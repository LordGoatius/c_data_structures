#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "vector.h"

Vector* create_vec(int capacity) {
    Vector* vec = (Vector*) malloc(sizeof(Vector));
    vec->vector = (int*) malloc(capacity * sizeof(int));
    vec->capacity = capacity;
    vec->size = 0;
    return vec;
}

void delete_vec(Vector *vec) {
    free(vec->vector);
    free(vec);
}

void vec_push(Vector *vec, int value) {
    if (vec->size < vec->capacity) {
        vec->vector[vec->size] = value;
        vec->size = vec->size + 1;
    } else {
        int* new_vec = (int*) malloc(vec->capacity * 2 * sizeof(int));
        for (int i = 0; i < vec->size; i++) {
            new_vec[i] = vec->vector[i];
        }
        free(vec->vector);
        vec->vector = new_vec;
        vec->vector[vec->size] = value;
        vec->size = vec->size += 1;
        vec->capacity = vec->capacity * 2;
    }
}

int vec_pop(Vector *vec) {
    vec->size = vec->size - 1;
    return vec->vector[vec->size];
    /*
     * int* ptr = [0, 9, 5, 6, 3, 2];  SAME THING
     * int[] ptr = [0, 9, 5, 6, 3, 2]; SAME THING
     * ptr => 0xbbbb: 0x0000 0900 0500 0600 0300 0200;
     * ptr[x]
     * * (ptr + x * sizeof(int))
     * */
} 

int vec_capacity(Vector *vec) {
    return vec->capacity;
}

int vec_size(Vector *vec) {
    return vec->size; 
}

void vec_print(Vector *vec) {
    printf("Vector { ");
    for (int i = 0; i < vec->size; i++) {
        printf("%d ", vec->vector[i]);
    }
    puts("}");
}

int vec_at(Vector *vec, int index) {
    if (index < vec->size) {
        return vec->vector[index];
    } else {
        return INT_MIN;
    }
}

int vec_search(Vector *vec, int value) {
    for (int i = 0; i < vec->size; i++) {
        if (vec->vector[i] == value) {
            return i;
        }
    }
    return -1;
}
