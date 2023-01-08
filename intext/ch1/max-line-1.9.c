#include <stdio.h>
/* takes multiple lines as input and returns the largest one */

#define MAXLEN 128

/* declaration of functions :
 * getline(to get lines of input)
 * copy(to save longest line) */
int getline(char line[], int maxchar);
void copy(char from[], char to[]);

int main() {
    int len;
    int max;
    char line[MAXLEN];
    char longest[MAXLEN];

    max = 0;
    while ((len = getline(line, MAXLEN)) > 0) {
        if (len > max) {
            max = len;
            copy(line, longest);
        }
    }

    if (max > 0) /* if a line was given */
        printf("\nLongest: %s", longest);
    return 0;
}

/* getline: reads a line into provided char array 's', return its length */
int getline(char s[], int limit) {
    int c,i;

    /* accept input line < maximum chars. (thus terminating at '\n') */
    for (i = 0; i<limit-1 && (c=getchar())!=EOF && c!='\n'; ++i)
        s[i] = c;
    /* add '\n' at end 's' as it holds a line in it */
    if (c == '\n') {
        s[i] = c;
        ++i;
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
