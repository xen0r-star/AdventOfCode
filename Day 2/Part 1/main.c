#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define NUMBER_LINE 1000
#define NUMBER_LEVEL 10

int main() {
    // Open file ----------------------------------------------------------------------------------
    FILE *fdat, *fres;
    fdat = fopen("input.txt", "r");
    fres = fopen("output.res", "w");

    int numberReportsSafe[NUMBER_LINE];
    int report[NUMBER_LEVEL];


    // Algorithm ----------------------------------------------------------------------------------
    char line[100];
    int row = 0;
    while (fgets(line, sizeof(line), fdat)) {
        int col = 0;
        char *token = strtok(line, " ");
        while (token != NULL) {
            report[col] = atoi(token);
            col++;
            token = strtok(NULL, " ");
        }

        int securityLevel = 0;
        int graphReport[NUMBER_LEVEL];
        for (int i = 0; i < col - 1; i++) {
            if (abs(report[i] - report[i + 1]) > 3 || report[i] - report[i + 1] == 0) {
                securityLevel++;
            }

            if (report[i] - report[i + 1] > 0) {
                graphReport[i] = 1;
            } else if (report[i] - report[i + 1] < 0) {
                graphReport[i] = 2;
            }

            if (i > 0 && graphReport[i - 1] != graphReport[i]) {
                securityLevel++;
            }
        } 

        if (securityLevel == 0) {
            numberReportsSafe[row] = 1;
        } else {
            numberReportsSafe[row] = 0;
        }

        row++;
    }


    // Print result -------------------------------------------------------------------------------
    long total = 0;
    for (int i = 0; i < row; i++) {
        if (numberReportsSafe[i] == 1) {
            total++;
        }
    }

    fprintf(fres, "|-------------------------------|\n");
    fprintf(fres, "| Total Report Safe: %-5ld      |\n", total);
    fprintf(fres, "|-------------------------------|\n");

    for (int i = 0; i < row; i++) {
        fprintf(fres, "| Report %0.5d | %5s          |\n", i + 1, numberReportsSafe[i] == 1 ? "True " : "False");
    }

    fprintf(fres, "|-------------------------------|\n");
}