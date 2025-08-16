// Exercise 2-1. Write a loop equivalent to the for loop above without using &&.

#include <stdio.h>

#define LIM 100

int main() {
    int i, c;
    char s[LIM];

    // for (i=0; i<LIM-1 && (c=getchar()) != '\n' && c != EOF; ++i)
    //     s[i] = c;

    for (i=0; i<LIM-1; ++i) {
        c = getchar();

        if (c == EOF || c == '\n')
            break;

        s[i] = c;
    }

    s[i] = '\0';
    printf(s);

    return 0;
}