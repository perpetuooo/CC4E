// Exercise 4-5. Suppose that there will never be more than one character of pushback. Modify getch and ungetch accordingly.

#include <stdio.h>
#define BUFSIZE 100

char buf; /* buffer char for ungetch */
int bufp = 0; /* checks if buffer is full */

int getch() /* get a (possibly pushed back) character */
{
  if (bufp) {
    bufp = 0;
    return buf;
  } else {
    return getchar();
  }
}

void ungetch (c) /* push character back on input */
int c;
{
  if (bufp)
    printf("ungetch: buffer is full\n");
  else
    buf = c;
    bufp = 1;
}

int main() {
    char c;

    while ((c = getch()) != EOF) {
        if (c == 'a')
            ungetch(c);
        else
            putchar(c);
    }

    printf(buf);
    return 0;
}