// Exercise 4-7. Adapt the ideas of printd to write a recursive version of itoa; that is, convert an integer into a string with a recursive routine.

#include <stdio.h>
#include <string.h>
#define MAX 100

void reverse(char r[]) {
    int i, j;
    char temp;

    for (i = 0, j = strlen(r) - 1; i < j; i++, j--) {
        temp = r[i];
        r[i] = r[j];
        r[j] = temp;
    }
}


int itoa(n, s, x)    /* convert n to characters in s */
char s[];
int n, x;
{
    if ((n / 10) != 0)
        x = itoa(n / 10, s, x);
    s[x++] = n % 10 + '0';     /* get next digit */
    return x;
        
    // i = 0;
    // do {    /* generate digits in reverse order */
    //     s[i++] = n % 10 + '0';     /* get next digit */

    // } while ((n /= 10) > 0); /* delete it */
        
}

int main() {
    char s[MAX];
    int n = 47; 
    int x = 0;

    if (n < 0) {
        n = -n;         
        s[x++] = '-';
    }    

    x = itoa(n, s, x);
    s[x] = '\0';
    printf("Result: %s\n", s);

    return 0;
} 