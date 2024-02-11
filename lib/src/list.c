#include "../headers/list.h"
#include <stdlib.h>
#include <stdio.h>

List * 
l_init(List *list, int elem) { //works
    list = calloc(1, sizeof(*list));
    list->data = elem;
    list->next = NULL;
    return list;
}

List *
l_push_back(List *list, int elem) { //works
    List *new_list = list;
    while (1) {
        if (new_list->next == NULL) {
            List *push_list;
            push_list = calloc(1, sizeof(*push_list));
            push_list->data = elem;
            push_list->next = NULL;
            new_list->next = push_list;
            break;
        }       
        new_list = new_list->next;
    }
    return list;
}

List *
l_insert(List *list, int elem, int pos) { //works without pos == 0
    List *new_list = calloc(1, sizeof(*new_list));
    if (pos < 0 || list == NULL) {
        return NULL;
    }
    if (pos == 0) { //not works :(
        new_list->data = elem;
        new_list->next = list;
        return new_list;
    }
    new_list = list;
    for (int i = 0; i < pos - 1; ++i) {
        if (new_list == NULL) {
            return NULL;
        }
        new_list = new_list->next;
    }
    List *new_elem = calloc(1, sizeof(*new_elem));
    new_elem->data = elem;
    List *temp = new_list->next;
    new_list->next = new_elem;
    new_elem->next = temp;
    return list;
} 

List *
l_erase(List *list, int pos) { //works
    if (pos < 0 || list == NULL) {
        return NULL;
    }
    if (pos == 0) { 
        List *new_list = list->next;
        free(list);
        return new_list;
    }
    List *new_list = list;
    for (int i = 0; i < pos - 1; ++i) {
        if (new_list->next == NULL) {
            return NULL;
        }
        new_list = new_list->next;
    }
    List *del_list = new_list->next;
    new_list->next = new_list->next->next;
    free(del_list);
    return list;
}

List *
l_update(List *list, int elem, int pos) { //works
    List *new_list = list;
    if (pos < 0 || list == NULL) {
        exit(1);
    }
    if (pos == 0) {
        new_list->data = elem;
        return list;
    } else {
        for (int i = 0; i < pos; ++i) {
            new_list = new_list->next;
            if (new_list == NULL) {
                exit(1);
            }
        }
        new_list->data = elem;
    }
    return list;
}

int
l_get(List *list, int pos) { //works
    List *new_list = list;
    if (pos < 0 || list == NULL) {
        exit(1);
    }
    if (pos == 0) {
        return list->data;
    } else {
        for (int i = 0; i < pos; ++i) {
            new_list = new_list->next;
            if (new_list == NULL) {
                exit(1);
            }
        }
        return new_list->data;
    }
}

List *
l_find(List *list, int elem) { //works
    List *new_list = list;
    while (1) {
        if (new_list == NULL) {
            return NULL;
        }
        if (new_list->data == elem) {
            return new_list;
        }
        new_list = new_list->next;
    }
}

void 
l_printf(List *list) { //works
    List *new_list = list;
    while (1) {
        if (new_list == NULL) {
            break;
        } else {
            printf("%d ", new_list->data);
        }
        new_list = new_list->next;
    }
    printf("\n");
}

void 
l_free(List *list) { 
    List *new_list = list->next;
    while (1) {
        if (new_list == NULL) {
            break;   
        }
        free(list);
        list = new_list;
        new_list = new_list->next;
    }
}

void
l2_push_back(L2 *list, int elem) {
    if (list == NULL) {
        fprintf(stderr, "l2 push_back: list is NULL\n");
        fflush(stderr);
        exit(1);
    }
    if (list->size == 0) {
        list->head = calloc(1, sizeof(*list->head));
        list->head->data = elem;
        list->head->next = NULL;
        list->head->prev = NULL;
        list->tail = list->head;
        list->size++;
    } else {
        list->tail->next = calloc(1, sizeof(*list->tail->next));
        list->tail->next->data = elem;
        list->tail->next->next = NULL;
        list->tail->next->prev = list->tail;
        list->tail = list->tail->next;
        list->size++;
    }
}

void
l2_push_front(L2 *list, int elem) {
    if (list == NULL) {
        fprintf(stderr, "l2 push_front: list is NULL\n");
        fflush(stderr);
        exit(1);
    }
    if (list->size == 0) {
        list->head = calloc(1, sizeof(*list->head));
        list->head->data = elem;
        list->head->next = NULL;
        list->head->prev = NULL;
        list->tail = list->head;
        list->size++;
    } else {
        list->head->prev = calloc(1, sizeof(*list->tail->next));
        list->head->prev->data = elem;
        list->head->prev->prev = NULL;
        list->head->prev->next = list->tail;
        list->head = list->head->prev;
        list->size++;
    }

}
