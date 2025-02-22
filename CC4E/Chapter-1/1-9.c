// Exercise 1-9. How would you test the word count program? What are some boundaries?

#include <stdio.h>

#define YES 1
#define NO  0

int main() /* count lines, words, chars in input */
{
    int c, nl, nw, nc, inword;

    inword = NO;
    nl = nw = nc = 0;
    while ((c = getchar()) != EOF) {
        ++nc;
        if (c == '\n' )
            ++nl;
        if (c == ' ' || c == '\n' || c == '\t' )
            inword = NO;
        else if ( inword == NO ) {
            inword = YES;
            ++nw;
        }
    }
    printf("%d %d %d\n", nl, nw, nc);
}