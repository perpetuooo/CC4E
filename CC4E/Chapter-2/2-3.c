// Exercise 2-3. Write an alternate version of squeeze(s1, s2) which deletes each character in s1 which matches any character in the string s2.

#include <stdio.h>

#define MAX 100

// squeeze(s, c) / delete all c from s /
// char s[];
// int c;
// {
// int i,  j;

// for (i = j = 0; s[i] != '\0'; i++)
//         if (s[i] != c)
//             s[j++] = s[i];
// s[j] = '\0';
// }

void squeeze(char s1[], char s2[]) {
    int i, j, k, match;
    
    for (i = j = 0; s1[i] != '\0'; i++) {
        match = 0;

        for (k = 0; s2[k] != '\0'; k++) {
            if (s1[i] == s2[k]) {
                match = 1;
                break;
            }
        }
        
        if (!match) {
            s1[j++] = s1[i];
        }
    }
    s1[j] = '\0';
}

int main() {
    char s1[MAX], s2[MAX];

    printf("Enter the first string: ");
    scanf("%s", s1);
    printf("Enter the second string: ");
    scanf("%s", s2);
    
    squeeze(s1, s2);
    printf("Result: %s", s1);


    return 0;
}