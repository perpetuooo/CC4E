// Exercise 2-5. Modify getbits to number bits from left to right.

#include <stdio.h>

int getbits(x, p, n) /* get n bits from position p */
unsigned x, p, n;
{
    return((x >> (p+1-n)) & ~(~0 << n));
}

int getleftbits(unsigned x, unsigned p, unsigned n) {
    return ((x >> ((32 - p) + 1 - n)) & ~(~0 << n));
}

int main () {
    printf("%d", getleftbits(214, 5, 3));   // 214 = 0b11010110

    return 0;
}