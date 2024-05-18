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
node_t *delete_node(list_t **list, int data);
node_t *pop_first(list_t **list);
node_t *pop_last(list_t **list);

// TODO: termina alea de mai sus

int main() {
    list_t *list = (list_t *) malloc(sizeof (list_t));
    push(&list, 10);
    push(&list, 155);
    append(&list, 9);
    append(&list, 12);
    push(&list, 23);
    display(&list);
    printf("Length: %d\n", list->length);
    delete_node(&list, 23);
    display(&list);
    printf("Length: %d\n", list->length);


    return 0;
}

node_t *delete_node(list_t **list, int data){
    // check if list is empty
    if((*list)->head == NULL){
        printf("Cannot delete node because list is null\n");
        return NULL;
    }

    node_t *tmp = (*list)->head;

    // check if we have to delete the first node
   if(tmp->data == data){
       (*list)->head = tmp->next;
       if((*list)->head != NULL){
           (*list)->head->prev = NULL;
       } else {
           (*list)->tail = NULL;
       }
       tmp->next = NULL;
       (*list)->length--;
       return tmp;
   }
    // traverse the list until we find the node or get to the end of the list
    while (tmp && tmp->data != data){
        tmp = tmp->next;
    }

    // check if the node doesn't exist
    if(tmp == NULL){
        printf("The node doesn't exist\n");
        return NULL;
    }

    // check if the node is the tail
    if(tmp == (*list)->tail){
        (*list)->tail = tmp->prev;
        (*list)->tail->next = NULL;
        (*list)->length--;
        return tmp;
    }

    // delete node
    node_t *prev = tmp->prev;
    prev->next = tmp->next;
    tmp->next = NULL;
    (*list)->length--;
    return tmp;

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

