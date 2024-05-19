#include <stdio.h>
#include "stdlib.h"
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

int main() {
    char *str = "vali";
    printf("hash value of '%s': %lu", str, hash_function(str));
    return 0;
}
