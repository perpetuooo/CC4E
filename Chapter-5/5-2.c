// Exercise 5-2. Write a pointer version of the function strcat which we showed in Chapter 2: strcat(s, t) copies the string t to the end of s.

#include <stdio.h>

void strcat2(s, t) /* concatenate t to end of s */
char *s, *t; /* s must be big enough */
{
  while (*s)  /* find end of s */
        s++;

  while (*s++ = *t++) /* copy t */
        ;
}

int main() {
    char s[100] = "Hello, ";
    char t[100] = "World!";

    strcat2(s, t);
    printf("%s", s);

    return 0;
}