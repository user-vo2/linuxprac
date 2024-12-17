#include <dlfcn.h>
#include <stdio.h>
#include <string.h>

typedef int (*removefile_t)(const char *filename);

int remove(const char *filename) {
    printf("%s", filename);

    removefile_t removefile = (removefile_t) dlsym(RTLD_NEXT, "remove");
    if (strstr(filename, "PROTECT") == NULL) {
        return removefile(filename);
    } else {
        return -1;
    }
}