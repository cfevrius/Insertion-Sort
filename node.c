#ifndef NODE_C
#define NODE_C

#include <stdlib.h>
#include "node.h"

node* node_create(int x){
    node* n = calloc(1, sizeof(node));
    n->data = x;
    return n;
}

void node_destroy(node* n){
    free(n);
}

#endif
