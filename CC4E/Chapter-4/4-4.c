// Exercise 4-4. Write a routine ungets(s) which will push back an entire string onto the input. Should ungets know about buf and bufp, or should it just use ungetch?

#include <stdio.h>
#include <string.h>

#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

int getch(void) {
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) {
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}

void ungets(const char *s) {
    int len = strlen(s);
    while (len > 0)
        ungetch(s[--len]);
}

int main() {
    const char *testStr = "Hello, World!";
    ungets(testStr);

    int c;
    while ((c = getch()) != EOF)
        putchar(c);
    
    return 0;
}
