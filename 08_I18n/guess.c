#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <libintl.h>
#include <locale.h>
#define _(STRING) gettext(STRING)

int main(int argc, char** argv) {

    setlocale (LC_ALL, "");
    bindtextdomain ("domain", ".");
    textdomain ("domain");

    printf(_("Think about the number from 1 to 100.\n"));
    int min = 1, max = 100, mid = (min + max) / 2;

    for (mid = (min + max) / 2; min < max; mid = (min + max) / 2) {
        printf(_("Is the number grater than %d?(yes/no)\n"), mid);
        char ans[10];
        scanf("%10s", ans);
        if (!strcmp(ans, _("yes"))) {
            min = mid + 1;
        } else if (!strcmp(ans, _("no"))){
            max = mid;
        } else {
            printf(_("Enter yes or no.\n"));
        }
    }
    printf(_("The number is %d.\n"), min);

    return 0;
}