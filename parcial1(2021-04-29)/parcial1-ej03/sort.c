/*
  @file sort.c
  @brief sort functions implementation
*/
#include <stdbool.h>
#include <assert.h>
#include <stdio.h> // printf
#include "helpers.h"
#include "sort.h"
#include "movie.h"


bool goes_before(movie_t s1, movie_t s2) {
    return s1.runtime <= s2.runtime;
}

unsigned int array_sorted_until(movie_t movielist[], unsigned int size) {
    
    unsigned int res = 0u; // contador para indicar hasta donde está ordenado el arreglo
    bool tmp = true; // variable para indicar que un arreglo se encuentra parcialmente ordenado

    for(unsigned int i = 0; i < size-1 && tmp; i++) {
        
        res++;
        
        if(!goes_before(movielist[i], movielist[i+1])) {
            tmp = false;
        }
    }

    if((tmp == false) && (res == 1)) {
        printf("Movielist isn't sorted\n");
    } else if ((tmp == false) && (res < size)) {
        printf("Movielist is sorted until %u\n", res - 1);
    } else if (tmp == true) {
        printf("Movielist is sorted\n");
    }
    return res;
}