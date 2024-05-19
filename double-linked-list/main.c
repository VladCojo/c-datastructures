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

void mergeSort(list_t **list);
node_t *merge(node_t* a, node_t *b);
void splitList(node_t *source, node_t **frontRef, node_t **backRef);




int main() {
    list_t *list = (list_t *) malloc(sizeof (list_t));
    push(&list, 10);
    push(&list, 155);
    append(&list, 9);
    append(&list, 12);
    push(&list, 23);
    display(&list);
    printf("Length: %d\n", list->length);
    mergeSort(&list);
    display(&list);
    return 0;
}
void splitList(node_t *source, node_t **frontRef, node_t **backRef){
    node_t *slow = source;
    node_t *fast = source->next;

    while(fast->next != NULL && fast->next->next != NULL){
        fast = fast->next->next;
        slow = slow->next;
    }
    (*frontRef) = source;
    (*backRef) = slow->next;
    slow->next = NULL;
    (*backRef)->prev = NULL;
}
node_t *merge(node_t *a, node_t *b){
    if(a == NULL){
        return b;
    } else if (b == NULL){
        return a;
    }

    if(a->data <= b->data){
        a->next = merge(a->next, b);
        if(a->next != NULL) a->next->prev = a;
        a->prev = NULL;
        return a;
    } else {
        b->next = merge(a, b->next);
        if(b->next != NULL) b->next->prev = b;
        b->prev = NULL;
        return b;
    }
}
void mergeSort(list_t **list){
    node_t *head = (*list)->head;
    node_t *a;
    node_t *b;


    if((head == NULL) || (head->next == NULL)){
        return;
    }

    splitList(head, &a, &b);
    list_t *leftList = (list_t *) malloc(sizeof (list_t));
    leftList->head = a;
    leftList->tail = NULL;
    leftList->length = 0;

    list_t *rightList = (list_t *) malloc(sizeof (list_t));
    rightList->head = b;
    rightList->tail = NULL;
    rightList->length = 0;

    mergeSort(&leftList);
    mergeSort(&rightList);

    (*list)->head = merge(leftList->head, rightList->head);
    // TODO: Update tail
    node_t *current = (*list)->head;
    while (current->next != NULL){
        current = current->next;
    }
    (*list)->tail = current;

}
node_t *pop_last(list_t **list){
    if((*list)->tail == NULL){
        printf("The list is empty");
        return NULL;
    }
    node_t *tmp = (*list)->tail;

    if(tmp->prev == NULL){
        (*list)->head = NULL;
        (*list)->tail = NULL;
        return tmp;
    }

    (*list)->tail = (*list)->tail->prev;
    (*list)->tail->next = NULL;
    tmp->prev = NULL;
    return tmp;
}

node_t *pop_first(list_t **list){
    if((*list)->head == NULL){
        printf("The list is empty;");
        return NULL;
    }
    node_t *tmp = (*list)->head;

    if((*list)->head->next == NULL){
        (*list)->head = NULL;
        (*list)->tail = NULL;
        return tmp;
    }
    (*list)->head = (*list)->head->next;
    (*list)->head->prev = NULL;
    return tmp;
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

