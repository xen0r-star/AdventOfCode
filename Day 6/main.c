#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE_MAP 10

typedef struct {
    int x;
    int y;
    int direction;
} Guard;


int moveGuard(char map[SIZE_MAP][SIZE_MAP], Guard *guard) {
    switch (guard->direction) {
        case 0:
            if (map[guard->x - 1][guard->y] != '#') {
                guard->x--;
            } else {
                guard->direction = 1;
            }
            break;
        case 1:  
            if (map[guard->x][guard->y + 1] != '#') {
                guard->y++;
            } else {
                guard->direction = 2;
            }
            break;
        case 2:  
            if (map[guard->x + 1][guard->y] != '#') {
                guard->x++;
            } else {
                guard->direction = 3;
            }
            break;
        case 3:  
            if (map[guard->x][guard->y - 1] != '#') {
                guard->y--;
            } else {
                guard->direction = 0;
            }
            break;
    }

    return 0;
}




int main() {
    FILE *fileInput, *fileOutput;
    fileInput = fopen("input.txt", "r");
    fileOutput = fopen("output.txt", "w");

    int totalMove = 0, totalObstacle = 0;

    char map1[SIZE_MAP][SIZE_MAP];
    char map2[SIZE_MAP][SIZE_MAP];
    Guard spawn = {0, 0, 0};
    for (int i = 0; i < SIZE_MAP; i++) {
        for (int j = 0; j < SIZE_MAP; j++) {
            fscanf(fileInput, "%1c", &map1[i][j]);
            switch (map1[i][j]) {
                case '^':
                    spawn.direction = 0;
                    break;
                case '>':
                    spawn.direction = 1;
                    break;
                case 'v':
                    spawn.direction = 2;
                    break;
                case '<':
                    spawn.direction = 3;
                    break;
            }

            if (map1[i][j] == '^' || map1[i][j] == 'v' || map1[i][j] == '<' || map1[i][j] == '>') {
                spawn.x = i;
                spawn.y = j;
                map1[i][j] = '.';
            }
            map2[i][j] = map1[i][j];
        }
        fscanf(fileInput, "\n");
    }

    fclose(fileInput);

    Guard guard1 = {spawn.x, spawn.y, spawn.direction};
    Guard guard2 = {spawn.x, spawn.y, spawn.direction};




    while (guard1.x >= 0 && guard1.x < SIZE_MAP && guard1.y >= 0 && guard1.y < SIZE_MAP) {
        moveGuard(map1, &guard1);

        if (map1[guard1.x][guard1.y] == '.') {
            map1[guard1.x][guard1.y] = 'X';
            totalMove++;
        }
    }



    int step;
    char tmp;
    for (int i = 0; i < SIZE_MAP; i++) { // Y
        for (int j = 0; j < SIZE_MAP; j++) { // X
            guard2.x = spawn.x;
            guard2.y = spawn.y;
            guard2.direction = spawn.direction;

            tmp = map2[i][j];
            map2[i][j] = '#';
            step = 0;

            while (guard2.x >= 0 && guard2.x < SIZE_MAP && guard2.y >= 0 && guard2.y < SIZE_MAP) {
                moveGuard(map2, &guard2);
                step++;

                if (step > SIZE_MAP * SIZE_MAP * 4) {
                    printf("Loop\n");
                    totalObstacle++;
                    break;
                }
            }

            map2[i][j] = tmp;
        }
    }




    fprintf(fileOutput, "|------------------------|\n");
    fprintf(fileOutput, "| Total Move: %-5d      |\n", totalMove);
    fprintf(fileOutput, "| Total Obstacle: %-5d  |\n", totalObstacle);
    fprintf(fileOutput, "|------------------------|\n");

    
    fclose(fileOutput);

    return 0;
}
