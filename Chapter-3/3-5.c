// Exercise 3-5. Write a version of itoa which accepts three arguments instead of two. The third argument is a minimum field width; the converted number must be padded with blanks on the left if necessary to make it wide enough.

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


void itoa(int n, char s[], int w) {
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
    
    while (i < w)
        s[i++] = ' ';
        
    s[i] = '\0';
    reverse(s);
}

int main() {
    char s[MAX];
    int n = (1 << 31);
    
    // printf("%d", n);
    itoa(n, s, 15);
    printf("Result: %s\n", s);

    return 0;
}