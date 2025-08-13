// Exercise 4-8. Write a recursive version of the function reverse(s), which reverses the string s.

#include <stdio.h>
#include <string.h>
#define MAX 1000

void reverse(char r[], int i, int j) {
    char temp;

    if (i < j) {
        temp = r[i];
        r[i] = r[j];
        r[j] = temp;
        reverse(r, ++i, --j);
    }

    // for (i = 0, j = strlen(r) - 1; i < j; i++, j--) {
    //     temp = r[i];
    //     r[i] = r[j];
    //     r[j] = temp;
    // }
}


int main() {
    char r[MAX] = "reverse";
    int i = 0;
    int j = strlen(r) - 1;

    reverse(r, i, j);
    
    printf("%s", r);
    return 0;
}