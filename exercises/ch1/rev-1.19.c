#include <stdio.h>
/*reverse a string */

#define MAXLEN 1024

int getsline(char str[], int lim);
void reverse(char str[], int len);

int main() {
    int len;
    char string[MAXLEN];
    while ((len=getsline(string, MAXLEN)) > 0) {
        if (string[0] == '\n') {
            printf("\n");
        }
        else {
            reverse(string, len);
            printf("%s\n", string);
        }
    }
    return 0;
}

int getsline(char str[], int lim) {
    int i, c;
    for (i = 0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
        str[i] = c;

    if (i==0 && c=='\n') {
        str[i] = '\n';
        ++i;
    }
    str[i] = '\0';
    return i;
}

void reverse(char str[], int len) {
    int i;
    for (i = 0; i < len/2; ++i) {
        str[i] = str[i] + str[len-1-i];
        str[len-1-i] = str[i] - str[len-1-i];
        str[i] = str[i] - str[len-1-i];
    }
}
