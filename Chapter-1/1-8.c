// Exercise 1-8. Write a program to replace each tab by the three-character sequence >, backspace, -, which prints as >, and each backspace by the similar sequence <. This makes tabs and backspaces visible.

#include <stdio.h>

int main()
{
    int c;

    c = getchar();

    while (c != EOF) {
        if (c == '\t') {
            printf(">--");

        } else if (c == '\b') {
            printf("<--");
            
        } else {
            putchar(c);
        }

        c = getchar();
    }
}
