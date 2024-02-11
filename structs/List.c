#include "../lib/headers/list.h"
#include <stdlib.h>
#include <stdio.h>

int
main(void) {
    List *list = NULL;
    list = l_init(list, 1);
    list = l_push_back(list, 2);
    list = l_insert(list, 22, 2);
    list = l_erase(list, 0);
    l_printf(list);
    l_free(list);
    return 0;
}
