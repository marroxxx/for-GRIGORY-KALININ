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
    char *st;
    st = calloc(MAX_LEN, sizeof(*st));
    fgets(st, MAX_LEN, stdin);
    hs_insert(&hash_table, st);
    hs_insert(&hash_table, st);
    l2s_printf(&hash_table.arr[0]);
    l2s_free(&hash_table.arr[0]);
    return 0;
}   
