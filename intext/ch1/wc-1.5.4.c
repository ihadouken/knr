#include <stdio.h>
/* bare-bones implementation of coreutil wc */

#define IN 1
#define OUT 0

int main() {
    double c, nl, nw, nc;
    int state;

    nl = nw = nc = 0;
    state = OUT;
    while ((c = getchar()) != EOF) {
        ++nc;
        if (c == '\n')
            ++nl;
        if (c == '\n' || c == '\t' || c == ' ')
            state = OUT;
        else if (state == OUT) {
            state = IN;
            ++nw;
        }
    }
    //printf("lines: %.0f\nwords: %.0f\nchars: %.0f\n", nl, nw, nc);
    printf("%7.0f %7.0f %7.0f\n", nl, nw, nc);
    return 0;
}
