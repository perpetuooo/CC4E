// From Python to C (at 3:48:30 on https://www.youtube.com/watch?v=PaPN51Mm5qQ).

#include <stdio.h>

#define DIGITS "0123456789abcdef"
#define MAX 30

void reverse(char r[], int length) {
    int i, j;
    char temp;

    for (i = 0, j = length - 1; i < j; i++, j--) {
        temp = r[i];
        r[i] = r[j];
        r[j] = temp;
    }
}

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

    out[length] = '\0'; 
    reverse(out, length); 

    printf("%d in base-8 is %s\n", x, out);

    // Base 16.
    y = x;
    length = 0;

    while (y > 0) {
        digit = y % 16;
        c = DIGITS[digit];
        out[length] = c;
        new = y / 16;
        y = new;
        length++;
    }

    out[length] = '\0';
    reverse(out, length);

    printf("%d in base-16 is %s\n", x, out);

    return 0;
}