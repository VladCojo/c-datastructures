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


node_t *create_node(int data);
void display_data(list **list);
void append_node(list **list, int data);
void push_node(list **list, int data);
node_t *delete_node(list **list, int data);

node_t *merge(node_t *a, node_t *b);
void mergeSort(list **lst);
void splitList(node_t *source, node_t **frontRef, node_t **backRef);



int main() {
    list* myList = (list*)malloc(sizeof(list));
    myList->length = 0;
    myList->head = NULL;
    myList->tail = NULL;

    push_node(&myList, 5);
    append_node(&myList, 3);
    append_node(&myList, 20);
    append_node(&myList, 15);
    append_node(&myList, 10);

    printf("Unsorted List:\n");
    display_data(&myList);
    printf("\n");

    mergeSort(&myList);

    printf("Sorted List:\n");
    display_data(&myList);
    printf("\n");

    return 0;
}

node_t *merge(node_t *a, node_t *b){
    node_t *result = NULL;

    if(a == NULL){
        return b;
    } else if(b == NULL) {
        return a;
    }

    if(a->data <= b->data){
        result = a;
        result->next = merge(a->next, b);
    } else {
        result = b;
        result->next = merge(a, b->next);
    }
    return result;
}

void mergeSort(list **lst){
    node_t *head = (*lst)->head;
    node_t *a;
    node_t *b;

    if((head == NULL) || (head->next == NULL)){
        return;
    }

    splitList(head, &a, &b);
    list *leftList = (list*) malloc(sizeof (list));
    leftList->head = a;
    leftList->length = 0;
    leftList->tail = NULL;

    list *rightList=(list*) malloc(sizeof (list));
    rightList->head = b;
    rightList->length = 0;
    leftList->tail = NULL;

    mergeSort(&leftList);
    mergeSort(&rightList);

    (*lst)->head = merge(leftList->head, rightList->head);

    // Updating the tail
    node_t *current = (*lst)->head;
    while (current->next != NULL){
        current = current->next;
    }
    (*lst)->tail = current;



}


void splitList(node_t *source, node_t **frontRef, node_t **backRef){
    node_t *fast;
    node_t *slow;
    slow = source;
    fast = source->next;

    while (fast->next != NULL && fast->next->next != NULL){
       fast = fast->next->next;
       slow = slow->next;
    }

    *frontRef = source;
    *backRef = slow->next;

    slow->next = NULL;
}

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