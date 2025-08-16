// Exercise 1-10. Write a program which prints the words in its input, one per line.

#include <stdio.h>

int main() {
    char c;
    
    while((c = getchar()) != EOF) {
        if (c == '\n' || c == '\t' || c == ' ') {
            printf("\n");
        } else {
            printf("%c", c);
        }
    }

    return 0;
}