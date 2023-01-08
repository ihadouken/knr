#include <stdio.h>
/* prints lines longer than 32 characters */

#define MAXLEN 1024
#define SHOWLEN 32

int getsline(char line[], int lim);

int main() {
    char line[MAXLEN];
    int len;

    while ((len = getsline(line, MAXLEN)) > 0) {
        if (len > SHOWLEN) {
            printf("%s", line);
        }
    }
    return 0;
}

int getsline(char line[], int lim) {
    int i, c;
    for (i = 0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
        line[i] = c;

    if (c == '\n') {
        line[i] = '\n';
        ++i;
    }

    line[i] = '\0';
    return i;
}

