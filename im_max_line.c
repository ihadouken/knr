#include <stdio.h>
/* takes multiple lines as input and returns the largest one */

#define MAXLEN 128
#define YES 1
#define NO 0
 
/* declaration of functions : 
 * getline(to get lines of input)
 * copy(to save longest line) */
int getline(char line[], int maxchar);
void copy(char from[], char to[]);

int main() {
    int len, max, truelen, nextline;
    char line[MAXLEN];
    char longest[MAXLEN];

    /* to temporarily store characters until MAXLEN in case of overflow */
    char temp[MAXLEN];

    max = truelen = 0;
    nextline = YES;
    while ((len = getline(line, MAXLEN)) > 0) {
        if (line[len-1] != '\n') {
            line[len-1] = '\n';
            if (truelen == 0)
                copy(line, temp);
            nextline = NO;
            truelen += len;
        }

        else
            nextline = YES;

        if (nextline == YES) {    
            if (truelen > 0 && truelen + len > max) {
                max = truelen + len;
                copy(temp, longest);
            }
            else if (truelen == 0 && len > max) {
                max = len;
                copy(line, longest);
            }
            truelen = 0;
        } 
    }

    if (max > MAXLEN) {
            printf("[ERROR]: Buffer of size %d overflowed by %d\n", MAXLEN, max-MAXLEN);
            /* printf("%d extra characters given!\n", max-MAXLEN+1); */
    }

    if (max > 0) { /* if a line was given */
        printf("\nLongest: %s", longest);
        printf("Length: %d\n", max);
    }
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
