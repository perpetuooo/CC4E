#include <stdio.h>

#define END_LINE 25
#define TRUE 1
#define FALSE 0

int main() {
    int c, count, inword, last_blank;
    char buffer[END_LINE + 1];

    count = 0; 
    inword = FALSE;
    last_blank = -1;

    while ((c = getchar()) != EOF) {
        buffer[count] = c; 

        if (c == ' ' || c == '\t') {
            last_blank = count;
            inword = FALSE;
            
        } else if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
            inword = TRUE;
        }

        if (count == END_LINE - 1) {
            if (last_blank != -1) {

                for (int i = 0; i <= last_blank; i++) {
                    putchar(buffer[i]);
                }
                putchar('\n');

                int shift = count - last_blank;

                for (int i = 0; i < shift; i++) {
                    buffer[i] = buffer[last_blank + 1 + i];
                }

                count = shift - 1;
                last_blank = -1;

            } else {
                for (int i = 0; i <= count; ++i) {
                    putchar(buffer[i]);
                }

                putchar('\n');
                count = -1;
                last_blank = -1;
            }
        }

        count++;
    }

    for (int i = 0; i < count; ++i) {
        putchar(buffer[i]);
    }

    return 0;
}