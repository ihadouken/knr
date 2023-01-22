/* Encode groups of spaces into a possible tab. */

#include <stdio.h>
#define TABW 4
#define SPACE ' '
#define TAB '\t'

int main() {
    int ch, spaces, pos;
    spaces = 0;
    /* Initialize to column one. */
    pos = 1;

    while ((ch=getchar()) != EOF) {
        if (ch == SPACE) {
            ++spaces;
            /* If tabstop is reached. */
            if (pos % TABW == 0) {
                /* Multiple spaces before tabstop. */
                if (spaces > 1)
                    putchar(TAB);
                else
                    putchar(SPACE);
                spaces = 0;
            }
            /* Increment column number. */
            ++pos;
        }
        else {
            if (spaces) {
                /* Spit out all spaces when non-space char. before tabstop. */
                for (int i = 0; i < spaces; ++i)
                    putchar(SPACE);
                spaces = 0;
            }
            putchar(ch);

            /* Increment column number. */
            ++pos;

            /* Reset column number for a new line. */
            if (ch == '\n')
                pos = 1;
        }
    }
    return 0;
}

