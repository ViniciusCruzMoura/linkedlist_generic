#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
=============================================================================

                            LINKED LIST

=============================================================================
*/

struct node {
    void* data;
    struct node* next;
};

struct linked_list {
    struct node* head;
    struct node* tail;
};

struct node* create_node(void* data) {
    struct node* newNode = (struct node*) malloc(sizeof(struct node));
    if (!newNode) {
        printf("Memory error\n");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct linked_list* create_linked_list() {
    struct linked_list* list = (struct linked_list*) malloc(sizeof(struct linked_list));
    if (!list) {
        printf("Memory error\n");
        return NULL;
    }
    list->head = NULL;
    list->tail = NULL;
    return list;
}

void add_node(struct linked_list* list, void* data) {
    struct node* newNode = create_node(data);
    if (list->head == NULL) {
        list->head = newNode;
        list->tail = newNode;
    } else {
        list->tail->next = newNode;
        list->tail = newNode;
    }
}

void delete_node(struct linked_list* list, void* data) {
    struct node * current = list->head;
    struct node * previous = current;
    while(current != NULL) {
        if(current->data == data) {
            previous->next = current->next;
            if(current == list->head) {
                list->head = current->next;
            }
            free(current);
            return;
        }
        previous = current;
        current = current->next;
    }
}

void print_list(struct linked_list* list, void (*printData)(void*)) {
    struct node* temp = list->head;
    while (temp != NULL) {
        printData(temp->data);
        temp = temp->next;
    }
}


/*
=============================================================================

                            QUICKSORT-LINKED-LIST

=============================================================================
*/

struct node* _partition(struct node* head,struct node* tail, int(*comp_func_ptr)()) {
    // Select the first node as the pivot node
    struct node* pivot = head;

    // 'pre' and 'curr' are used to shift all
    // smaller nodes' data to the left side of the pivot node
    struct node* pre = head;
    struct node* curr = head;

    // Traverse the list until you reach the node after the tail
    while (curr != tail->next) {
        // If current node's data is less than the pivot's data
        if (comp_func_ptr(curr->data, pivot->data)) {

            // Swap the data between 'curr' and 'pre->next'
            void* temp = curr->data;
            curr->data = pre->next->data;
            pre->next->data = temp;

            // Move 'pre' to the next node
            pre = pre->next;
        }
        // Move 'curr' to the next node
        curr = curr->next;
    }

    // Swap the pivot's data with 'pre' data
    void* currData = pivot->data;
    pivot->data = pre->data;
    pre->data = currData;

    // Return 'pre' as the new pivot
    return pre;
}

void _quicksort_node(struct node* head, struct node* tail, int(*comp_func_ptr)()) {
    if (head == NULL || head == tail) {
        return;
    }
    struct node* pivot = _partition(head, tail, comp_func_ptr);
    _quicksort_node(head, pivot, comp_func_ptr);
    _quicksort_node(pivot->next, tail, comp_func_ptr);
}

struct linked_list* quicksort(struct linked_list* list, int(*comp_func_ptr)()) {
    _quicksort_node(list->head, list->tail, comp_func_ptr);
    return list;
}
