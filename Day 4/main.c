#include <stdio.h>
#include <string.h>

#define SIZE 140
#define WORD "XMAS"
#define WORD_LENGTH 4

int main() {
    FILE *fileInput, *fileOutput;
    fileInput = fopen("input.txt", "r");
    fileOutput = fopen("output.txt", "w");

    char grid[SIZE][SIZE];
    int count1 = 0;
    int count2 = 0;

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            fscanf(fileInput, " %c", &grid[i][j]);
        }
    }

    fclose(fileInput);




    for (int r = 0; r < SIZE; r++) {
        for (int c = 0; c < SIZE; c++) {
            // Horizontal right
            if (c + WORD_LENGTH <= SIZE) {
                int match = 1;
                for (int i = 0; i < WORD_LENGTH; i++) {
                    if (grid[r][c + i] != WORD[i]) {
                        match = 0;
                        break;
                    }
                }
                if (match) count1++;
            }

            // Horizontal left
            if (c - WORD_LENGTH + 1 >= 0) {
                int match = 1;
                for (int i = 0; i < WORD_LENGTH; i++) {
                    if (grid[r][c - i] != WORD[i]) {
                        match = 0;
                        break;
                    }
                }
                if (match) count1++;
            }

            // Vertically downwards
            if (r + WORD_LENGTH <= SIZE) {
                int match = 1;
                for (int i = 0; i < WORD_LENGTH; i++) {
                    if (grid[r + i][c] != WORD[i]) {
                        match = 0;
                        break;
                    }
                }
                if (match) count1++;
            }

            // Vertically upwards
            if (r - WORD_LENGTH + 1 >= 0) {
                int match = 1;
                for (int i = 0; i < WORD_LENGTH; i++) {
                    if (grid[r - i][c] != WORD[i]) {
                        match = 0;
                        break;
                    }
                }
                if (match) count1++;
            }

            // Diagonal ascending to the left
            if (r - WORD_LENGTH + 1 >= 0 && c - WORD_LENGTH + 1 >= 0) {
                int match = 1;
                for (int i = 0; i < WORD_LENGTH; i++) {
                    if (grid[r - i][c - i] != WORD[i]) {
                        match = 0;
                        break;
                    }
                }
                if (match) count1++;
            }

            // Downward diagonal to the left
            if (r + WORD_LENGTH <= SIZE && c - WORD_LENGTH + 1 >= 0) {
                int match = 1;
                for (int i = 0; i < WORD_LENGTH; i++) {
                    if (grid[r + i][c - i] != WORD[i]) {
                        match = 0;
                        break;
                    }
                }
                if (match) count1++;
            }

            // Diagonal ascending to the right
            if (r - WORD_LENGTH + 1 >= 0 && c + WORD_LENGTH <= SIZE) {
                int match = 1;
                for (int i = 0; i < WORD_LENGTH; i++) {
                    if (grid[r - i][c + i] != WORD[i]) {
                        match = 0;
                        break;
                    }
                }
                if (match) count1++;
            }

            // Downward diagonal to the right
            if (r + WORD_LENGTH <= SIZE && c + WORD_LENGTH <= SIZE) {
                int match = 1;
                for (int i = 0; i < WORD_LENGTH; i++) {
                    if (grid[r + i][c + i] != WORD[i]) {
                        match = 0;
                        break;
                    }
                }
                if (match) count1++;
            }

            // X Downward pattern
            if (r - 1 >= 0 && r + 1 < SIZE && c - 1 >= 0 && c + 1 < SIZE) {
                int match = 0;

                if (grid[r - 1][c - 1] == WORD[1] && grid[r][c] == WORD[2] && grid[r + 1][c + 1] == WORD[3]) {
                    match++;
                }
                if (grid[r - 1][c - 1] == WORD[3] && grid[r][c] == WORD[2] && grid[r + 1][c + 1] == WORD[1]) {
                    match++;
                }

                if (grid[r - 1][c + 1] == WORD[1] && grid[r][c] == WORD[2] && grid[r + 1][c - 1] == WORD[3]) {
                    match++;
                }
                if (grid[r - 1][c + 1] == WORD[3] && grid[r][c] == WORD[2] && grid[r + 1][c - 1] == WORD[1]) {
                    match++;
                }

                if (match == 2) count2++;
            }
        }
    }



    fprintf(fileOutput, "|------------------|\n");
    fprintf(fileOutput, "| Count 1: %-5d   |\n", count1);
    fprintf(fileOutput, "| Count 2: %-5d   |\n", count2);
    fprintf(fileOutput, "|------------------|\n");

    fclose(fileOutput);

    return 0;
}
