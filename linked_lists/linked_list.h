#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__

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

linked_list* create_linked_list();
/**
void push(linked_list* ll, int data);

int pop(linked_list* ll);

int search(linked_list* ll, int target);

int remove(linked_list* ll, int target);

int update_value(linked_list* ll, int target, int new_value);

void travel(linked_list* ll);
*/
#endif
