#include <stdio.h>
/* checks ascii charset and displays numeric values for chars. */

int main() {
    int c;

    printf("Please enter your character: ");
    c = getchar();

    printf("\nASCII value for input character is %d\n", c);
    return 0;
}

