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


int main() {
    // Open file ----------------------------------------------------------------------------------
    FILE *fdat, *fres;
    fdat = fopen("input.txt", "r");
    fres = fopen("output.res", "w");

    long totalDistance = 0;
    long numberLeft[NUMBER_LINE], numberRight[NUMBER_LINE];


    // Algorithm ----------------------------------------------------------------------------------
    for (int i = 0; i < 1000; i++) {
        fscanf(fdat, "%5d %5d", &numberLeft[i], &numberRight[i]);
    }

    sortArray(numberLeft, NUMBER_LINE);
    sortArray(numberRight, NUMBER_LINE);


    // Print result -------------------------------------------------------------------------------
    for (int i = 0; i < NUMBER_LINE; i++) {
        totalDistance += labs(numberLeft[i] - numberRight[i]);
    }
    

    fprintf(fres, "|--------------------------|\n");
    fprintf(fres, "| Total Distance: %-8ld |\n", totalDistance);
    fprintf(fres, "|--------------------------|\n");

    for (int i = 0; i < NUMBER_LINE; i++) {
        fprintf(fres, "| %5ld  | %5ld  | %-5ld  |\n", numberLeft[i], numberRight[i], labs(numberLeft[i] - numberRight[i]));
    }

    fprintf(fres, "|--------------------------|");
}