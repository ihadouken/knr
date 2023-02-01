/* Fold lines longer than a limit (possibly at a blank) */

#include <stdio.h>
#define LINELEN 1024
#define FOLDWIDTH 8

/* read a line into provided char array 's', return its length */
int getaline(char s[], int limit);
/* return the index of last whitespace char. in given line. */
int last_blank(char line[], int pos, int width);

int main(void) {
    char line[LINELEN];
    int len, blank, pos, i;

    while ((len=getaline(line, LINELEN-1)) > 0) {
        pos = 0;
        /* Keep folding the line until required. */
        while (len > FOLDWIDTH) {
            /* If blank exists as or before FOLDWIDTHth character. */
            if ((blank = last_blank(line, pos, FOLDWIDTH)) != -1) {
                for (i = pos; i < blank; ++i)
                    putchar(line[i]);
                /* Characters from index pos to blank (inclusive) processed. */
                len -= blank - pos + 1;
                /* Continue from just after blank. */
                pos = blank + 1;
            }
            else {
                for (i = 0; i < FOLDWIDTH - 1; ++i)
                    putchar(line[pos+i]);
                /* FOLDWIDTH-1 characters were processed. */
                len -= FOLDWIDTH - 1;
                /* Continue from FOLDWIDTHth element after current position. */
                pos += FOLDWIDTH - 1;
            }
            putchar('\n');
        }

        /* Print the last small part of the line which requires no folds. */
        for (i = 0; i < len; ++i)
            putchar(line[pos+i]);
    }
    return 0;
}

int getaline(char s[], int limit) {
    int c,i;

    /* accept input line < maximum chars. (thus terminating at '\n') */
    for (i = 0; (c=getchar())!=EOF && i<limit-1 && c!='\n'; ++i)
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

int last_blank(char line[], int pos, int width) {
    int blank = pos + width - 1;
    while (blank > pos) {
        if (line[blank] == ' ' || line[blank] == '\n' || line[blank] == '\t')
            return blank;
        --blank;
    }
    return -1;
}
