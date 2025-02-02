#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct node;
typedef struct node {
    long long value;
    long long occurence;
    struct node *next;
} Node;

int digit(long long number) {
    if (number <= 0) return 1;

    int count = 0;
    while (number > 0) {
        number /= 10;
        count++;
    }
    return count;
}

Node *findOrCreateNode(Node **head, long long value, long long occurence) {
    Node *current = *head;
    Node *prev = NULL;
    while (current) {
        if (current->value == value) {
            current->occurence += occurence;
            return current;
        }
        prev = current;
        current = current->next;
    }
    
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->value = value;
    newNode->occurence = occurence;
    newNode->next = NULL;
    
    if (prev)
        prev->next = newNode;
    else
        *head = newNode;
    
    return newNode;
}

Node *readData() {
    FILE *file = fopen("input.txt", "r");
    if (!file) return NULL;
    
    Node *head = NULL;
    long long value;
    while (fscanf(file, "%lld", &value) == 1) {
        findOrCreateNode(&head, value, 1);
    }
    
    fclose(file);
    return head;
}

Node *blinking(Node *head) {
    Node *newHead = NULL;
    Node *current = head;
    while (current) {
        if (current->value == 0) {
            findOrCreateNode(&newHead, 1, current->occurence);
        } else {
            int digitCount = digit(current->value);
            if (digitCount % 2 == 0) {
                int divisor = 1;
                for (int i = 0; i < digitCount / 2; i++) {
                    divisor *= 10;
                }
                
                long long firstHalf = current->value / divisor;
                long long secondHalf = current->value % divisor;
                
                findOrCreateNode(&newHead, firstHalf, current->occurence);
                findOrCreateNode(&newHead, secondHalf, current->occurence);
            } else {
                findOrCreateNode(&newHead, current->value * 2024, current->occurence);
            }
        }
        Node *temp = current;
        current = current->next;
        free(temp);
    }
    return newHead;
}

void loopBlinking(Node **head, int iteration) {
    for (int i = 0; i < iteration; i++) {
        *head = blinking(*head);
    }
}

long long countRock(Node *head) {
    long long count = 0;
    Node *current = head;
    while (current) {
        count += current->occurence;
        current = current->next;
    }
    return count;
}

void freeRock(Node *head) {
    Node *current = head;
    while (current) {
        Node *next = current->next;
        free(current);
        current = next;
    }
}

int main() {
    Node *head = readData();
    FILE *file = fopen("output.txt", "w");

    loopBlinking(&head, 25);
    long long count = countRock(head);

    fprintf(file, "|--------------------------------------------|\n");
    fprintf(file, "| Number of rocks (25): %-20lld |\n", count);


    loopBlinking(&head, 50); // 25 + 50 = 75
    count = countRock(head);

    fprintf(file, "| Number of rocks (75): %-20lld |\n", count);
    fprintf(file, "|--------------------------------------------|\n");


    freeRock(head);
    fclose(file);
    return 0;
}