#include <stdbool.h> // para verificar que el arreglo sigue ordenado
#include <stdio.h> // printf
#include "sorted.h"

unsigned int sorted_until(int array[], unsigned int size) {
    
    unsigned int sorted_i = 0; // indice hasta donde el arreglo esta ordenado
    bool tmp = true;

    for(unsigned int i = 0; i < size - 1 && tmp; i++) {
        if(array[i] <= array[i + 1]) {
            sorted_i++;
        } else {
            tmp = false;
        }
    }

    printf("%u\n", sorted_i);
    return sorted_i;
}

// funcion main para comprobar el algoritmo
int main() {

    int array[100];

    array[0] = 1;
    array[1] = 3;
    array[2] = 0;
    array[3] = 4;
    array[4] = 5;
    sorted_until(array, 5);

    array[0] = 1;
    array[1] = 3;
    array[2] = 4;
    array[3] = 0;
    array[4] = 0;
    sorted_until(array, 5);

    array[0] = 1;
    array[1] = 0;
    array[2] = 4;
    array[3] = 0;
    array[4] = 0;
    sorted_until(array, 5);

    array[0] = 1;
    array[1] = 3;
    array[2] = 4;
    array[3] = 5;
    array[4] = 5;
    sorted_until(array, 5);

    array[0] = 3;
    sorted_until(array, 1);

    return 0;
}