/* Remove comments from a C source file. */

#include <stdio.h>

/* Various states used by the comment parser */
#define NORM 0
#define SQUOTE 1
#define DQUOTE 2
#define SLASH 3
#define COMM 4
#define INCOMM 5
#define STAR 6
#define ESC 7

int main() {
    int ch, state;
    state = NORM;
    while ((ch = getchar()) != EOF) {
        if (state == NORM) {
            if (ch == '\'') {
                state = SQUOTE;
                putchar(ch);
            }
            else if (ch == '"') {
                state = DQUOTE;
                putchar(ch);
            }
            /* C comments starts with a slash character. */
            else if (ch == '/')
                state = SLASH;
            else
                putchar(ch);
        }

        /* Ignore comment delimeters found in quotes. */
        else if (state == SQUOTE) {
            if (ch == '\'')
                state = NORM;
            putchar(ch);
        }

        else if (state == DQUOTE) {
            if (ch == '"')
                state = NORM;
            putchar(ch);
        }

        else if (state == SLASH) {
            /* Enter regular comment. */
            if (ch == '*')
                state = COMM;
            /* Enter inline comment. */
            else if (ch == '/')
                state = INCOMM;
            /* Slash may not mean a comment everytime. */
            else {
                putchar('/');
                putchar(ch);
            }
        }

        else if (state == INCOMM) {
            if (ch == '\n') {
                state = NORM;
                putchar(ch);
            }
            /* Inline comments may span multiple lines via escaping newline. */
            if (ch == '\\')
                state = ESC;
        }

        else if (state == ESC)
            state = INCOMM;

        else if (state == COMM) {
            if (ch == '*')
                state = STAR;
        }

        /* Block comments end with star followed by a slash. */
        else if (state == STAR) {
            if (ch == '/')
                state = NORM;
            /* The star ending the comment may be preceeded by other stars. */
            else if (ch != '*')
                state = COMM;
        }
    }
    return 0;
}

