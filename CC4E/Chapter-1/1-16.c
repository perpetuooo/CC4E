// Exercise 1-16. Write a program to remove trailing blanks and tabs from each line of input, and to delete entirely blank lines.

#include <stdio.h>

#define MAXLINE 1000

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

int remove_blanks(char s[], int len) {
    int i;

    for (i = len - 1; i >= 0; --i) {
        if (s[i] != ' ' && s[i] != '\t' && s[i] != '\n') {
            break;
        }
    }

    if (i >= 0) {
        s[i + 1] = '\n';
        s[i + 2] = '\0';
        return i + 2;
    } else {
        return 0;
    }    
}

int main() {
    int len;
    char line[MAXLINE];

    while ((len = get_line(line, MAXLINE)) > 0) {
        len = remove_blanks(line, len);

        if (len > 0) {
            printf("%s", line);
        }
    }
    return 0;
}
