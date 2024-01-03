#ifndef VECTOR_H
#define VECTOR_H

typedef struct {
    int* vector;
    int capacity;
    int size;
} Vector;

Vector* create_vec(int capacity);
void delete_vec(Vector* vec);

void vec_push(Vector* vec, int value);
int  vec_pop(Vector* vec);
int  vec_capacity(Vector* vec);
int  vec_size(Vector* vec);
void vec_print(Vector* vec);
int vec_at(Vector* vec, int index);
int vec_search(Vector* vec, int value);

#endif
