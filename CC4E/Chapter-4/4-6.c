// Exercise 4-6. Our getch and ungetch do not handle a pushed-back EOF in a portable way. Decide what their properties ought to be if an EOF is pushed back, then implement your design.

#include <stdio.h>
#define BUFSIZE 100
#define STOP 23 // ASCII for CTRL+W

char buf[BUFSIZE]; /* buffer for ungetch */
int bufp = 0; /* next free position in buf */

int getch() /* get a (possibly pushed back) character */
{
  return((bufp > 0) ? buf[--bufp] : getchar());
}

void ungetch (c) /* push character back on input */
int c;
{
  if (bufp > BUFSIZE) {
    printf("ungetch: too many characters\n");

  } else {
    if (c == EOF) {
        c = '!';  // new representation for EOF
    }
  
    buf[bufp++] = c;
  }
}

int main() {
    char c;

    while ((c = getch()) != STOP)
    {
        if (c == 'a')
            ungetch(c);
        else
            putchar(c);
    }

    return 0;
}