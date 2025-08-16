// Exercise 1-4. Write a program to print the corresponding Celsius to Fahrenheit table.

#include <stdio.h>

/* print Fahrenheit-Celsius table
for f = 0, 20, ..., 300 */

int main()
{
    int lower, upper, step;
    float fahr, celsius;
    lower = 0; /* lower limit of temperature table */
    upper = 300; /* upper limit */
    step = 20; /* step size */
    celsius = lower;

    printf("****   CELSIUS --> FAHRENHEIT   ****\n\n");

    while (celsius <= upper) {
        fahr = (celsius * 9.0/5.0) + 32.0;
        printf("%4.0f %6.0f\n", celsius, fahr);
        celsius = celsius + step;
    }
}