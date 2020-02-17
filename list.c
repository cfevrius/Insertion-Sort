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

void  list_swap(list* l, node* node1, node* node2){
    node* node1_orig_prev = node1->prev;
    node* node2_orig_next = node2->next;

    /* first node is head */
    if(node1->prev == 0){
        l->head = node2;
        node2->prev = 0;
    } else {
        node2->prev = node1_orig_prev;
        node1_orig_prev->next = node2;
    }
    node1->prev = node2;
    node2->next = node1;

    /* second node is tail */
    if(node2_orig_next == 0){
        node1->next = 0;
    } else {
        node1->next = node2_orig_next;
        node2_orig_next->prev = node1;
    }
}

void list_sort(list* l){
    node* curr = l->head->next;
    while(curr){
        node* orig_next = curr->next;
        node* temp = curr;
        while(temp){
            if(temp->prev && (temp->prev->data > temp->data)){
                list_swap(l, temp->prev, temp);
            } else {
                temp = temp->prev;
            }
        }
        curr = orig_next;
    }
}

#endif
