#include <stdlib.h>
#include <stdio.h>

void absolute(int x, int y) {
    // practico el uso del operador terniario
    printf("El valor absoluto de %d es %d\n", x, 0 <= x ? x : -x);
}

int main(void) {
    int a = -98;
    int res = 0;

    absolute(a, res);

    printf("%d\n", res);

    return EXIT_SUCCESS;
}

