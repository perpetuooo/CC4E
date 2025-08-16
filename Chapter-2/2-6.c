#include <stdio.h>

int wordlength() {
    unsigned int x = ~0;
    int count = 0;
    
    while (x != 0) {
        x >>= 1;
        count++;
    }
    
    return count;
}

int main() {
    printf("Word length: %d bits\n", wordlength());

    return 0;
}
