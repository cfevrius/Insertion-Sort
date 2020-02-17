#ifndef NODE_H
#define NODE_H 

typedef struct node node;
struct node {
    int data;
    node* next;
    node* prev;
};

node* node_create(int x);
void  node_destroy(node* n);

#endif
