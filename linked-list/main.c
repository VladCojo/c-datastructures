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
        return;
    }

    node_t *tmp = (*list)->head;

    while (tmp->next) {
        tmp = tmp->next;
    }
    tmp->next = newNode;

}

void push_node(list **list, int data){
    node_t *newNode = create_node(data);
    newNode->next = (*list)->head;
    (*list)->head = newNode;

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

void delete_node(list **list, int data){
    if((*list)->head == NULL){
        printf("The list is empty");
        return;
    }

    node_t *tmp = (*list)->head;

    while (tmp->next->data != data){
        tmp = tmp->next;
    }

    if(tmp->next == NULL){
        printf("The node does not exist");
    }

    node_t *del = tmp->next;
    tmp->next=tmp->next->next;
    del->next = NULL;


}

int main() {
    list *myList = (list *)malloc(sizeof(list));
    display_data(&myList);


    for(int i = 0; i <= 20; i ++){
        append_node(&myList, i);
    }

    display_data(&myList);
    printf("\n");
    delete_node(&myList, 19);
    display_data(&myList);

    return 0;
}
