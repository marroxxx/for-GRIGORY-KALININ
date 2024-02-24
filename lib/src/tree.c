#include "../headers/tree.h"
#include <stdlib.h>
#include <stdio.h>

void
heap_insert(Heap *heap, int elem) {
    if (heap->root == NULL) {
        heap->root = calloc(1, sizeof(heap->root));
        heap->root->data = elem;
        heap->root->left = NULL;
        heap->root->right = NULL;
        heap->root->parent = NULL; 
    } else {
        TreeNode *node = heap->root;
        TreeNode *new_node = calloc(1, sizeof(*new_node));
        new_node->data = elem;
        new_node->parent = NULL;
        new_node->left = NULL;
        new_node->right = NULL;
        while (1) {
            if (elem < node->data) {
                if (node->left == NULL) {
                    node->left = new_node;
                    new_node->parent = node;
                    break;
                }
                node = node->left;
            } else {
                if (node->right == NULL) {
                    node->right = new_node;
                    new_node->parent = node;
                    break;
                }
                node = node->right;
            }
        }
    }
}

void
swap(void *a, void *b) {
    void *temp = a;
    a = b;
    b = temp;
}

void 
heap_make(TreeNode *node) {
    TreeNode *smallest = node;
    TreeNode *left = node->left;
    TreeNode *right = node->right;
    if (left != NULL && left->data < smallest->data)
        smallest = left;
    if (right != NULL && right->data < smallest->data)
        smallest = right;
    if (smallest != node) {
        swap(&(node->data), &(smallest->data));
        heap_make(smallest);
    }
}

void 
erase_heap_root(Tree *tree) {
    if (tree->root == NULL) {
        return;
    }
    TreeNode *last_node = tree->root;
    while (last_node->left != NULL || last_node->right != NULL) {
        if (last_node->right != NULL) {
            last_node = last_node->right;
        }
        else {
            last_node = last_node->left;
        }
    }
    tree->root->data = last_node->data;
    if (last_node->parent->left == last_node)
        last_node->parent->left = NULL;
    else
        last_node->parent->right = NULL;
    free(last_node);
    heap_make(tree->root);
}

void
bst_insert(BSTree *tree, int elem) {
    TreeNode *new_node = calloc(1, sizeof(*new_node));
    new_node->data = elem;
    new_node->parent = NULL;
    new_node->left = NULL;
    new_node->right = NULL;
    if (tree->root == NULL) {
        tree->root = new_node;
        return; 
    }
    TreeNode *cur = tree->root;
    TreeNode *parent = NULL;
    while (cur != NULL) {
        parent = cur;
        if (elem < cur->data) {
            cur = cur->left;
        } else {
            cur = cur->right;
        }
    }
    new_node->parent = parent;
    if (elem < parent->data) {
        parent->left = new_node;
    } else {
        parent->right = new_node;
    }
}

int 
bst_find(BSTree *tree, int elem) {
    TreeNode *current = tree->root;

    while (current != NULL) {
        if (current->data == elem) {
            return 1;
        } else if (current->data < elem) {
            current = current->right;
        } else {
            current = current->left;
        }
    }
    return 0;
}


void 
transplant(BSTree *tree, TreeNode *old, TreeNode *new) {
    if (old->parent == NULL) {
        tree->root = new;
    } else if (old == old->parent->left) {
        old->parent->left = new;
    } else {
        old->parent->right = new;
    }
    if (new != NULL) {
        new->parent = old->parent;
    }
}


TreeNode* 
min_node(TreeNode *node) {
    while (node->left != NULL) {
        node = node->left;
    }
    return node;
}


void 
bst_erase(BSTree *tree, int elem) {
    TreeNode *current = tree->root;
    int check = 0;
    while (current != NULL) {
        if (current->data == elem) {
            check = 1;
            break;
        } else if (current->data < elem) {
            current = current->right;
        } else {
            current = current->left;
        }
    }
    if (check == 0) {
        fprintf(stderr, "bst_erase: tree doesn't contain elem\n");
        fflush(stderr);
        exit(1);
    }
    if (current->left == NULL) {
        transplant(tree, current, current->right);
    } else if (current->right == NULL) {
        transplant(tree, current, current->left);
    } else {
        TreeNode *new_node = min_node(current->right);
        if (new_node->parent != current) {
            transplant(tree, new_node, new_node->right);
            new_node->right = current->right;
            new_node->right->parent = new_node;
        }
        transplant(tree, current, new_node);
        new_node->left = current->left;
        new_node->left->parent = new_node;
    }
    free(current);
}


void 
recurse_vector(TreeNode *node, Vector *vector) {
    if (node == NULL) {
        return;
    }
    recurse_vector(node->left, vector);
    v_push_back(vector, node->data);
    recurse_vector(node->right, vector);
}


Vector bst_to_vector(BSTree *tree) {
    Vector vector;
    vector.size = 0;
    vector.capacity = 10000;
    vector.data = calloc(1, sizeof(vector.data));
    recurse_vector(tree->root, &vector);
    return vector;
}
