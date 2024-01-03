#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "linked.h"

LinkedList* create_list() {
    // LinkedList* list = new LinkedList();
    LinkedList* list = (LinkedList*) malloc(sizeof(LinkedList));
    list->head = NULL;
    return list;
}

void push(LinkedList *linked_list, int64_t data) {
    Node* head = linked_list->head;

    if (head == NULL) {
        Node* node = (Node*) malloc(sizeof(Node));
        node->data = data;
        node->next = NULL;
        linked_list->head = node;
        return;
    }

    if (head->next == NULL) {
        Node* node = (Node*) malloc(sizeof(Node));
        node->data = data;
        node->next = NULL;
        linked_list->head->next = node;
        return;
    }

    Node* node = linked_list->head;

    while (node->next != NULL) {
        node = node->next;
    }

    Node* to_insert = (Node*) malloc(sizeof(Node));
    to_insert->data = data;
    to_insert->next = NULL;
    node->next = to_insert;
    return;
}

void delete_node(Node* head) {
    if (head == NULL) {
        return;
    }
    delete_node(head->next);
    free(head);
    head = NULL;
}

void delete_list(LinkedList *linked_list) {
    delete_node(linked_list->head);
    //delete LinkedList
    free(linked_list);
}

void print_list(LinkedList *linked_list) {
    Node* node = linked_list->head;

    printf("LinkedList { ");

    while (node != NULL) {
        printf("%ld ", node->data);
        node = node->next;
    }

    puts("}");
}

int list_size(LinkedList* linked_list) {
    int size = 0;
    Node* node = linked_list->head;

    while (node != NULL) {
        size += 1;
        node = node->next;
    }
    return size;
}

int64_t at(LinkedList* linked_list, int64_t index) {
    if (index > list_size(linked_list) - 1) {
        return -1;
    }

    Node* node = linked_list->head;

    while(index != 0) {
        node = node->next;
        index -= 1;
    }

    if (node == NULL) {
        return -2;
    }

    return node->data;
}

int64_t* at_ptr(LinkedList* linked_list, int64_t index) {
    if (index > list_size(linked_list) - 1) {
        return NULL;
    }

    Node* node = linked_list->head;

    while(index != 0) {
        node = node->next;
        index -= 1;
    }

    if (node == NULL) {
        return NULL;
    }

    return &node->data;
}

void remove_data(LinkedList *linked_list, int64_t data) {
    Node* prev = linked_list->head;

    if (prev == NULL) {
        return;
    }

    Node* curr = prev->next;

    if (prev->data == data) {
        Node* delete = prev;
        linked_list->head = curr;
        free(delete);
        return;
    }

    while (curr != NULL) {
        if (curr->data == data) {
            Node* delete = curr;
            prev->next = curr->next;
            free(delete);
            return;
        }
        prev = curr;
        curr = curr->next;
    }
}

int64_t* find(LinkedList *linked_list, int64_t data) {
    Node* curr = linked_list->head;

    while(curr != NULL) {
        if (curr->data == data) {
            return &curr->data;
        }
        curr = curr->next;
    }
    return NULL;
}

void swap_index(LinkedList *linked_list, int64_t index_1, int64_t index_2) {
    int64_t* val_1 = at_ptr(linked_list, index_1);
    int64_t* val_2 = at_ptr(linked_list, index_2);
    
    if (val_1 == NULL || val_2 == NULL) {
        return;
    }

    int64_t temp = *val_1;
    *val_1 = *val_2;
    *val_2 = temp;
}

void bubble_sort(LinkedList *linked_list) {
    for (int i = list_size(linked_list); i > 0; --i) {
        for (int j = 0; j < i - 1; ++j) {
            if(at(linked_list, j) > at(linked_list, j+1)) {
                swap_index(linked_list, j, j+1);
            }
        }
    }
}

void reverse(LinkedList *linked_list) {
    int last = list_size(linked_list) - 1;
    for (int i = list_size(linked_list) - 1; i >= last/2; --i) {
        int index_1 = i;
        int index_2 = last - i;
        swap_index(linked_list, index_1, index_2);
    }
}

void replace(LinkedList *linked_list, int64_t index, int64_t data) {
    int64_t* to_replace = at_ptr(linked_list, index);
    *to_replace = data;
}

// Some more function stubs, because C was made in the stone age
void quicksort_rec(LinkedList*, int, int);
int partition(LinkedList*, int, int);

// Sorts whole array
void quicksort(LinkedList *linked_list) {
    quicksort_rec(linked_list, 0, list_size(linked_list) - 1);
}

void quicksort_rec(LinkedList *linked_list, int pivot, int right) {
    if (pivot < right) {
        int mid = partition(linked_list, pivot, right);
        quicksort_rec(linked_list, pivot, mid-1);
        quicksort_rec(linked_list, mid+1, right);
    }
}

int partition(LinkedList *linked_list, int left, int right) {
    int pivot = at(linked_list, right);
    int i = left - 1;
    for (int j = left; j < right; j++) {
        if (at(linked_list, j) <= pivot) {
            i += 1;
            swap_index(linked_list, i, j);
        }
    }
    swap_index(linked_list, i+1, right);
    return i+1;
}

