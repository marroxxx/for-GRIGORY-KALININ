#include "../lib/headers/hash.h"
#include <stdlib.h>
#include <stdio.h>

enum {
    MAX_LEN = 10000
}; 

unsigned short
f(char *str) {
    return 0;
}

int 
main(void) {
    char *s;
    s = calloc(MAX_LEN, sizeof(*s));
    fgets(s, MAX_LEN, stdin);
    HashTable hash_table;
    hash_table.hash = f;
    hs_insert(&hash_table, s);
    printf("%s\n", hash_table.arr[0].head->data);
    return 0;
}   
