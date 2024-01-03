#ifndef LINKED_H
#define LINKED_H

#include <stdint.h>

typedef struct Node {
    int64_t data;
    struct Node* next;
} Node;

typedef struct {
    struct Node* head;
} LinkedList;

LinkedList* create_list();

void push(LinkedList* linked_list, int64_t data);
void print_list(LinkedList* linked_list);
void delete_list(LinkedList* linked_list);
int list_size(LinkedList* linked_list);
int64_t at(LinkedList* linked_list, int64_t index);
int64_t* at_ptr(LinkedList* linked_list, int64_t index);
void remove_data(LinkedList* linked_list, int64_t data);
int64_t* find(LinkedList* linked_list, int64_t data);
void swap_index(LinkedList* linked_list, int64_t index_1, int64_t index_2);
void bubble_sort(LinkedList* linked_list);
void reverse(LinkedList* linked_list);
void quicksort(LinkedList* linked_list);
void replace(LinkedList* linked_list, int64_t index, int64_t data);

#endif
