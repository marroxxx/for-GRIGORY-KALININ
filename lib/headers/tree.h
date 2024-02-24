#ifndef TREE_H
#define TREE_H

#include "vector.h"

typedef struct TreeNode {
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
    struct TreeNode *parent;
} TreeNode;

typedef struct Tree {
    TreeNode *root;
} Tree;

typedef Tree Heap;
typedef Tree BSTree;

extern void swap(void *a, void *b);
extern void heap_insert(Heap *heap, int elem); 
extern void heap_erase_root(Heap *heap);
extern void heap_make(TreeNode *node);
extern void bst_insert(BSTree *tree, int elem);
extern void bst_erase(BSTree *tree, int elem);
extern void transplant(BSTree *tree, TreeNode *old, TreeNode *new);
extern TreeNode* min_node(TreeNode *node);
extern void recurse_vector(TreeNode *node, Vector *vector);
extern int bst_find(BSTree *tree, int elem);
extern Vector bst_to_vector(BSTree *tree);

#endif
