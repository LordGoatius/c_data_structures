#include "bst.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

BST* create_bst(int64_t first_data) {
    BST* bst = malloc(sizeof(BST));
    bst->left  = NULL;
    bst->right = NULL;
    bst->data  = first_data;
    return bst;
}

inline bst_node* create_node(int64_t data) {
    bst_node *newnode = malloc(sizeof(bst_node));
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

void bst_add_rec(bst_node* node, int64_t data) {
    if (data > node->data) {
        if (node->right != NULL) bst_add_rec(node->right, data);
        else node->right = create_node(data);
    } else if (data < node->data) {
        if (node->left != NULL) bst_add_rec(node->left, data);
        else node->left = create_node(data);
    } else return;
}

void bst_add(BST* tree, int64_t data) {
    if (data > tree->data) {
        if (tree->right != NULL) bst_add_rec(tree->right, data);
        else tree->right = create_node(data);
    } else if (data < tree->data) {
        if (tree->right != NULL) bst_add_rec(tree->right, data);
        else tree->right = create_node(data);
    } else return;
}

void print_bst_inorder(BST* tree) {
    if (tree == NULL) return;
    print_bst_inorder((BST*)tree->left);
    printf("%ld ", tree->data);
    print_bst_inorder((BST*)tree->right);
}

void delete_bst(BST* tree) {
    if (tree == NULL) return;
    delete_bst((BST*)tree->left);
    delete_bst((BST*)tree->right);
    free(tree);
}
int bst_size(BST* tree) {
    if (tree == NULL) return 0;
    return 1 + bst_size(tree->left) + bst_size(tree->right);
}
void bst_remove_data(BST* tree, int64_t data);

