// Exercise 1-13. Write a program to convert its input to lower case, using a function lower(c) which returns c if c is not a letter, and the lower case value of c if it is a letter.

#include <stdio.h>

char lower(char c) {
    int n;

    n = c;  // Convert to ASCII.

    if (n >= 65 && n <= 90) {   // Verifies if 'c' is a uppercase letter (according to the ASCII table).
        c = (n += 32);   // Converts to the lowercase character.

        return c;
    } else {
        return c;
    }
}

int main() {
    char c;

    printf("Enter a character:\n");
    scanf("%c", &c);
    c = lower(c);
    printf("Result: %c\n", c);

    return 0;
}


