// Exercise 3-2. Write a function expand(s1 , s2) which expands shorthand notations like a-z in the string s1 into the equivalent complete list abc...xyz in s2. Allow for letters of either case and digits, and be prepared to handle cases like a-b-s1[i] and a-z0-9 and -a-z. (A useful convention is that a leading or trailing - is taken literally.)

#include <stdio.h>
#define MAX 100

void expand(char s1[], char s2[]) {
    int i, j, k;
    char start, end;

    for (i = j = 0; s1[i] != '\0'; i++) {
        if (s1[i] == '-' && (i == 0 || s1[i+1] == '\0')) {
            s2[j++] = '-';
        
        } else if (s1[i] == '-' && i > 0 && s1[i+1] != '\0') {
            start = s1[i-1];
            end = s1[i+1];

            if ((start >= 'a' && end <= 'z' && start <= end) ||
                (start >= 'A' && end <= 'Z' && start <= end) ||
                (start >= '0' && end <= '9' && start <= end)) {
                
                for (k = start; k <= end; k++) {
                    s2[j++] = k;
                }
            }
        }
    }
    
    s2[j] = '\0';
}

int main() {
    char s1[MAX], s2[MAX];

    printf("Enter the first string: ");
    scanf("%s", s1);

    expand(s1, s2);

    printf("Result: %s\n", s2);

    return 0;
}
