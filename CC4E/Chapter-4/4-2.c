// Exercise 4-2. Extend atof so it handles scientific notation of the form 123.45e-6 where a floating point number may be followed by e or E and an optionally signed exponent.double atof(s) /* convert string s to double */

#include <stdio.h>
#define MAXLINE 100

double atof(char s[]) /* convert string s to double */ {
    double val, power, exp_val;
    int i, sign, exp_sign, exponent;

    for (i = 0; s[i] == ' ' || s[i] == '\n' || s[i] == '\t'; i++)
        ;     /* skip white space */

    sign = 1;
    if (s[i] == '+' || s[i] == '-') /* sign */
        sign = (s[i++] == '+') ? 1 : -1;

    for (val = 0; s[i] >= '0' && s[i] <= '9'; i++)
        val = 10 * val + (s[i] - '0');

    if (s[i] == '.')
        i++;

    for (power = 1; s[i] >= '0' && s[i] <= '9'; i++) {
        val = 10 * val + (s[i] - '0');
        power *= 10;
    }

    if (s[i] == 'e' || s[i] == 'E') {
        i++;
        exp_sign = 1;
        if (s[i] == '+' || s[i] == '-') {
            exp_sign = (s[i++] == '+') ? 1 : -1;
        }
        
        for (exponent = 0; s[i] >= '0' && s[i] <= '9'; i++) {
            exponent = 10 * exponent + (s[i] - '0');
        }
        
        exp_val = 1;
        while (exponent-- > 0) {
            exp_val *= 10;
        }
        
        if (exp_sign == 1) {
            val = val / power * exp_val;
        } else {
            val = val / power / exp_val;
        }
    } else {
        val = sign * val / power;
    }

    return val;
}

int main() {
    char s[MAXLINE] = "123.456789e6";
    
    printf("%.10f\n", atof(s));

    return 0;
}