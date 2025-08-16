// Exercise 1-22. Write a program to remove all comments from a C program. Don't forget to handle quoted strings and character constants properly.

#include <stdio.h>

#define OUT 0
#define IN_COMMENT 1
#define IN_STRING 2
#define IN_CHAR 3

int main() {
    int c, prev_c, state;

    state = OUT;
    prev_c = '\0';

    while ((c = getchar()) != EOF) {
        if (state == OUT) {
            if (c == '/' && prev_c == '/') {
                state = IN_COMMENT;

            } else if (c == '*' && prev_c == '/') {
                state = IN_COMMENT;

            } else if (c == '"') {
                state = IN_STRING;
                putchar(prev_c);
                putchar(c);

            } else if (c == '\'') {
                state = IN_CHAR;
                putchar(prev_c);
                putchar(c);

            } else {
                if (prev_c != '\0') {
                    putchar(prev_c);
                }
            }

            prev_c = c;

        } else if (state == IN_COMMENT) {
            if (c == '\n' && prev_c == '/') {
                state = OUT;
                putchar('\n');
                prev_c = '\0';
            }

            else if (c == '/' && prev_c == '*') {
                state = OUT;
                prev_c = '\0';

            } else {
                prev_c = c;
            }

        } else if (state == IN_STRING) {
            if (c == '"' && prev_c != '\\') {
                state = OUT;
                putchar(c);

            } else {
                putchar(c);
            }

            prev_c = c;

        } else if (state == IN_CHAR) {
            if (c == '\'' && prev_c != '\\') {
                state = OUT;
                putchar(c);

            } else {
                putchar(c);
            }
            prev_c = c; 
        }
    }

    if (state == OUT && prev_c != '\0') {
        putchar(prev_c);
    }

    return 0;
}