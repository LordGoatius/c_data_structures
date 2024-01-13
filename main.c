#include "linked/linked.h"
#include "vector/vector.h"
#include "tree/bst.h"
#include "schedule/schedule.h"
#include <stdio.h>

int main(int argc, char** argv) {
    BST* bst = create_bst(6);
    bst_add(bst, 9);
    bst_add(bst, 12);
    bst_add(bst, 10);
    bst_add(bst, 8);
    bst_add(bst, 3);
    bst_add(bst, 5);
    bst_add(bst, 4);
    bst_add(bst, 2);
    bst_add(bst, 1);
    print_bst_inorder(bst);
    printf("\n%d\n", bst_size(bst));
    delete_bst(bst);

    //Vector* vec = create_vec(7);
    //vec_push(vec, 148310);
    //vec_push(vec, 114831);
    //vec_push(vec, 81431);
    //vec_push(vec, 321310);
    //vec_push(vec, 21431);
    //vec_push(vec, 6418310);
    //vec_push(vec, 414831);
    //vec_print(vec);
    //schedule_sort(vec);
    //vec_print(vec);
    //delete_vec(vec);

    //LinkedList* list = create_list();
    //push(list, 3);
    //push(list, 8);
    //push(list, 9);
    //push(list, 7);
    //push(list, 8);
    //push(list, 0);
    //push(list, 62);
    //push(list, 32);
    //push(list, 16);
    //push(list, 64);
    //push(list, 12);
    //print_list(list);
    //quicksort(list);
    //print_list(list);
    //delete_list(list); 
}


