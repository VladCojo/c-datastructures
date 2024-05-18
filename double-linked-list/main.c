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

node_t *create_node(int data);
void push(list_t **list, int data);
void append(list_t **list, int data);
void display(list_t **list);
node_t *delete(list_t **list, int data);



int main() {
    list_t *list = (list_t *) malloc(sizeof (list_t));
    push(&list, 10);
    push(&list, 12);
    append(&list, 9);
    append(&list, 12);
    push(&list, 23);
    display(&list);
    printf("Length: %d", (*list).length);


    return 0;
}

void display(list_t **list){
    if((*list)->head == NULL){
        printf("The list is empty\n");
        return;
    }
    node_t *tmp = (*list)->head;
    while(tmp){
        printf("%d ", tmp->data);
        tmp = tmp->next;
    }
    printf("\n");
}


void append(list_t **list, int data){
    node_t *newNode = create_node(data);

    if((*list)->head == NULL){
        (*list)->head = newNode;
        (*list)->tail = newNode;
    } else{
        (*list)->tail->next = newNode;
        newNode->prev = (*list)->tail;
        (*list)->tail = newNode;
    }
    (*list)->length++;
}


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

void push(list_t **list, int data){
    node_t *newNode = create_node(data);

    // Check if the list is empty
    if((*list)->head == NULL){
        (*list)->head = newNode;
        (*list)->tail = newNode;
    } else{
        newNode->next = (*list)->head;
        (*list)->head->prev = newNode;
        (*list)->head = newNode;
    }

    (*list)->length++;

}

