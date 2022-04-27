#include <stdio.h> // printf
#include <stdbool.h>

#include "pivot.h"

bool is_pivot(int array[], unsigned int length, unsigned int piv) {
    
    bool res = true;

    for(unsigned int i = 0; i < length; i++) {
        if((i < piv && array[i] > array[piv]) || (i > piv && array[piv] >= array[i])) {
            res = false;
        }
    }

    printf("%s\n", (res == true) ? "true" : "false");
    return res;
}

// funcion main para poner a prueba el algoritmo
int main() {
    int array[4];
    bool res;

    array[0] = 1;
    array[1] = 2;
    array[2] = 6;
    array[3] = 5;
    res = is_pivot(array, 4, 1);

    array[0] = 1;
    array[1] = 2;
    array[2] = 6;
    array[3] = 5;
    res = is_pivot(array, 4, 0);

    array[0] = 1;
    array[1] = 2;
    array[2] = 6;
    array[3] = 5;
    res = is_pivot(array, 4, 2);

    array[0] = 1;
    array[1] = 1;
    array[2] = 6;
    array[3] = 5;
    res = is_pivot(array, 4, 1);

    array[0] = 1;
    array[1] = 1;
    array[2] = 1;
    array[3] = 5;
    res = is_pivot(array, 4, 1);

    return 0;
}