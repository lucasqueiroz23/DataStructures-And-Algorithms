#include "linked_list.h"
#include <stdlib.h>
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

linked_list* create_linked_list() {
    linked_list* new_ll = malloc(sizeof(linked_list));
    new_ll->length = 0;

    node* head = malloc(sizeof(node));
    node* tail = malloc(sizeof(node));

    head->prev = NULL;
    head->next = tail;
    head->data = INT_MIN;

    tail->prev = head;
    tail->next = NULL;
    tail->data = INT_MIN;

    new_ll->head = head;
    new_ll->tail = tail;

    return new_ll;
}
/**
void push(linked_list* ll, int data);

int pop(linked_list* ll);

int search(linked_list* ll, int target);

int remove(linked_list* ll, int target);

int update_value(linked_list* ll, int target, int new_value);

void travel(linked_list* ll);
*/
