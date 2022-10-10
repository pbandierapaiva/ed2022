#include <stdio.h>

int main() {
    char c;

    for(;;) {
        c = getc(stdin);
        printf("Caracter %c - código %d", c, c);
    }


    return 0;
}