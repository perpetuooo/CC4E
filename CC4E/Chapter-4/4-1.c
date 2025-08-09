// Exercise 4-1. Write the function rindex(s, t), which returns the position of the rightmost occurrence of t in s, or -1 if there is none.

#include <stdio.h>
#define MAXLINE 100

int rindex(char s[], char t[], int lenght) {
    int i, j, k;
    int t_len = 0;

    while (t[t_len] != '\0')
    t_len++;

    for (i=lenght-1; i>=0; i--) {
        for (j=i, k=t_len-1; k>=0 && j>=0 && s[j]==t[k]; j--, k--) {
            ;
        }
 
        if (k < 0) {
            return j + 1;
        }
    }

    return -1;
}

int get_line(char s[], int lim) /* get line into s, return length */
{
    int c, i;

    for (i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
        s[i] = c;

    if (c == '\n') {
        s[i] = c;
        ++i;
    }

    s[i] = '\0';
    return i;
}

int main() {
    char s[MAXLINE], t[MAXLINE];
    int l;

    while ((l = get_line(s, MAXLINE)) > 0) {

        if (rindex(s, "the", l) >= 0) {
            printf("%s", s);
        }
    }

    printf("%d", get_line("teste", MAXLINE));

    return 0;
}