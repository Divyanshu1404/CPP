#include <stdio.h>

int main() {

    int a = 5, b = 2;

    if (a & b || a ^ b && ~b)

        printf("True");

    else

        printf("False");

    return 0;

}