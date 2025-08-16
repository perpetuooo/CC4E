// Exercise 4-9. Define a macro swap(x, y) which interchanges its two int arguments. (Block structure will help.)

#include <stdio.h>
#define max(A, B) ((A) > (B) ? (A) : (B))
#define swap(x, y) do { \
    int temp = (x);     \
    (x) = (y);          \
    (y) = temp;         \
} while (0)

int main() {
    int x = 1;
    int y = 3;

    return 0;
}