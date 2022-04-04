#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "array_helpers.h"
#include "sort_helpers.h"
#include "sort.h"

static unsigned int min_pos_from(int a[], unsigned int i, unsigned int length) {
    unsigned int min_pos = i;
    for (unsigned int j = i + 1; j < length; ++j) {
        if (!goes_before(a[min_pos],a[j])) {
            min_pos = j;
        }
    }
    return (min_pos);
}

void selection_sort(int a[], unsigned int length) {
    for (unsigned int i = 0u; i < length; ++i) {
        unsigned int min_pos = min_pos_from(a, i, length);
        swap(a, i, min_pos);
    }
}


static void insert(int a[], unsigned int i) {
    /* my implementation */
    unsigned int j = i;
    while(0 < j && goes_before(a[j], a[j-1])) {
        swap(a,j-1,j);
        j--;
    }
}

void insertion_sort(int a[], unsigned int length) {
    for (unsigned int i = 1u; i < length; ++i) {
        insert(a, i);
    }
}


static unsigned int partition(int a[], unsigned int izq, unsigned int der) {
    /* my implementation */

    unsigned int piv = izq;
    unsigned int i = izq + 1;
    unsigned int j = der;

    while(i <= j) {
        if(goes_before(a[i], a[piv])) {
            i++;
        } else if(goes_before(a[piv], a[j])) {
            j--;
        } else if(goes_before(a[piv], a[i]) && goes_before(a[j], a[piv])) {
            swap(a, i, j);
            i++;
            j--;
        }
    }
    
    swap(a, piv, j);
    piv = j;

    return piv;
}

static void quick_sort_rec(int a[], unsigned int izq, unsigned int der) {
    /* my implementation */
    unsigned int piv = 0;

    if (izq < der) {
        piv = partition(a,izq,der);

        /* no implemento partition, ya está implementado en sort_helpers.o */
        quick_sort_rec(a,izq,piv);
        quick_sort_rec(a,piv+1,der);
    }
}

void quick_sort(int a[], unsigned int length) {
    quick_sort_rec(a, 0u, (length == 0u) ? 0u : length - 1u);
}
