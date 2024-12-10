#include <stdio.h>
#include <stdlib.h>

int cmp(int i, int stop, int cond) {
    if (!cond)
        return i < stop;
    else
        return i > stop;
}

int main(int argc, char *argv[]) {
    int start = 0, step = 1, stop, cond = 0;
    if (argc == 1) {
        printf(
            "Программа-генератор арифметической прогрессии, принимающая от одного до трёх параметров по аналогии с питоновским range()\n" \
            "Без параметров — выводит это сообщение.\n"
            "С одним параметром N — выводит в столбик последовательность [0, 1, … N-1].\n"
            "С двумя — M, N — последовательность [M, M+1, … N-1].\n"
            "С тремя — M, N, S — последовательность [M, M+S, M+2S, … N-1].\n"
            );
        return 0;
    }
    if (argc == 2) {
        stop = strtol(argv[1], NULL, 10);
    } else if (argc == 3) {
        start = strtol(argv[1], NULL, 10);
        stop = strtol(argv[2], NULL, 10);
    } else if (argc == 4) {
        start = strtol(argv[1], NULL, 10);
        stop = strtol(argv[2], NULL, 10);
        step = strtol(argv[3], NULL, 10);
    }
    int res = start;
    if (start > stop)
        cond = 1;
    for(int i = start; cmp(i, stop, cond); i += step)
            printf("%d\n", i);
    
    return 0;
}