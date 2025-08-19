// Eitercise 5-3. Write a macro for strcpy.

#include <stdio.h>
#define max(A, B) ((A) > (B) ? (A) : (B))

#define swap(x, y) do { \
    int temp = (x);     \
    (x) = (y);          \
    (y) = temp;         \
} while (0)

#define strcpy(s, t) do {             \
    int i = 0;                        \
    while (((s)[i] = (t)[i]) != '\0') \
        i++;                          \
} while (0)

int main() {
    int x = 1;
    int y = 3;
    char t[50] = "hello, world!";
    char s[50];
    
    strcpy(s, t);
    printf("%s", s);
    return 0;
}