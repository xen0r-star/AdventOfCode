#include <stdio.h>
#include <math.h>

#define NUMBER_LINE 1000


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
    
    for (int i = 0; i < NUMBER_LINE; i++) {
        totalDistance += numberLeft[i] * numberRepeatElement(numberLeft[i], numberRight, NUMBER_LINE);
    }


    // Print result -------------------------------------------------------------------------------
    fprintf(fres, "|-------------------------------|\n");
    fprintf(fres, "| Total Distance: %-13ld |\n", totalDistance);
    fprintf(fres, "|-------------------------------|\n");

    for (int i = 0; i < NUMBER_LINE; i++) {
        fprintf(fres, "| %5ld  | %5ld * %-2d = %-7ld |\n", 
            numberLeft[i], 
            numberLeft[i], 
            numberRepeatElement(numberLeft[i], numberRight, NUMBER_LINE),
            numberLeft[i] * numberRepeatElement(numberLeft[i], numberRight, NUMBER_LINE)
        );
    }

    fprintf(fres, "|-------------------------------|");
}