#include <stdio.h>

// copy input to output (cat)
int main() {
    int c;
    // checking if printf output can be assigned to var.
    // char p = printf("s");
    // putchar(p);

    while ((c = getchar()) != EOF)
        putchar(c);
}
