// Exercise 2-9. In a 2's complement number system, x & ( x-1 ) deletes the rightmost 1-bit in x. (Why?) Use this observation to write a faster version of bitcount

#include <stdio.h>

int wordlength() {
    unsigned int x = ~0;
    int count = 0;
    
    while (x != 0) {
        x &= (x - 1);
        count++;
    }
    
    return count;
}

int main() {
    printf("Word length: %d bits\n", wordlength());

    return 0;
}
