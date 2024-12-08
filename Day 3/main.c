#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define SIZE 3
const char *WORDS[SIZE] = {
    "mul(",
    "do()",
    "don't()"
};

int matchWord(FILE *file, const char *word) {
    int len = strlen(word);
    for (int i = 0; i < len; i++) {
        if (fgetc(file) != word[i]) {
            fseek(file, -i-1, SEEK_CUR);
            return 0;
        }
    }
    return 1;
}




int main() {
    FILE *fileInput, *fileOutput;
    fileInput = fopen("input.txt", "r");
    fileOutput = fopen("output.txt", "w");

    long result1 = 0, result2 = 0;

    char c;
    int index = 0;
    int status = 1;
    while ((c = fgetc(fileInput)) != EOF) {
        if (c == WORDS[0][0] && matchWord(fileInput, WORDS[0] + 1)) {
            char num1[4] = {0}, num2[4] = {0};
            int i = 0;

            while (isdigit(c = fgetc(fileInput)) && i < 3) {
                num1[i++] = c;
            }
            num1[i] = '\0';

            if (c == ',') {
                i = 0;
                while (isdigit(c = fgetc(fileInput)) && i < 3) {
                    num2[i++] = c;
                }
                num2[i] = '\0';
            }

            if (c == ')' || (c = fgetc(fileInput)) == ')') {
                result1 += atoi(num1) * atoi(num2);
                if (status) {
                    result2 += atoi(num1) * atoi(num2);
                }
            } else {
                fseek(fileInput, -strlen(num2) - 1, SEEK_CUR);
            }
        }

        if (c == WORDS[1][0] && matchWord(fileInput, WORDS[1] + 1)) {
            status = 1;
        }

        if (c == WORDS[2][0] && matchWord(fileInput, WORDS[2] + 1)) {
            status = 0;
        }
    }



    fprintf(fileOutput, "|------------------------|\n");
    fprintf(fileOutput, "| Result 1: %-10ld   |\n", result1);
    fprintf(fileOutput, "| Result 2: %-10ld   |\n", result2);
    fprintf(fileOutput, "|------------------------|\n");


    fclose(fileInput);
    fclose(fileOutput);

    return 0;
}