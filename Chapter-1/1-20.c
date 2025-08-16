// Exercise 1-20. Write the program entab which replaces strings of blanks by the minimum number of tabs and blanks to achieve the same spacing. Use the same tab stops as for detab.

#include <stdio.h>

#define TAB_STOPS 8

int main() {
    int c, pos, spaces;

    pos = 0;
    spaces = 0;

    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            spaces++;

        } else {
            while (spaces > 0) {
                int next_tab_stop = TAB_STOPS - (pos % TAB_STOPS);

                if (spaces >= next_tab_stop) {
                    putchar('\t');
                    spaces -= next_tab_stop;
                    pos += next_tab_stop;

                } else {
                    putchar(' ');
                    spaces--;
                    pos++;
                }
            }
            putchar(c);

            if (c == '\n') {
                pos = 0;
                
            } else {
                pos++;
            }
        }
    }
    return 0;
}