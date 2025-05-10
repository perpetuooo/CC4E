// Exercise 3-4. Write the analogous function itob(n, s) which converts the unsigned integer n into a binary character representation in s. Write itoh, which converts an integer to hexadecimal representation.

#include <stdio.h>
#include <string.h>
#define MAX 100
#define DIGITS "0123456789abcdef"

void reverse(char r[]) {
    int i, j;
    char temp;

    for (i = 0, j = strlen(r) - 1; i < j; i++, j--) {
        temp = r[i];
        r[i] = r[j];
        r[j] = temp;
    }
}

void itob(int n, char s[]) {
    int i, bin;
    for (i=0; n>0; i++) {
        bin = n % 2;
        s[i] = '0' + bin;
        n /= 2;
    }

    s[i] = '\0';
}

void itoh(int n, char s[]) {
    int digit, new, i;
    char c;

    for (i=0; n>0; i++) {
        digit = n % 16;
        c = DIGITS[digit];
        s[i] = c;
        n = n / 16;
    }

    s[i] = '\0';
    reverse(s);
}

int main() {
    int n = 15;
    char r[MAX];
    
    itoh(n, r);
    printf("Hex: %s\n", r);
    itob(n, r);
    printf("Bin: %s\n", r);

    return 0;
}
