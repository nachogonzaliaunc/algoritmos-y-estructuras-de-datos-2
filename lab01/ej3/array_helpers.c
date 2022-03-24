// librerias
#include <stdio.h>

#include "array_helpers.h"

// pido el largo del arreglo y sus valores
unsigned int array_from_file(int array[],
           unsigned int max_size,
           const char *filepath) {
    // creo un archivo con nombre file
    FILE *file;

    // abro el archivo
    file = fopen(filepath, "r");
    // pido al usuario el largo del arreglo
    int size;
    do {
        fprintf(stdout, "introduzca el largo del arreglo: "),
        scanf("%d", &size);
    } while (size <= 0);

    // pido al usuario los elementos del arreglo
    for(int i = 0; i < size; i++) {
        fprintf(stdout, "ingrese el valor de la posicion %u: ", i);
        scanf("%d", &array[i]);
    }

    // cierro el archivo
    fclose(file);

    max_size = size;
    return max_size;
}

//imprimo el arreglo
void array_dump(int a[], unsigned int length) {

    // imprimo el arreglo
    printf("[ ");

    for(unsigned int i = 0; i < length - 1; i++) {
        printf("%d, ", a[i]);
    }

    printf("%d ]\n", a[length - 1]);
}