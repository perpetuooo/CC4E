// Exercise 2-10. Rewrite the function lower, which converts upper case letters to lower case, with a conditional expression instead of if-else.

#include <stdio.h>

char lower(char c) {
    // int n;

    // n = c;  // Convert to ASCII.

    // if (n >= 65 && n <= 90) {   // Verifies if 'c' is a uppercase letter (according to the ASCII table).
    //     c = (n += 32);   // Converts to the lowercase character.

    //     return c;
    // } else {
    //     return c;
    // }

    (c >= 'a' && c <= 'z') ? c -= 32 : c;

    return c;
}

int main() {
    char c;

    printf("Enter a character: ");
    scanf("%c", &c);
    c = lower(c);
    printf("Result: %c\n", c);

    return 0;
}
