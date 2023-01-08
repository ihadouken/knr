#include <stdio.h>
/* c program to count words, lines, tabs, chars., blanks and what not in a given input. */

#define IN 1
#define OUT 0

int main() {
    int c, state;
    state = OUT;

    double nc, nb, nt, nw, nl;
    nc = nb = nt = nw = nl = 0;

    while ((c = getchar()) != EOF) {
        ++nc;
        
        if (c == '\t')
            ++nt;
        else if (c == ' ')
            ++nb;
        else if (c == '\n')
            ++nl;

        if (c == '\n' || c == ' ' || c == '\t')
            state = OUT;
        else if (state == OUT) {
            state = IN;
            ++nw;
        }
    }
    printf("Chars: %.0f\nSpaces: %.0f\nTabs: %.0f\nWords: %.0f\nLines: %.0f\n", nc, nb, nt, nw, nl);
    return 0;
}
