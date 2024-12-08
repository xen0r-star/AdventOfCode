#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// #define NUMBER_RULES 1176
#define NUMBER_RULES 21
#define MAX_PAGES 23

int main() {
    FILE *fileInput, *fileOutput;
    fileInput = fopen("input.txt", "r");
    fileOutput = fopen("output.txt", "w");

    int totalMiddlePages1 = 0, totalMiddlePages2 = 0;

    int rules[NUMBER_RULES][2];
    for (int i = 0; i < NUMBER_RULES; i++) {
        fscanf(fileInput, "%d|%d", &rules[i][0], &rules[i][1]);
    }

    fscanf(fileInput, "\n");

    char buffer[256];
    while (fgets(buffer, sizeof(buffer), fileInput)) {
        int pages[MAX_PAGES];
        int pageCount = 0;

        char *token = strtok(buffer, ",");
        while (token && pageCount < MAX_PAGES - 1) {
            pages[pageCount++] = atoi(token);
            token = strtok(NULL, ",");
        }

        int error = 0;
        for (int i = 0; i < NUMBER_RULES; i++) {
            int x = rules[i][0];
            int y = rules[i][1];

            int posX = -1, posY = -1;
            for (int j = 0; j < pageCount; j++) {
                if (pages[j] == x) posX = j;
                if (pages[j] == y) posY = j;
            }

            if (posX != -1 && posY != -1 && posX > posY) {
                error++;
                break;
            }
        }

        if (error == 0) {
            int indexMiddlePage = (int) (((float) pageCount / 2) - 0.5);
            totalMiddlePages1 += pages[indexMiddlePage];
        }
    }
    



    fprintf(fileOutput, "|-----------------------|\n");
    fprintf(fileOutput, "| Total Pages 1: %-5d  |\n", totalMiddlePages1);
    fprintf(fileOutput, "| Total Pages 2: %-5d  |\n", totalMiddlePages2);
    fprintf(fileOutput, "|-----------------------|\n");

    fclose(fileInput);
    fclose(fileOutput);

    return 0;
}
