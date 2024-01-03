#include "linked.h"
#include "vector.h"
#include <stdio.h>

int main(int argc, char** argv) {
    Vector* vec = create_vec(2);
    vec_push(vec, 1);
    vec_push(vec, 2);
    vec_push(vec, 4);
    vec_push(vec, 8);
    vec_push(vec, 16);
    vec_push(vec, 32);
    vec_print(vec);
    int popped = vec_pop(vec);
    int at = vec_at(vec, 2);
    int index = vec_search(vec, 8);
    printf("Pop: %d\nAt: %d\nIndex: %d\n", popped, at, index);
    vec_print(vec);
    delete_vec(vec);

    LinkedList* list = create_list();
    push(list, 3);
    push(list, 8);
    push(list, 9);
    push(list, 7);
    push(list, 8);
    push(list, 0);
    push(list, 62);
    push(list, 32);
    push(list, 16);
    push(list, 64);
    push(list, 12);
    print_list(list);
    quicksort(list);
    print_list(list);
    delete_list(list); 
}


