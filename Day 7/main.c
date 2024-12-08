#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define NUMBER_LIGNE 850


long long concat(long long a, long long b) {
    char strA[40], strB[40];
    sprintf(strA, "%lld", a);
    sprintf(strB, "%lld", b);

    char result[80];
    strcpy(result, strA);
    strcat(result, strB);

    return atoll(result);
}



int main() {
    FILE *fileInput, *fileOutput;
    fileInput = fopen("input.txt", "r");
    fileOutput = fopen("output.txt", "w");

    long long calibrationResult1 = 0, calibrationResult2 = 0;

    char buffer[256];
    for (int i = 0; i < NUMBER_LIGNE; i++) {
        long long result = 0;
        int number[50] = {0};
        int sign[50] = {0};
        int count = 0;

        fscanf(fileInput, "%lld:", &result);

        fgets(buffer, 256, fileInput);
        char *token = strtok(buffer, " ");
        while (token && count < 50) {
            number[count++] = atoi(token);
            token = strtok(NULL, " ");
        }




        for (int j = 0; j < pow(2, count - 1); j++) {
            int temp = j;
            for (int k = 0; k < count - 1; k++) {
                sign[k] = temp % 2;
                temp /= 2;
            }

            long long total = number[0];
            for (int k = 0; k < count - 1; k++) {
                if (sign[k] == 1) {
                    total *= number[k + 1];
                } else {
                    total += number[k + 1];
                }
            }

            if (total == result) {
                calibrationResult1 += total;
                break;
            }
        }




        for (int j = 0; j < pow(3, count - 1); j++) {
            int temp = j;
            for (int k = 0; k < count - 1; k++) {
                sign[k] = temp % 3;
                temp /= 3;
            }

            long long total = number[0];
            for (int k = 0; k < count - 1; k++) {
                if (sign[k] == 1) {
                    total *= number[k + 1];
                } else if (sign[k] == 2) {
                    total = concat(total, number[k + 1]);
                } else {
                    total += number[k + 1];
                }
            }

            if (total == result) {
                calibrationResult2 += total;
                break;
            }
        }
    }
    



    fprintf(fileOutput, "|-----------------------------------------------|\n");
    fprintf(fileOutput, "| Calibration Result: %-25lld |\n", calibrationResult1);
    fprintf(fileOutput, "| Calibration Result: %-25lld |\n", calibrationResult2);
    fprintf(fileOutput, "|-----------------------------------------------|\n");

    fclose(fileInput);
    fclose(fileOutput);

    return 0;
}
