#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define NUMBER_LINE 1000
#define NUMBER_LEVEL 10

int main() {
    FILE *fdat, *fres;
    fdat = fopen("input.txt", "r");
    fres = fopen("output.txt", "w");

    int numberReportsSafe1 = 0;
    int numberReportsSafe2 = 0;
    int report[NUMBER_LEVEL];




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
            numberReportsSafe1++;
        }




        int reportOneDelete[NUMBER_LEVEL];

        for (int h = 0; h < col; h++) {
            int counter = 0;
            securityLevel = 0;
            for (int i = 0; i < col; i++) {
                reportOneDelete[counter] = report[i];
                if (i != h) counter++;
            }


            for (int i = 0; i < col - 1 - 1; i++) {
                if (abs(reportOneDelete[i] - reportOneDelete[i + 1]) > 3 || reportOneDelete[i] - reportOneDelete[i + 1] == 0) {
                    securityLevel++;
                }

                if (reportOneDelete[i] - reportOneDelete[i + 1] > 0) {
                    graphReport[i] = 1;
                } else if (reportOneDelete[i] - reportOneDelete[i + 1] < 0) {
                    graphReport[i] = 2;
                }

                if (i > 0 && graphReport[i - 1] != graphReport[i]) {
                    securityLevel++;
                }
            }

            if (securityLevel == 0) {
                numberReportsSafe2++;
                break;
            }
        }

        row++;
    }

    fprintf(fres, "|------------------------------|\n");
    fprintf(fres, "| Total Report Safe 1: %-5ld   |\n", numberReportsSafe1);




    // char line[100];
    // int row = 0;
    // while (fgets(line, sizeof(line), fdat)) {
    //     int col = 0;
    //     char *token = strtok(line, " ");
    //     while (token != NULL) {
    //         report[col] = atoi(token);
    //         col++;
    //         token = strtok(NULL, " ");
    //     }

        

    //     row++;
    // }

    fprintf(fres, "| Total Report Safe 2: %-5ld   |\n", numberReportsSafe2);
    fprintf(fres, "|------------------------------|\n");
}