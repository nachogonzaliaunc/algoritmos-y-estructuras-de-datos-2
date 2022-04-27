#include <stdlib.h>
#include <stdio.h>

void absolute(int x, int *y) {

    if(x >= 0) {
        *y = x;
    } else {
        *y = -x;
    }
}

int main(void) {
    int a = -98;
    int res = 0;

    // declaracion y asignacion del puntero
    int *int_pointer = NULL;
    int_pointer = &res;

    absolute(a, int_pointer);

    printf("%d\n", res);

    return EXIT_SUCCESS;
}

