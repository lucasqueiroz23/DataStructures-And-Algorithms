#include "linked_list.h"
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

/**
typedef struct node {
    int data;
    struct node* next;
    struct node* prev;
} node;

typedef struct linked_list {
    int length;
    node* head;
    node* tail;
} linked_list;
*/

/**
 * Creates a new linked list and returns
 * it.
 */
linked_list* create_linked_list() {
    linked_list* new_ll = malloc(sizeof(linked_list));
    new_ll->length = 0;

    node* head = malloc(sizeof(node));
    node* tail = malloc(sizeof(node));

    head->data = INT_MIN;
    tail->data = INT_MIN;

    head->prev = NULL;
    tail->prev = head;

    tail->next = NULL;
    head->next = tail;

    new_ll->head = head;
    new_ll->tail = tail;

    return new_ll;
}

void travel(linked_list* ll) {
    for(node* i = ll->head->next; i->next != NULL; i = i->next) {
        printf("%d ", i->data);
    }
}

void reverse_travel(linked_list* ll) {
    for(node* i = ll->tail->prev; i->prev != NULL; i = i->prev) {
        printf("%d ", i->data);
    }
}

/*
 * Creates a new node and puts it 
 * into the end of the list.
 */
void push(linked_list* ll, int data) {
    node* new_node = malloc(sizeof(node));

    new_node->data = ll->tail->data;
    ll->tail->data = data;

    new_node->prev = ll->tail;

    ll->tail->next = new_node;
    ll->length++;

    ll->tail = new_node;
}


/**
int pop(linked_list* ll);

int search(linked_list* ll, int target);

int remove(linked_list* ll, int target);

int update_value(linked_list* ll, int target, int new_value);

*/
