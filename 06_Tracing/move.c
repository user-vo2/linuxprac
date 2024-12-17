#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>


#define BUFSIZE 4096

void closefiles (int fdin, int fdout, char** argv, int err) {
    if (close(fdout)) {
        perror("Failed to close file");
        if (close(fdin)) {
            perror("Failed to close file");
            if (remove(argv[2]) == -1){
                perror("Failed to remove file");
                exit(4);
            }
            exit(3);
        }
        if (remove(argv[2]) == -1){
            perror("Failed to remove file");
            exit(4);
        }
        exit(3);
    }
    if (err) {
        if (remove(argv[2]) == -1){
            perror("Failed to remove file");
            exit(4);
        }
        if (close(fdin)) {
            perror("Failed to close file");
            if (remove(argv[2]) == -1){
                perror("Failed to remove file");
                exit(4);
            }
            exit(3);
        }
        exit(err);
    } else {
        if (close(fdin)) {
            perror("Failed to close file");
            if (remove(argv[2]) == -1){
                perror("Failed to remove file");
                exit(4);
            }
            exit(3);
        }
        if (remove(argv[1]) == -1){
            perror("Failed to remove file");
            exit(4);
        }
    }
}

int main(int argc, char** argv) {
    char buffer[BUFSIZE];
    int size_r, size_w;

    if (argc != 3) {
        fprintf(stderr, "Wrond number of arguments\n");
        return 1;
    }

    int fdin = open(argv[1], O_RDONLY);
    if (fdin == -1) {
        perror("Failed to open infile");
        exit(2);
    }

    int fdout = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC);
    if (fdout == -1) {
        perror("Failed to open outfile");
        if (close(fdin)) {
            perror("Failed to close file");
            exit(3);
        }
        exit(2);
    }
    int err = 0;
    while ((size_r = read(fdin, buffer, sizeof(buffer))) != 0) {
        if (size_r == -1) {
            perror("Failed to read from file");
            err = 5;
            break;
        }
        size_w = write(fdout, buffer, size_r);
        if (size_w == -1) {
            perror("Failed to write to file");
            err = 6;
            break;
        }
    }
    closefiles(fdin, fdout, argv, err);

    return 0;
}