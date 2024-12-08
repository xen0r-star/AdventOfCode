#include <stdio.h>
#include <string.h>

int main() {
    FILE *fileInput, *fileOutput;
    fileInput = fopen("input.txt", "r");
    fileOutput = fopen("output.txt", "w");
    
    long result1 = 0;
    long result2 = 0;




    char buffer[9];
    int index = 0;
    
    while (fread(buffer, sizeof(char), 1, fileInput) == 1) {
        index++;

        if (buffer[0] == 'm') {
            if (fread(buffer + 1, sizeof(char), 3, fileInput) == 3) {
                buffer[4] = '\0';

                if (strcmp(buffer, "mul(") == 0) {
                    int num1, num2;
                    if (fread(buffer + 1, sizeof(char), 8, fileInput) == 8) {
                        buffer[8] = '\0';
                    }
                    
                    // fscanf(fileInput, "%3d,%3d", &num1, &num2);

                    printf("mul(%s\n", buffer);
                    // if (buffer[0] == ')') {
                        // result1 += num1 * num2;
                    // }
                }
            }
        }
    }




    fprintf(fileOutput, "|------------------------|\n");
    fprintf(fileOutput, "| Result 1: %-10ld   |\n", result1);
    fprintf(fileOutput, "| Result 1: %-10ld   |\n", result2);
    fprintf(fileOutput, "|------------------------|\n");




    fclose(fileInput);
    fclose(fileOutput);
}