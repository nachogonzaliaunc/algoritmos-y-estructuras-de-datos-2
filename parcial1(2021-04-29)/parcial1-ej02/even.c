#include <stdbool.h>
#include <stdio.h> // printf
#include "even.h"

bool is_even_sorted(int array[], unsigned int length) {
    
    bool res = true;

    if(length == 0) {
        printf("No están admitidos los arreglo vacíos\n");
    } else if(length == 1) {
        printf("El arreglo tiene un solo elemento, por lo tanto está ordenado\n");
    } else {
        for(unsigned int i = 0; i < length - 1 && res; i += 2) {
            if(array[i] > array[i + 2]) {
                res = false;
            }
        }
    }

    printf("El arreglo %s está ordenado en sus posiciones pares\n", (res == true) ? "efectivamente" : "no");
    return res;
}

//funcion main para comprobar el funcionamiento del algoritmo
int main() {

    int array[100];

    array[0] = 6;
    array[1] = 1;
    is_even_sorted(array, 1);

    array[0] = 1;
    array[1] = 6;
    array[2] = 2;
    array[3] = 0;
    is_even_sorted(array, 4);

    array[0] = 1;
    array[1] = 6;
    array[2] = 0;
    array[3] = 0;
    is_even_sorted(array, 4);

    array[0] = 1;
    array[1] = 0;
    array[2] = 0;
    array[3] = 0;
    is_even_sorted(array, 4);

    array[0] = 1;
    array[1] = 6;
    array[2] = 2;
    array[3] = 0;
    array[4] = 3;
    is_even_sorted(array, 5);

    array[0] = 1;
    array[1] = 6;
    array[2] = 2;
    array[3] = 0;
    array[4] = -1;
    is_even_sorted(array, 5);

    return 0;
}