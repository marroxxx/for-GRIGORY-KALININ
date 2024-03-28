#include "../lib/headers/lists.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum {
    MAX_LEN = 1000
};

int
main(void) {
    char *string;
    string = calloc(MAX_LEN, sizeof(string));
    scanf("%s", string);
    L2S list;
    list.head = NULL;
    list.tail = NULL;
    list.size = 0;
    char *s;
    s = calloc(MAX_LEN, sizeof(s));
    scanf("%s", s);
    l2s_push_back(&list, s);
    l2s_push_back(&list, string);
    l2s_printf(&list);
    int pos = l2s_find(&list, s);
    printf("%d\n", pos);
    l2s_erase(&list, pos);
    l2s_printf(&list);
    l2s_free(&list);
    return 0;
}
