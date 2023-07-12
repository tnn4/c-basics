#include <stdio.h>

int main(void)
{
    
    printf("see: https://en.wikipedia.org/wiki/ANSI_escape_code\n");
    int i, j, n;

    for (i = 0; i < 11; i++) {
        for (j = 0; j < 10; j++) {
            n = 10 * i + j;
            if (n > 108) break;
            printf("\033[%dm %3d\033[m", n, n);
        }
        printf("\n");
    }

    // c char array vs char pointer
    // char* and char[] are _different_ types
    // c: https://stackoverflow.com/questions/1807530/difference-between-using-character-pointers-and-character-arrays
    
    return 0;
}