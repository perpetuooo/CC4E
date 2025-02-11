// 3:48:30

#include <stdio.h>

#define DIGITS "0123456789abcdef"
#define MAX 30

// void reverse(char r[]) {

// }

int main() {
    int x, y, length, digit, new;
    char c, out[MAX];

    printf("Enter a base-10 number: ");
    scanf("%d", &x);

    y = x;
    length = 0;

    // Base 8.
    while (y > 0) {
        digit = y % 8;
        c = digit + '0';
        out[length] = c;
        new = y / 8;
        y = new;
        length++;
    }

    // reverse(out);
    out[length + 1] = '\0';

    printf("%d in base-8 is %s", x, out);

    return 0;
}