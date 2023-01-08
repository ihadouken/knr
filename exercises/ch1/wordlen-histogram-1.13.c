#include <stdio.h>
/* prints histogram on basis of length of words */

#define MAXLEN 21
#define MAXWORDS 1024
#define HISTSYM '*'
#define OUT 0
#define IN 1

int main() {
    int c, i, j, wlen, wc, state;
    int freq[MAXLEN];
    
    for (i = 0; i < MAXLEN; ++i)
        freq[i] = 0;
    
    wc = wlen = 0;
    state = OUT;
    while ((c = getchar()) != EOF && wc <= MAXWORDS) {
        
        if (c != '\n' && c != '\t' && c != ' ') {
            ++wlen;
            if (state == OUT) {
                state = IN;
                ++wc;
            }
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
    
    printf("\nPrinting your histogram ... \n\nX -> Num. of words \nY -> Word length \n\nTotal words: %d\n\n", wc);

    for (i = 1; i < MAXLEN; ++i) {
        printf("%3d\t", i);
        for (j = 0; j < freq[i]; ++j) 
            //putchar('X');
            printf("\033[1;31m%c\033[0m", HISTSYM);
        printf("\t(%d)\n", freq[i]);
    } 

    printf(">20\t");
    for (j = 0; j < freq[0]; ++j)
        printf("\033[1;31m%c\033[0m", HISTSYM);
    printf("\t(%d)\n\n", freq[0]);

    printf("Scale: 1 \033[1;31m%c\033[0m = 1 word\n", HISTSYM);
    return 0;
}
