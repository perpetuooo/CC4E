// Exercise 4-3. Given the basic framework, it's straightforward to extend the calculator. Add the modulus (%) and unary minus operators. Add an "erase" command which erases the top entry on the stack. Add commands for handling variables. (Twenty-six single-letter variable names is easy.)

#include <stdio.h>

#define MAXOP 20 /* max size of operand, operator */
#define NUMBER '0' /* signal that number found */
#define TOOBIG '9' /* signal that string is too big */

double push();
double pop();
void clear();
int getop();
char getch();
void ungetch();


int main() /* reverse Polish desk calculator */
{
  int type;
  char s[MAXOP];
  double op2, atof(), pop(), push();

  while ((type = getop(s, MAXOP)) != EOF)
    switch (type) {

    case NUMBER:
        push(atof(s));
        break;

    case '+':
        push(pop() + pop());
        break;

    case '*':
        push(pop() * pop());
        break;

    case '-':
        op2 = pop();
        push(pop() - op2);
        break;

    case '/':
        op2 = pop();
        if (op2 != 0.0)
          push(pop() / op2);

        else
          printf("zero divisor popped\n");
        break;

    case '%':
    op2 = pop();
    if (op2 != 0.0)
        push((int) pop() % (int) op2);

    else
        printf("zero divisor popped\n");
    break;

    case '=':
        printf("\t%f\n", push(pop()));
        break;

    case 'c':
        clear();
        break;
    
    case 'e':
        pop();
        break;

    case TOOBIG:
        printf("%.20s ... is too long\n", s);
        break;

    default:
        printf("unknown command %c\n", type);
        break;
    }
}

#define MAXVAL 100 /* maximum depth of val stack */

int sp = 0; /* stack pointer */
double val[MAXVAL]; /* value stack */

double push(f) /* push f onto value stack */
double f;
{
  if (sp < MAXVAL)
    return(val[sp++] = f);
  else {
    printf("error: stack full\n");
    clear();
    return(0);
  }
}

double pop() /* pop top value from stack */
{
  if (sp > 0)
    return(val[--sp]);
  else {
    printf("error: stack empty\n");
    clear();
    return(0);
  }
}

void clear() /* clear stack */
{
  sp = 0;
}

int getop(s, lim) /* get next operator or operand */
char s[];
int lim;
{
  int i, c;

  while ((c = getch()) == ' ' || c == '\t' || c == '\n')
    ;
  if (c != '.' && (c < '0' || c > '9'))
    return(c);
  s[0] = c;
  for (i = 1; (c = getchar()) >= '0' && c <= '9'; i++)
    if (i < lim)
      s[i] = c;
  if (c == '.') {  /* collect fraction */
    if (i < lim)
      s[i] = c;
    for (i++; (c=getchar()) >= '0' && c <= '9'; i++)
      if (i < lim)
        s[i] = c;
  }
  if (i < lim) {  /* number is ok */
    ungetch(c);
    s[i] = '\0';
    return (NUMBER);
  } else { /* it's too big; skip rest of line */
    while (c != '\n' && c != EOF)
      c = getchar();
    s[lim-1] = '\0';
    return(TOOBIG);
  }
}


#define BUFSIZE 100

char buf[BUFSIZE]; /* buffer for ungetch */
int bufp = 0; /* next free position in buf */

char getch() /* get a (possibly pushed back) character */
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