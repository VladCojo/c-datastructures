#include <stdio.h>
#include "stdlib.h"


typedef struct node{
    int data;
    struct node *next;
}node_t;


node_t *create_node(int data){
    node_t *newNode = (node_t*) malloc(sizeof (node_t));

    if(newNode == NULL){
        printf("Memory allocated error");
        exit(1);
    }

    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}


node_t *append_node(node_t **head, int data){
    node_t *newNode = create_node(data);
    node_t *tmp = *head;

    while (tmp->next) {
        tmp = tmp->next;
    }
    tmp->next = newNode;
    return *head;
}

node_t *push_node(node_t **head, int data){
    node_t *newNode = create_node(data);
    newNode->next = *head;
    *head = newNode;
    return *head;
}

void display_data(node_t **head){
    node_t *tmp = *head;

    while (tmp){
        printf("%d ", tmp->data);
        tmp=tmp->next;
    }
}


int main() {
    node_t *head = create_node(20);
    append_node(&head, 10);
    push_node(&head, 30);
    display_data(&head);


    return 0;
}
