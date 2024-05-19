#include <stdio.h>
#include "stdlib.h"
#include "string.h"
// size of hash table
#define CAPACITY 5000

typedef struct item{
    char* key;
    char* value;
}item;

typedef struct hashtable{
    item **items;
    int size;
    int count;
}hashtable;

unsigned long hash_function(char *str){
    unsigned long i = 0;

    for(int j = 0; str[j]; j++){
        i += str[j];
    }
    return i % CAPACITY;
}

item *create_item(char *key, char *val){
    item *newItem = (item*) malloc(sizeof (item));
    newItem->key = (char*) malloc(strlen(key)+1);
    newItem->value = (char*) malloc(strlen(val)+1);
    strcpy(newItem->value, val);
    strcpy(newItem->key, key);
    return newItem;
}

hashtable *create_hashtable(int size){
    hashtable *newHashtable = (hashtable*) malloc(sizeof (hashtable));
    newHashtable->size = size;
    newHashtable->count = 0;
    newHashtable->items = (item**) calloc(newHashtable->size, sizeof(item*));
    for(int i = 0; i < newHashtable->size; i++){
        newHashtable->items[i]= NULL;
    }
    return newHashtable;
}

void printTable(hashtable *table){
    printf("Hash table: \n");
    for(int i = 0; i < table->size; i ++){
        if(table->items[i]){
            printf("index: %d, key: %s, value: %s\n", i, table->items[i]->key, table->items[i]->value);
        }
    }
}
void insert(hashtable* table, char* key, char* value){
    item *newItem = create_item(key, value);
    int index = hash_function(key);
    
}
int main() {
    char *str = "vali";
    printf("hash value of '%s': %lu", str, hash_function(str));
    return 0;
}
