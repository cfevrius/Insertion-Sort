#ifndef list_C
#define list_C

#include <stdlib.h>
#include <stdio.h>
#include "list.h"

list* list_create(void){
    list* l = calloc(1, sizeof(list));
    return l;
}

list* list_destroy(list* l){
    node* curr = l->head;
    while(curr){
        node* next = curr->next;
        free(curr);
        curr = next; 
    }
    free(l);
    return NULL;
}

void  list_display(list* l){
    printf("[ ");
    node* n;
    for(n = l->head; n; n = n->next){
        if(n->next){
            printf("%d, ", n->data);
        } else {
            printf("%d ", n->data);
        }
    }
    printf(" ]\n");
}

void  list_append(list* l, int x){
    node* n = node_create(x);
    if(!(l->head)){
        l->head = n;
        l->tail = n;
    } else {
        l->tail->next = n;
        n->prev = l->tail;
        l->tail = n;
    }
}

#endif
