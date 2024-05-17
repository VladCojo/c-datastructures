#include <stdio.h>
#include "stdlib.h"


typedef struct node{
    int data;
    struct node* next;
    struct node* prev;
}node_t;

typedef struct list{
    node_t *head;
    node_t *tail;
    int length;
}list_t;

node_t *create_node(int data){
    node_t *newNode = (node_t *) malloc(sizeof (node_t));

    if(newNode == NULL){
        printf("Memory allocation failed");
        exit(1);
    }

    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}







int main() {
    printf("Hello, World!\n");
    return 0;
}
