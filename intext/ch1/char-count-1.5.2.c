#include <stdio.h>

// count characters in input

int main() {
    // use double counter as int is easily overflow-able
    float count;
    int c;
    count = 0;

    //for (count = 0; getchar() != EOF; ++count)
    while ((c = getchar()) != EOF)
        ++count;
    printf("No. of characters: %.0f\n", count);
    return 0;
}
