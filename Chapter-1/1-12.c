// Exercise 1-12. Write a program to print a histogram of the lengths of words in its input. It is easiest to draw the histogram horizontally; a vertical orientation is more challenging.

#include <stdio.h>

#define MAX 15

int main() {
    int count[MAX];
    int i, x, c, t;

    t = 0;
    
    for (i = 0; i <= MAX; i++) {
        count[i] = 0;
    }

    while ((c = getchar()) != EOF) {
        if (c == '\n' || c == '\t' || c == ' ') {
            if (t > 0 && t <= MAX) {
                count[t - 1]++;
                t = 0;
            }
        } else {
            t++;
        }
    }

    for (i = 0; i < MAX; i++) {
        if (count[i] != 0) {
            printf("%d characters ", i + 1);
            for (x = 0; x < count[i]; x++) {
                printf("|");
            }
            printf("\n");
        }
    }

    return 0;
}