#include <stdio.h>
/* vertical histogram showing number of characters in a word */

#define IN 1
#define OUT 0
#define HISTSYM 'X'
#define MAXLEN 21
#define MAXWORD 100

int main() {
    int c, i, j, state, wc, wlen;
    int freq[MAXLEN];

    for (i = 0; i < MAXLEN; ++i)
        freq[i] = 0;

    state = OUT;
    wc = wlen = 0;
    while((c = getchar()) != EOF) {
        if (c != '\n' && c!= '\t' && c != ' ') {
            if (state == OUT) {
                ++wc;
                state = IN;
            }
            ++wlen;
        }
        else if (0 < wlen && wlen < MAXLEN) {
            ++freq[wlen];
            wlen = 0;
            state = OUT;
        }
        else if (wlen >= MAXLEN) {
            ++freq[0];
            wlen = 0;
            state = OUT;
        }
    }

    printf("total words: %d\n", wc);

    //int sum = 0;
    //for (i = 1; i < MAXLEN; ++i) {
    //    printf("%d words with %3d chars\n", freq[i], i);
    //    sum += freq[i];
    //}
    //printf("%d words with >20 chars\n", freq[0]);
    //sum += freq[0];

    //printf("summation: %d\n", sum);

    int max = 0;
    for (i = 0; i < MAXLEN; i++)
        if (max < freq[i])
            max = freq[i];
    printf("Max. freq value: %d\n", max);

    for (i = max; i > 0; --i) {
        // putchar('|');
        for (j = 1; j < MAXLEN; ++j) {
            if (freq[j] >= i)
                printf("  X  ");
        }
        printf("\n");
    }

    for (i = 1; i < MAXLEN; ++i) {
        printf("%5d", freq[i]);
    }
    return 0;
}

