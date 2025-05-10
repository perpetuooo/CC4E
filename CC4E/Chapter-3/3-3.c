// Exercise 3-3. In a 2's complement number representation, our version of itoa does not handle the largest negative number, that is, the value of n equal to -(2wordsize-1). Explain why not. Modify it to print that value correctly, regardless of the machine it runs on.

#include <stdio.h>
#include <string.h>
#define MAX 100

void reverse(char r[]) {
    int i, j;
    char temp;

    for (i = 0, j = strlen(r) - 1; i < j; i++, j--) {
        temp = r[i];
        r[i] = r[j];
        r[j] = temp;
    }
}


void itoa(int n, char s[]) {
    int i = 0;
    int sign = n;

    if (n == (1 << (sizeof(int) * 8 - 1))) {
        do {
            s[i++] = -(n % 10) + '0';
            n /= 10;

        } while (n != 0);

    } else {
        if (sign < 0)
            n = -n;

        do {
            s[i++] = n % 10 + '0';

        } while ((n /= 10) > 0);
    }

    if (sign < 0)
        s[i++] = '-';
        
    s[i] = '\0';
    reverse(s);
}

int main() {
    char s[MAX];
    int n = (1 << 31);
    
    // printf("%d", n);
    itoa(n, s);
    printf("Result: %s\n", s);

    return 0;
}