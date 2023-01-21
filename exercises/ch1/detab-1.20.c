/* Replace tabs with spaces upto the next tabstop */

#include <stdio.h>
#define TABSIZE 8

int next_tab_stop(int pos, int tablen);
int main(void) {
    int ch, col, stop;
    col = 1;

    while ((ch=getchar()) != EOF) {
        if (ch == '\t') {
            stop = next_tab_stop(col, TABSIZE);
            while (col <= stop) {
                putchar(' ');
                ++col;
            }
        }

        else if (ch == '\n') {
            putchar(ch);
            col = 1;
        }

        else {
            putchar(ch);
            ++col;
        }

    }
    return 0;
}

int next_tab_stop(int pos, int tablen) {
    int prev, next;
    prev = (pos / tablen) * tablen;
    next = prev + tablen;
    return next;
}
