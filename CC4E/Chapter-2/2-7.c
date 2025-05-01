// Exercise 2-7. Write the function rightrot(n, b) which rotates the integer n to the right by b bit positions

#include <stdio.h>

unsigned rightrot(unsigned n, int b) {

    return (n >> b) | (n << (32 - b));
}

int main() {
    unsigned n = 1;

    printf("%d\n", rightrot(n, 3));
}
