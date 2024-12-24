#include <rhash.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <errno.h>

#ifdef READLINE
#include <readline/readline.h>
#include <readline/history.h>
#endif

int main() {
    rhash_library_init();

    unsigned char digest[128];
    char output[512];

    char* line = NULL;

    int res = 0;

    int rhash_algo;
    int rhash_flag;

#ifdef READLINE
    while ((line = readline(NULL))) {
#else
    size_t len = 0;
    while (getline(&line, &len, stdin) != -1) {
#endif
        char* algo = strtok(line, " ");
        char* msg = strtok(NULL, " ");

        if (algo == NULL || msg == NULL)
            continue;

        if (islower(algo[0]))
            rhash_flag = RHPR_BASE64;
        else
            rhash_flag = RHPR_HEX;

        for (size_t i = 0; i < strlen(algo); i++)
            algo[i] = toupper(algo[i]);

        if (!strcmp(algo, "SHA1"))
            rhash_algo = RHASH_SHA1;
        else if (!strcmp(algo, "TTH"))
            rhash_algo = RHASH_TTH;
        else if (!strcmp(algo, "MD4"))
            rhash_algo = RHASH_MD4;
        else if (!strcmp(algo, "MD5"))
            rhash_algo = RHASH_MD5;
        else {
            printf("Wrong hash algo: <%s>!\n", algo);
            continue;
        }

        if (msg[strlen(msg)-1] == '\n')
            msg[strlen(msg)-1] = 0;

        if (msg[0] == '"') {
            res = rhash_msg(rhash_algo, msg+1, strlen(msg)-1, digest);
        } else {
            res = rhash_file(rhash_algo, msg, digest);
        }

        if (res < 0) {
            fprintf(stderr, "LibRHash error: %s: %s\n", msg, strerror(errno));
            continue;
        }

        rhash_print_bytes(output, digest, rhash_get_digest_size(rhash_algo), rhash_flag);

        printf("%s\n", output);
    }

    if (line != NULL)
        free(line);

    return 0;
}