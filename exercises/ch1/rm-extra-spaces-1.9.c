#include <stdio.h>
/* This program replaces one or more blanks with a single blank in its input */

int main() {
    int c;
    char p;

    while ((c = getchar()) != EOF) {
        //if (p != ' ' || c != ' ') {
        //    putchar(c);
        //}

        /* equivalent to the commented 'if' block (de-morgan's theorem) */
        if (!(p == ' ' && c == ' '))
            putchar(c);
        p = c;
    }   
    return 0;
}

