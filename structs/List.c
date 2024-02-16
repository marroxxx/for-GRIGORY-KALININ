#include "../lib/headers/list.h"
#include <stdlib.h>
#include <stdio.h>

int
main(void) {
    L2 cop;
    cop.head = NULL;
    cop.tail = NULL;
    cop.size = 0;
    L2 *list = &cop;
    for (int i = 0; i < 20; ++i) {
        l2_push_back(list, i);
        l2_push_front(list, i);
    }
    for (int i = 0; i < 40; ++i) {
        l2_erase(list, 0);
    }
    l2_free(list);
    return 0;
}
