// Exercise 3-1. Write a function expand(s, t) which converts characters like newline and tab into visible escape sequences like \n and \t as it copies the string s to t. Use a switch.

#include <stdio.h>
#define MAX 100

void expand(char s[], char t[]) {
    int i, j;

    for(i=j=0; s[i]!='\0'; i++) {
        switch (s[i]) {
            case '\n':
                t[j++] = '\\';
                t[j++] = 'n';
                break;
            case '\t':
                t[j++] = '\\';
                t[j++] = 't';
                break;
            default:
                t[j++] = s[i];
                break;
        }
    }

    t[j] = '\0';
}

int main() {
    char s[MAX], t[MAX];

    printf("Enter the first string: ");
    fgets(s, MAX, stdin);

    expand(s, t);

    printf("Result: %s", t);

    return 0;
}