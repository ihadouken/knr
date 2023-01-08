#include <stdio.h>
// bare-bones implementation of cat using getchar and putchar.

int main() {
    int c;
    while ((c = getchar()) != EOF) {
        if (c == '\t') {
            //printf("\\t");
            putchar('\\');
            putchar('t');
        }
        else if (c == '\b') {
            putchar('\\');
            putchar('b');
        }
        else if (c == '\\') {
            putchar('\\');
            putchar('\\');
        }
        else
            putchar(c);
    }
    return 0;
}
