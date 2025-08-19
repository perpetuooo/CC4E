// Exercise 5-4. Rewrite appropriate programs from earlier chapters and exercises with pointers instead of array indexing. Good possibilities include get_line (Chapter 1 and 4), atoi, itoa, and their variants (Chapter 2, 3, and Chapter 4), reverse (Chapter 3), and index and getop (Chapter 4).

#include <stdio.h>
#define MAX 100

int get_line(char *s) /* get line into s, return length */
{
    int c, i;
    i = 0;
    while((c=getchar())!=EOF && c!='\n') {
        *s++ = c;
        i++;
    }

    if (c == '\n') {
        *s++ = c;
        i++;
    }
 
    *s = '\0';
    return(i);

    // for (i=0; i<MAX-1 && (c=getchar())!=EOF && c!='\n'; ++i)
    //     s[i] = c;
    // if (c == '\n') {
    //     s[i] = c;
    //     ++i;
    // }
    // s[i] = '\0';
    // return(i);
}

int atoi(char *s) /* convert s to integer */
{
    int n = 0;


    while (*s >= '0' && *s <= '9') {
        n = 10 * n + *s++ - '0';
    }

    return(n);

    // for (i = 0; s[i] >= '0' && s[i] <= '9'; ++i)
    //     n = 10 * n + s[i] - '0';
}

void reverse (char *s) /* reverse string s in place */
{

  char *p = s;
  char tmp;

  while (*p) {
    p++;
  }
  p--;

  while (s < p) {
        tmp = *s;
        *s = *p;
        *p = tmp;
        s++;
        p--;
  }

//   int c, i, j;
//   for (i = 0, j = strlen(s)-1; i < j; i++, j--) {
//     c = s[i];
//     s[i] = s[j];
//     s[j] = c;
//   }
}

void itoa(int n, char *s[])    /* convert n to characters in s */
{
    int sign;

    if ((sign = n) < 0)    /* record sign */
        n = -n;              /* make n positive */
    
    do {    /* generate digits in reverse order */
        *s++ = n % 10 + '0';     /* get next digit */
    } while ((n /= 10) > 0); /* delete it */
    if (sign < 0)
        *s++ = '-';
    *s = '\0';
    reverse(s);
}

int index(char *s, char *t) /* return index of t in s, -1 if none */
{
  char *start = s;

  while (*s) {
    char *p = s;
    char *i = t;
    
    while (*p && *i && *p == *i) {
        p++;
        i++;
    }

    if (*i == '\0')
        return s-start;
    
    s++;
  }

  return -1;

//   int i, j, k;

//   for (i = 0; s[i] != '\0'; i++) {
//     for (j=i, k=0; t[k]!='\0' && s[j]==t[k]; j++, k++)
//       ;
//     if (t[k] == '\0')
//       return(i);
//   }
 
//   return (-1) ;
}

#define BUFSIZE 100
#define MAXOP 20 /* max size of operand, operator */
#define NUMBER '0' /* signal that number found */
#define TOOBIG '9' /* signal that string is too big */

char buf[BUFSIZE]; /* buffer for ungetch */
int bufp = 0; /* next free position in buf */

int getch() /* get a (possibly pushed back) character */
{
  return((bufp > 0) ? buf[--bufp] : getchar());
}

void ungetch (c) /* push character back on input */
int c;
{
  if (bufp > BUFSIZE)
    printf("ungetch: too many characters\n");
  else
    buf[bufp++] = c;
}

int getop(char *s, int lim) /* get next operator or operand */
{
  int i, c;

  while ((c = getch()) == ' ' || c == '\t' || c == '\n')
    ;
    
  if (c != '.' && (c < '0' || c > '9'))
    return(c);

  *s = c;
  
  while ((c = getchar()) >= '0' && c <= '9') {
    if (i < lim)
        *s = c;
        s++;    
  }

  if (c == '.') {  /* collect fraction */
    if (i < lim) {
      *s = c;
      s++;
    }
    
    while ((c = getchar()) >= '0' && c <= '9') {
        if (i < lim) {
            *s = c;
            s++;
        }
    }
  }

  if (i < lim) {  /* number is ok */
    ungetch(c);
    *s = '\0';
    return (NUMBER);
    
  } else { /* it's too big; skip rest of line */
    while (c != '\n' && c != EOF)
      c = getchar();
    s[lim-1] = '\0';
    return(TOOBIG);
  }

//   for (i = 1; (c = getchar()) >= '0' && c <= '9'; i++)
//     if (i < lim)
//       s[i] = c;
//   if (c == '.') {  /* collect fraction */
//     if (i < lim)
//       s[i] = c;
//     for (i++; (c=getchar()) >= '0' && c <= '9'; i++)
//       if (i < lim)
//         s[i] = c;
//   }
//   if (i < lim) {  /* number is ok */
//     ungetch(c);
//     s[i] = '\0';
//     return (NUMBER);
//   } else { /* it's too big; skip rest of line */
//     while (c != '\n' && c != EOF)
//       c = getchar();
//     s[lim-1] = '\0';
//     return(TOOBIG);
//   }
}


int main() {

    return 0;
}