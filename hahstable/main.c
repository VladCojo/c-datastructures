
#include "stdint.h"
#include "stdio.h"
#include "time.h"
#include "stdlib.h"
// Comentari utest
#define M_VAL 4
#define X_VAL 1000000

#define hash_a (uint32_t) 2654435769
#define hash_w 32
#define hash_m 3

uint32_t hashf_krlose(char *str) {
    uint32_t hash = 0;
    char c;
    while((c=*str++)) {
        printf("%c", c);
        hash+=c;
    } 
    return hash;
}


int main(){
    char* input[] = { "IJK", "HJL", "GJM", "FJN" };
    uint32_t i;
    printf("\n");
    hashf_krlose("buna");
    printf("\n");
    for(i = 0; i < 4; i++) {
        printf("%d\n", hashf_krlose(input[i]));
    }

    return 0;

}