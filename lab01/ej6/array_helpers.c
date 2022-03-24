// librerias
#include <stdio.h>

#include "array_helpers.h"

// tanto array_from_file como array_dump son copias del ejercicio 1
unsigned int array_from_file(int array[],
           unsigned int max_size,
           const char *filepath) {
    // creo un archivo con nombre file
    FILE *file;

    // abro el archivo
    file = fopen(filepath, "r");
    // escaneo el largo del arreglo
    fscanf(file, "%u", &max_size);

    // escaneo los elementos del arreglo
    for(unsigned int i = 0; i < max_size; i++) {
        fscanf(file, "%d", &array[i]);
    }

    // cierro el archivo
    fclose(file);

    return max_size;
}

void array_dump(int a[], unsigned int length) {

    // imprimo el arreglo
    printf("[ ");

    for(unsigned int i = 0; i < length - 1; i++) {
        printf("%d, ", a[i]);
    }

    printf("%d ]\n", a[length - 1]);
}


//invierto el arreglo
void array_swap(int a[], unsigned int i, unsigned int j) {
    unsigned int tmp = a[i];
    a[i] = a[j];
    a[j] = tmp;
}


// verifico si el arreglo esta ordenado
mybool array_is_sorted(int a[], unsigned int length) {
    mybool res = true;

    for(unsigned int i = 0; i < length - 1; i++) {
        if(a[i+1] < a[i]) {
            res = false;
        }
    }

    if(res) {
        printf("El arreglo está ordenado\n");
    } else {
        printf("El arreglo no está ordenado\n");
    }

    return res;
}