#include <stdio.h>

int main() {
    int n = 7, i, j;

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            if (i + j == (n+1)/2 + 1 || j - i == (n-1)/2 ||
                i - j == (n-1)/2 || i + j == (3*n+1)/2)
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }
    return 0;
}