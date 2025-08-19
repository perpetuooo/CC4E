// Exercise 5-1. Write getfloat, the floating point analog of get_int. What type does getfloat return as its function value?

#include <stdio.h>
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

// int get_int(pn) /* get next integer from input */
// int *pn;
// {
//   int c, sign;

//   while ((c = getch()) == ' ' || c == '\n' || c == '\t')
//   ;   /* skip white space */
//   sign = 1;
//   if (c == '+' || c == '-') { /* record sign */
//     sign = (c=='+') ? 1 : -1;
//     c = getch();
//   }
//   for (*pn = 0; c >= '0' && c <= '9'; c = getch())
//     *pn = 10 * *pn + c - '0';
//   *pn *= sign;
//   if (c != EOF)
//     ungetch(c);
//   return(c);
// }

int getfloat(float *pn) {
    int sign, c;
    float power;

    while ((c = getch()) == ' ' || c == '\n' || c == '\t')
    ;   /* skip white space */

    sign = 1;
    if (c == '+' || c == '-') { /* record sign */
        sign = (c=='+') ? 1 : -1;
        c = getch();
    }

    *pn = 0.0;
    for (; c >= '0' && c <= '9'; c = getch())
        *pn = 10.0 * *pn + (c - '0');

    if (c == '.') {
        c = getch();
        for (power = 1.0; c >= '0' && c <= '9'; c = getch()) {
            *pn = 10.0 * *pn + (c - '0');
            power *= 10.0;
        }
        *pn /= power;
    }

    *pn *= sign;

    if (c != EOF)
        ungetch(c);

    return (c);
}

int main () {
    int n;
    float v, array[BUFSIZE];

    for (n = 0; n < BUFSIZE && getfloat(&v) != EOF; n++)
        array[n] = v;
    
    printf("\n");
    for (n = 0; n < BUFSIZE; n++)
        printf("%f\n", array[n]);

    return 0;
}