// Exercise 1-2. Experiment to find out what happens when printf's argument string contains \x, where x is some character not listed above.

#include <stdio.h>

int main()
{
    printf("hello, ");
    printf("world");
    printf("\a");
    printf("\n");
}