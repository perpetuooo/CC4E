// Exercise 2-2. Write the function htoi(s), which converts a string of hexadecimal digits into its equivalent integer value. The allowable digits are 0 through 9, a through f, and A through F.

#include <stdio.h>

#define MAX 100

int htoi(char s[]) {
    int n;

    for (int i=0; s[i]!='\0'; ++i) {
        char c = s[i];

        if (c >= '0' && c <= '9') {
            n = 16 * n + (c - '0');
        
        } else if (c >= 'a' && c <= 'f') {
            n = 16 * n + (c - 'a' + 10);
        
        } else if (c >= 'A' && c <= 'F') {
            c = c + 'a' - 'A';
            n = 16 * n + (c - 'a' + 10);
        }
    }

    return n;
}

int main() {
    char c[MAX];
    int valid = 1;

    printf("Enter a hexadecimal number: ");
    scanf("%s", c);

    for (int i=0; c[i]!='\0'; ++i) {
        if (!((c[i] >= '0' && c[i] <= '9') || (c[i] >= 'a' && c[i] <= 'f') || (c[i] >= 'A' && c[i] <= 'F'))) {
            valid = 0;
            break;
        }
    }

    if (!valid) {
        printf("Invalid hex number...");
    
    } else {
        int result = htoi(c);
        printf("Converted string: %d", result);
    }

    return 0;
}