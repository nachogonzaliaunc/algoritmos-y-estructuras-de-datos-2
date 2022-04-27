#include <stdio.h> // printf
#include <stdbool.h>

#include "odd.h"

bool is_odd_sorted(int array[], unsigned int length) {
    
    bool res = true;

    for(unsigned int i = 1; i < length - 2; i += 2) {
        if((i % 2 == 1) && array[i] > array[i + 2]) {
            res = false;
        }
    }

    printf("El arreglo está ordenado en sus posiciones impares?: %s\n", (res == true) ? "si" : "no");
    return res;
}

// funcion main para poner a prueba el algoritmo
int main() {

    int array[100];

    array[0] = 6;
    array[1] = 1;
    is_odd_sorted(array, 2);

    array[0] = 5;
    array[1] = 1;
    array[2] = 8;
    array[3] = 2;
    array[4] = 3;
    is_odd_sorted(array, 5);

    array[0] = 5;
    array[1] = 5;
    array[2] = 8;
    array[3] = 2;
    array[4] = 3;
    is_odd_sorted(array, 5);

    array[0] = 5;
    array[1] = 1;
    array[2] = 8;
    array[3] = 2;
    array[4] = 3;
    array[5] = 4;
    is_odd_sorted(array, 6);

    array[0] = 5;
    array[1] = 1;
    array[2] = 8;
    array[3] = 2;
    array[4] = 3;
    array[5] = -1;
    is_odd_sorted(array, 6);

    return 0;
}