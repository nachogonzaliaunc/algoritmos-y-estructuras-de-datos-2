/*
  @file sort.c
  @brief sort functions implementation
*/

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "helpers.h"
#include "sort.h"
#include "player.h"

bool goes_before(player_t x, player_t y){
        return x->rank <= y->rank;
}

bool array_is_sorted(player_t atp[], unsigned int length) {
    unsigned int i = 1u;
    while (i < length && goes_before(atp[i - 1u], atp[i])) {
        i++;
    }
    return (i == length);
}


static void swap(player_t a[], unsigned int i, unsigned int j) {
    player_t tmp;

    tmp = a[i];
    a[i] = a[j];
    a[j] = tmp;
}

static void insert(player_t a[], unsigned int length) {
    /* my new implementation */
    for(unsigned int i = 1; i < length; i++) {
        if(goes_before(a[i], a[i-1])) {
            swap(a,i-1,i);
        }
    }
}

void sort(player_t a[], unsigned int length) {
    /* i'm going to use selection sort */
    for (unsigned int i = 1u; i < length; ++i) {
        insert(a, length);
    }
}

