#include "../headers/lists.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

enum {
    SIZE = 10000
};

void 
l2s_push_front(L2S *list, char *elem) { 
    if (list == NULL) { 
        fprintf(stderr, "l2s_push_front: list is NULL"); 
        fflush(stderr); 
        exit(1); 
    } 
    if (list->size == 0) { 
        list->head = calloc(strlen(elem), sizeof(*list->head)); 
        list->head->data = elem; 
        list->head->next = NULL; 
        list->head->prev = NULL; 
        list->tail = list->head; 
        list->size++; 
    } else { 
        list->head->prev = calloc(strlen(elem), sizeof(*list->head)); 
        list->head->prev->data = elem; 
        list->head->prev->prev = NULL; 
        list->head->prev->next = list->head; 
        list->head = list->head->prev; 
        list->size++; 
    } 
} 
 
void 
l2s_push_back(L2S *list, char *elem) { 
    if (list == NULL) { 
        fprintf(stderr, "l2s_push_back: list is NULL"); 
        fflush(stderr); 
        exit(1); 
    } 
    if (list->size == 0) { 
        list->head = calloc(strlen(elem), sizeof(list->head)); 
        list->head->data = elem; 
        list->head->next = NULL; 
        list->head->prev = NULL; 
        list->tail = list->head; 
        list->size++; 
    } else { 
        list->tail->next = calloc(strlen(elem), sizeof(list->head)); 
        list->tail->next->data = elem; 
        list->tail->next->next = NULL; 
        list->tail->next->prev = list->tail; 
        list->tail = list->tail->next; 
        list->size++; 
    } 
}


void
l2s_printf(L2S *list) {
    L2SNode *node = list->head;  
    while (node != NULL) {
        printf("%s ", node->data);
        node = node->next;
    }
    printf("\n");
}

void 
l2s_insert(L2S *list, int pos, char *elem) {
    if (pos < 0 || list == NULL || pos > list->size) {
        fprintf(stderr, "l2s_insert error\n");
        fflush(stderr);
        exit(1);
    }  
    if (pos == list->size) {
        l2s_push_back(list, elem);
        return;
    } else if (pos == 0) {
        l2s_push_front(list, elem);
        return;
    }
    if (pos <= list->size / 2) {
        L2SNode *node = list->head;
        for (int i = 0; i < pos - 1; ++i) {
            node = node->next;
        }      
        L2SNode *new_node = calloc(1, sizeof(*new_node));
        new_node->data = elem;
        L2SNode *temp = node->next;
        node->next = new_node;
        new_node->next = temp;
        new_node->prev = node;
    } else {
        L2SNode *node = list->tail;
        for (int i = list->size - 1; i >= pos; --i) {
            node = node->prev;
        }
        L2SNode *new = calloc(1, sizeof(*new));
        new->data = elem;
        L2SNode *temp = node->next;
        node->next = new;
        new->next = temp;
        new->prev = node;
    }
    list->size++;
}

void 
l2s_erase(L2S *list, int pos) {
    if (pos < 0 || list == NULL || pos >= list->size || list->size == 0) {
        fprintf(stderr, "l2s_erase error\n");
        fflush(stderr);
        exit(1);
    }
    if (pos == 0) {
        L2SNode *node = list->head;
        list->head = list->head->next;
        list->head->prev = NULL;
        free(node); 
        list->size--;
        return;
    } else if (pos == list->size - 1) {
        L2SNode *node = list->tail;
        list->tail = list->tail->prev;
        list->tail->next = NULL;
        list->size--;
        free(node);
        return;    
    } 
    
    L2SNode *node = list->head;
    for (int i = 0; i < pos - 1; ++i) {
        node = node->next;
    }
    L2SNode *del_node = node->next;
    node->next = node->next->next;
    node->next->prev = node;
    list->size--;
    free(del_node);
}

void
l2s_update(L2S *list, int pos, char *elem) {
    L2SNode *copy = list->head;
    if (pos < 0 || list->head == NULL || pos >= list->size) {
        fprintf(stderr, "l2s_update pos < 0 or list == NULL\n");
        fflush(stderr);
        exit(1);
    }
    for (int i = 0; i < pos; ++i) {
        if (copy == NULL) {
            fprintf(stderr, "l2s_update pos > size");
            fflush(stderr);
            exit(1);
        }
        copy = copy->next;
    }
    copy->data = elem;
}

int
l2s_find(L2S *list, char *elem) {
    if (list == NULL) {
        fprintf(stderr, "l2s_find error\n");
        fflush(stderr);
        exit(1);
    }
    int pos = 0;
    L2SNode *node = list->head;
    while (node != NULL) {
        if (strcmp(node->data, elem) == 0) {
            return pos;
        }
        ++pos;
        node = node->next;
    }
    return -1;
}

void
l2s_free(L2S *list) {
    L2S *copy = list;
    while (1) {
        if (list->head == NULL) {
            break;
        } 
        copy->head = copy->head->next;
        free(list->head);
    }
}

char *
l2s_get(L2S *list, int pos) {
    if (pos == 0 || list == NULL || pos >= list->size) {
        fprintf(stderr, "l2s_get err\n");
        fflush(stderr);
        exit(1);
    }
    L2SNode *node = list->head;
    for (int i = 0; i < pos; ++i) {
        node = node->next;
    }
    return node->data;
}
