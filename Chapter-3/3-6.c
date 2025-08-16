// Exercise 3-6. Write a program which copies its input to its output, except that it prints only one instance from each group of adjacent identical lines. (This is a simple version of the UNIX utility uniq.)

#include <stdio.h>
#include <string.h>

#define MAX_LINE 1024

int main() {
    char current_line[MAX_LINE];
    char previous_line[MAX_LINE] = "";

    while (fgets(current_line, MAX_LINE, stdin)) {
        if (strcmp(current_line, previous_line) != 0) {
            fputs(current_line, stdout);
            strcpy(previous_line, current_line);
        }
    }

    return 0;
}
