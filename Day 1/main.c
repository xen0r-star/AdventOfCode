#include <stdio.h>
#include <math.h>

#define NUMBER_LINE 1000


void sortArray(long arr[], int size) {
    long tmp;
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] > arr[j]) {
                tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
    }
}

int numberRepeatElement(long number, long arr[], int size) {
    int tmp = 0;
    for (int i = 0; i < size; i++) {
        if (number == arr[i]) {
            tmp++;
        }
    }

    return tmp;
}



int main() {
    FILE *fdat, *fres;
    fdat = fopen("input.txt", "r");
    fres = fopen("output.txt", "w");

    long totalDistance1 = 0;
    long totalDistance2 = 0;
    long numberLeft[NUMBER_LINE], numberRight[NUMBER_LINE];

    for (int i = 0; i < 1000; i++) {
        fscanf(fdat, "%5d %5d", &numberLeft[i], &numberRight[i]);
    }




    sortArray(numberLeft, NUMBER_LINE);
    sortArray(numberRight, NUMBER_LINE);


    for (int i = 0; i < NUMBER_LINE; i++) {
        totalDistance1 += labs(numberLeft[i] - numberRight[i]);
    }
    
    fprintf(fres, "|-----------------------------|\n");
    fprintf(fres, "| Total Distance 1: %-9ld |\n", totalDistance1);



    
    for (int i = 0; i < NUMBER_LINE; i++) {
        totalDistance2 += numberLeft[i] * numberRepeatElement(numberLeft[i], numberRight, NUMBER_LINE);
    }

    fprintf(fres, "| Total Distance 2: %-9ld |\n", totalDistance2);
    fprintf(fres, "|-----------------------------|\n");
}