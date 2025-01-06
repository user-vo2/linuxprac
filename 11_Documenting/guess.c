/** @mainpage
*   # Program that guesses user's number.
*/
/** @page Program that guesses user's number.
*   Only yes or no replies are accepted. Can display numbers in roman notation.
*   
*   Arguments (not necessary):
*   -r sets all numbers to roman system
*   --help, -h shows help message
*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <libintl.h>
#include <locale.h>
#define _(STRING) gettext(STRING)

// Array of numbers from 1 to 100 in roman notation
char *roman[] = {
    "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX", "X",
    "XI", "XII", "XIII", "XIV", "XV", "XVI", "XVII","XVIII", "XIX", "XX",
    "XXI", "XXII", "XXIII", "XXIV", "XXV", "XXVI", "XXVII", "XXVIII", "XXIX", "XXX",
    "XXXI", "XXXII", "XXXIII", "XXXIV", "XXXV", "XXXVI", "XXXVII", "XXXVIII", "XXXIX", "XL",
    "XLI", "XLII", "XLIII", "XLIV", "XLV", "XLVI", "XLVII", "XLVIII", "XLIX", "L",
    "LI", "LII", "LIII", "LIV", "LV", "LVI", "LVII", "LVIII", "LIX", "LX",
    "LXI", "LXII", "LXIII", "LXIV", "LXV", "LXVI", "LXVII", "LXVIII", "LXIX", "LXX",
    "LXXI", "LXXII", "LXXIII", "LXXIV", "LXXV", "LXXVI", "LXXVII", "LXXVIII", "LXXIX", "LXXX",
    "LXXXI", "LXXXII", "LXXXIII", "LXXXIV", "LXXXV", "LXXXVI", "LXXXVII", "LXXXVIII", "LXXXIX", "XC",
    "XCI", "XCII", "XCIII", "XCIV", "XCV", "XCVI", "XCVII", "XCVIII", "XCIX", "C",};

/** Convert integer in arabic notation into roman notation.
 *
 * @param num integer in arabic notation to convert
 * @return string representation of num in roman notation
 */
char *arabic2roman (int num) {
    return roman[num - 1];
}

/** Convert string in roman notation into arabic notation.
 *
 * @param num string in roman notation to convert
 * @return integer representation of num in arabic notation
 */
int roman2arabic (char *num) {
    for(int i = 0; i < 100; i++) {
        if (!strcmp(num, roman[i])) {
            return i + 1;
        }
    }
}

int main(int argc, char** argv) {

    int roman_notation = 0;
    for(int i = 1; i < argc; i++) {
        if (!strcmp(argv[i], "-r")) {
            roman_notation = 1;
            break;
        }
    }

    setlocale (LC_ALL, "");
    bindtextdomain ("domain", ".");
    textdomain ("domain");

    printf(_("Think about the number from 1 to 100.\n"));
    int min = 1, max = 100, mid = (min + max) / 2;

    for (mid = (min + max) / 2; min < max; mid = (min + max) / 2) {
        if (roman_notation) {
            printf(_("Is the number grater than %s?(yes/no)\n"), arabic2roman(mid));
        } else {
            printf(_("Is the number grater than %d?(yes/no)\n"), mid);
        }
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
    if (roman_notation) {
        printf(_("The number is %s.\n"), arabic2roman(min));
    } else {
        printf(_("The number is %d.\n"), min);
    }
    return 0;
}