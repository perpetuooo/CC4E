// Exercise 1-19. Write a program detab which replaces tabs in the input with the proper number of blanks to space to the next tab stop. Assume a fixed set of tab stops, say every n positions

#include <stdio.h>

#define TAB_STOPS 6

int main() {
    int c, pos;

    pos = 0;

    while ((c = getchar()) != EOF) {
        if (c == '\t') {
            int spaces = TAB_STOPS - (pos % TAB_STOPS);

            for (int i = 0; i < spaces; i++) {
                putchar(' ');
                pos++;
            }

        } else if (c == '\n') {
            putchar(c);
            pos = 0;
            
        } else {
            putchar(c);
            pos++;
        }
    }
    return 0;
}