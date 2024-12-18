#include <stdio.h>
#include <stdlib.h>
#include <time.h>

enum DIRECTIONS {
    L_DIR,
    U_DIR,
    R_DIR,
    D_DIR,
} DIRECTIONS;

int create_path(int row, int col, int unmarked, char** maze, int size) {
    maze[row][col] = '.';
    unmarked--;
    if (!unmarked) {
        return unmarked;
    }
    while (unmarked) {
        int closed = 0;
        int dirs[4];
        if (col - 2 > 0 && maze[row][col - 2] == 0) {
            dirs[closed++] = L_DIR;
        }
        if (row - 2 > 0 && maze[row - 2][col] == 0) {
            dirs[closed++] = U_DIR;
        }
        if (col + 2 < size * 2 && maze[row][col + 2] == 0) {
            dirs[closed++] = R_DIR;
        }
        if (row + 2 < size * 2 && maze[row + 2][col] == 0) {
            dirs[closed++] = D_DIR;
        }
        if (!closed) {
            return unmarked;
        } else {
            int new_dir = dirs[rand() % closed];
            switch (new_dir) {
            case L_DIR:
                maze[row][col - 1] = '.';
                unmarked = create_path(row, col - 2, unmarked, maze, size);
                break;
            case U_DIR:
                maze[row - 1][col] = '.';
                unmarked = create_path(row - 2, col, unmarked, maze, size);
                break;
            case R_DIR:
                maze[row][col + 1] = '.';
                unmarked = create_path(row, col + 2, unmarked, maze, size);
                break;
            case D_DIR:
                maze[row + 1][col] = '.';
                unmarked = create_path(row + 2, col, unmarked, maze, size);
                break;
            }
        }
    }
    return unmarked;
}

int main(int argc, char** argv) {

    srand(time(NULL));

    int size = 6;

    char** maze = malloc((2 * size + 1) * sizeof(char*));
    for (int i = 0; i < 2 * size + 1; i++)
        maze[i] = malloc((2 * size + 2) * sizeof(char));

    for (int i = 0; i < 2*size+1; i++) {
        for (int j = 0; j < 2 * size + 1; j++) {
            if (i % 2 == 1 && j % 2 == 1) {
                maze[i][j] = 0;
            } else {
                maze[i][j] = '#';
            }
        }
    }

    int row = (1 + rand() % size) * 2 - 1;
    int col = (1 + rand() % size) * 2 - 1;
    
    create_path(row, col, size * size, maze, size);

    for (int i = 0; i < 2 * size + 1; i++)
        printf("%s\n", maze[i]);

    for (int i = 0; i < 2 * size + 1; i++)
        free(maze[i]);
    free(maze);

    return 0;
}