#include <stdio.h>
/* prints its output one world per line */

int main() {
    int c, p;

    while ((c = getchar()) != EOF) {

        /* This complex nested if so that newlines(empty lines), tabs or spaces following the same are not printed in separate lines but rather ignored. */
    if (c == ' ' || c == '\t' || c == '\n') {
        if (!(p == ' ' || p == '\t' || p == '\n'))
            putchar('\n');
        /* else, don't print anything */
    }
    else
        putchar(c);

    p = c;
    }
    return 0;
}
