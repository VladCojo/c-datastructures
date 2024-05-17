#include <stdio.h>
#include "stdlib.h"


typedef struct node{
    int data;
    struct node *next;
}node_t;

typedef struct {
    int length;
    node_t *head;
    node_t *tail;
}list;


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


void append_node(list **list, int data){
    node_t *newNode = create_node(data);

    if((*list)->head == NULL){
        (*list)->head = newNode;
        (*list)->tail = newNode;
    }else {
        (*list)->tail->next = newNode;
        (*list)->tail = newNode;
    }
    (*list)->length++;
}

void push_node(list **list, int data){
    node_t *newNode = create_node(data);

    if((*list)->head == NULL) {
        (*list)->head = newNode;
        (*list)->tail = newNode;
    } else {
        newNode->next = (*list)->head;
        (*list)->head = newNode;
    }
    (*list)->length++;
}

void display_data(list **list){
    if((*list)->head == NULL){
        printf("The list is empty\n");
        return;
    }

    node_t *tmp = (*list)->head;

    while (tmp){
        printf("%d ", tmp->data);
        tmp=tmp->next;
    }
}

node_t *delete_node(list **list, int data){
    // Check if the list is empty
    if((*list)->head == NULL){
        printf("The list is empty\n");
        return NULL;
    }

    node_t *tmp = (*list)->head;
    node_t *prev = NULL;


    // Check if the node is the head
    if(tmp->data == data){
        (*list)->head = tmp->next;
        // Check if the deleted node is the only node in the list
        if((*list)->head == NULL){
            (*list)->tail = NULL;
            printf("You have deleted the only node");
            (*list)->length--;
            return tmp;
        }
    }

    while (tmp != NULL && tmp->data != data ){
        prev = tmp;
        tmp = tmp->next;
    }

    if(tmp == NULL){
        printf("The node has not been found\n");
        return NULL;
    }

    prev->next = tmp->next;

    if(prev->next == NULL){
        (*list)->tail = prev;
    }

    tmp->next = NULL;
    (*list)->length--;

    return tmp;


}





int main() {
    list *myList = (list *)malloc(sizeof(list));
    push_node(&myList, 20);
    delete_node(&myList, 20);

    return 0;
}
