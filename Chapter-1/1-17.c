// Exercise 1-17. Write a function reverse(s) which reverses the character string s. Use it to write a program which reverses its input a line at a time.

#include <stdio.h>

#define MAX 1000

int reverse(char s[]) {
    int l, i;
    char reverted[MAX];

    l = 0;  

    while (s[l] != '\0') {
        l++;   // Get lenght.
    }

    printf("Lenght: %d\n", l);

    l -= 2;   // Remove '\n' and '\0'.

    for (i = 0; i <= l; i++) {
        reverted[i] = s[l - i];
    }

    reverted[l + 1]  = '\0';   // Add '\0' to end the line.

    printf("Reversed line: %s\n", reverted);

    return 0;
}

int main() {
    char line[MAX];

    while (1) {
        printf("Enter a line: ");
        fgets(line, MAX, stdin);
        reverse(line);
    }

    return 0;
}

