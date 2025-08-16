// Exercise 1-15. Write a program to print all lines that are longer than 80 characters.

#include <stdio.h>

#define MAXLINE 1000
#define MIN_LENGTH 80

int get_line(char s[], int lim) {
    int c, i;
    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
        s[i] = c;
    }
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

int main() {
    int len;
    char line[MAXLINE];

    while ((len = get_line(line, MAXLINE)) > 0) {
        if (len > MIN_LENGTH) {
            printf("%s", line);
        }
    }
    return 0;
}

