#include "../lib/headers/tree.h"
#include <stdio.h>
#include <stdlib.h>

int
main(void) {
    BSTree *tree = calloc(1, sizeof(*tree));
    tree->root = NULL;
    bst_insert(tree, 1);
    bst_insert(tree, 3);
    bst_insert(tree, 2);
    bst_insert(tree, 6);
    bst_insert(tree, -8);
    bst_insert(tree, -8);
    bst_erase(tree, 6);
    Vector vector = bst_to_vector(tree);
    for (int i = 0; i < vector.size; ++i) {
        printf("%d ", vector.data[i]);
    }   
    printf("\n");
    return 0;
}
