#include <curses.h>
#include <locale.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>

#define DX 7
#define DY 3

int main(int argc, char *argv[]) {
        
        WINDOW *frame, *win;
        int c = 0;
        
        if (argc != 2) {
                printf("Wrong number of arguments.\n");
                exit(1);
        }

        const char* fname = argv[1];

        struct stat st;
        if (stat(fname, &st) != 0) {
                perror("stat");
                exit(1);
        }

        setlocale(LC_ALL, "ru_RU.UTF-8");
        initscr();
        noecho();
        cbreak();
        printw("Файл: %s; Размер: %ld.", fname, st.st_size);
        refresh();

        frame = newwin(LINES - 2*DY, COLS - 2*DX, DY, DX);
        box(frame, 0, 0);
        wrefresh(frame);

        win = newwin(LINES - 2*DY - 2, COLS - 2*DX-2, DY+1, DX+1);
        keypad(win, TRUE);
        scrollok (win, TRUE);
        FILE* f = fopen(fname, "r");
        char buf[(COLS - 2*DX-2) * (LINES - 2*DY - 2)];
        for (int i = 0; i < LINES - 2*DY - 2; i++) {
                if (!fgets(buf, sizeof(buf), f)) {
                        break;
                }
                wprintw(win, "%s", buf);
        }
        while((c = wgetch(win)) != 27) {
                if (c == 32) {
                        for (int i = 0; i < LINES - 2*DY - 2; i++) {
                                if (!fgets(buf, sizeof(buf), f)) {
                                        break;
                                }
                                wprintw(win, "%s", buf);
                        }
                }
        }
        delwin(win);
        delwin(frame);
        endwin();
        return 0;
}

