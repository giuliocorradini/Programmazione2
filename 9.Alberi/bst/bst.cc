#include "bst.h"
#include <stddef.h>
#include <cstring>

#include <iostream>
using namespace std;

int compare_key(bst_key_t a, bst_key_t b) {
    if(a > b)
        return 1;
    if(a < b)
        return -1;

    return 0;
}

void copy_key(bst_key_t &a, bst_key_t &b) {
    a = b;
}

void copy_inf(bst_inf_t &a, bst_inf_t &b) {
    int inf_dim = strlen(b);

    cout << inf_dim;
    a = new char[inf_dim + 1];

    strcpy(a, b);
}



bst_key_t &bst_getKey(bst_node_t *n) {
    return n->key;
}

bst_inf_t &bst_getInf(bst_node_t *n) {
    return n->inf;
}

bst_t &bst_getLeft(bst_node_t *n) {
    return n->left;
}

bst_t &bst_getRight(bst_node_t *n) {
    return n->right;
}



bst_node_t *bst_newNode(bst_key_t k, bst_inf_t i) {
    bst_node_t *node = new bst_node_t;
    
    copy_key(node->key, k);

    copy_inf(node->inf, i);

    node->left = nullptr;
    node->right = nullptr;
}


void bst_insert(bst_t &tree, bst_node_t *n) {
    bst_t &curr_subtree = tree;

    while(curr_subtree != nullptr) {
        if(compare_key(bst_getKey(tree), bst_getKey(n)) >= 0)
            curr_subtree = bst_getLeft(curr_subtree);

        else
            curr_subtree = bst_getLeft(curr_subtree);
    }

    curr_subtree = n;
}

void bst_delete(bst_t &tree, bst_node_t *n) {

}

bst_node_t *bst_search(bst_t &tree, bst_key_t key) {

}