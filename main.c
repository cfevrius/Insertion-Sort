#include <stdio.h>
#include <stdlib.h>

#include "list.h"

int main(){
    int data_to_sort[]  = { 34, 23, 22, 8, 50, 74, 2, 1, 17, 40 };
    int node_elements = 10;

    /* Load elements in the array and add them to a linked list */
    list* l = list_create();
    for(int i = 0; i < node_elements; i++){
        list_append(l, data_to_sort[i]);
    }
    list_display(l);
    l = list_destroy(l);
    return 0;
}

