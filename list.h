#ifndef list_H
#define list_H

#include "node.h"

typedef struct list list;

struct list {
    node* head;
    node* tail;
    int size;
};

list* list_create(void);
list* list_destroy(list* l);

void  list_display(list* l);
void  list_append(list* l, int n);
void  list_swap(list* l, node* node1, node* node2);
void  list_sort(list* l);

#endif
