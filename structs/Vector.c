#include "../lib/headers/vector.h"
#include <stdio.h>
#include <stdlib.h>

enum {
    LEN = 10,
    CAPACITY = 10000
};

int
main(void) {
    Vector vector;
    int *data;
    data = calloc(CAPACITY, sizeof(*data));
    for (int i = 0; i < LEN; ++i) {
        data[i] = i;
    }
    vector.data = data;
    vector.size = LEN;
    vector.capacity = CAPACITY;
    v_erase(&vector, 9);
    for (int i = 0; i < vector.size; ++i) {
        printf("%d ", v_get(&vector, i));
    }
    printf("\n");
    return 0;
}
