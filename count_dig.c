#include <stdio.h>
/* counts digits, whitespace chars. and other chars. in input */

#define MAXWORDS 1024
int main() {
    int c, i, nwhite, nother, wc;
    nwhite = nother = wc = 0;
    int ndigs[10];

    for (i = 0; i < 10; ++i)
        ndigs[i] = 0;

    while ((c = getchar()) != EOF && wc <= MAXWORDS) {
        if (c >= '0' && c <= '9')
            ++ndigs[c-'0'];
        else if (c == ' ' || c == '\n' || c == '\t')
            ++nwhite;
        else
            ++nother;
    }
    printf("digits: ");
    for (i = 0; i < 10; ++i)
        printf("%3d ", ndigs[i]);

    printf(", whites: %d, others: %d\n", nwhite, nother);
    
    return 0;
}
