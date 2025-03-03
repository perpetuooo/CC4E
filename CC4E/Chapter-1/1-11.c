// Exercise 1-11. Revise the word count program to use a better definition of "word," for example, a sequence of letters, digits and apostrophes that begins with a letter.

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
            
        else if ( inword == NO && ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))) {
            inword = YES;
            ++nw;
        }
    }
    printf("Lines: %d\nWords: %d\nChars: %d\n", nl, nw, nc);
}