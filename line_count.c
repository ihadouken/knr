#include <stdio.h>
/* This program count the number of lines in an input */

int main() {
    double count;
    int c;

    while ((c = getchar()) != EOF)
        if (c == '\n')
            ++count;
    printf("No. of lines: %.0f\n", count);
    return 0;
}
