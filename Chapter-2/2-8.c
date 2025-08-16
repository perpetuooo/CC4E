// Exercise 2-8. Write the function invert(x, p, n) which inverts (i.e., changes 1 into 0 and vice versa) the n bits of x that begin at position p, leaving the others unchanged.

#include <stdio.h>

unsigned invert(unsigned x, unsigned p, unsigned n) {
    unsigned mask = (~(~0 << n)) << (p + 1 - n);

    return x ^ mask;
}

int main() {
    unsigned x = 214;   // 214 = 0b11010110

    printf("%u\n", invert(x, 5, 3));    // 238 = 0b11101110

    return 0;
}