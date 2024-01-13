#ifndef BST_H
#define BST_H

#include <stdint.h>
#include <stdlib.h>

typedef struct bst_node {
    int64_t data;
    struct bst_node *left;
    struct bst_node *right;
} bst_node;

typedef bst_node BST;

BST* create_bst(int64_t);

void bst_add(BST*, int64_t);
void print_bst_inorder(BST*);
void delete_bst(BST*);
int bst_size(BST*);
void bst_remove_data(BST*, int64_t);

#endif
