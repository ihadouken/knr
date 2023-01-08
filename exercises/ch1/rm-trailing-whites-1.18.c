#include <stdio.h>
/* takes multiple lines as input and returns the largest one */

#define MAXLEN 128
#define IN 1
#define OUT 0

/* declaration of functions :
 * getsline(to get lines of input)
 * copy(to save longest line) */
int getsline(char line[], int maxchar);
void copy(char from[], char to[]);

int main() {
    int len;
    char line[MAXLEN];

    while ((len = getsline(line, MAXLEN)) > 0) {
        printf("%s", line);
    }
    return 0;
}

/* getsline: reads a line into provided char array 's', return its length */
int getsline(char s[], int limit) {
    char temp[64];
    int c, i, p, j, nw, state;

    nw = 0;
    p = 50;
    state = IN;

    /* accept input line < maximum chars. (thus terminating at '\n') */
    for (i = 0; i<limit-1 && (c=getchar())!=EOF && c!='\n'; ++i) {
        if ((p!=' ' && p!='\n' && p!='\t') || (c!=' ' && c!='\n' && c!='\t')) {
            if (state == OUT) {
                j = 0;
                while (j <= nw) {
                    s[i] = temp [j];
                    ++i;
                    ++j;
                }
                state = IN;
                nw = 0;
            }
            s[i] = c;
            ++i;
        }
        else {
            state = OUT;
            temp[nw] = c;
            ++nw;
        }
    }
    /* add '\n' at end 's' as it holds a line in it */
    if (c == '\n') {
        s[i] = c;
        ++i;
        p = c;
    }
    /* NULL character to mark end of string */
    s[i] = '\0';
    return i;
}

/* copy: copy 'from' to 'to' (assuming its big enough) */
void copy(char from[], char to[]) {
    int i;

    i = 0;
    while ((to[i] = from [i]) != '\0')
        ++i;
}
