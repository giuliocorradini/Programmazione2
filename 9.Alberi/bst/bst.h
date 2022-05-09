#pragma once

//
// Contenuto informativo del nodo
//

typedef int bst_key_t;
typedef char * bst_inf_t;

int compare_key(bst_key_t a, bst_key_t b);
void copy_key(bst_key_t &a, bst_key_t &b);


//
//  Gestione e accesso del nodo
//

struct bst_node_t {
    bst_key_t   key;
    bst_inf_t   inf;
    bst_node_t *left;
    bst_node_t *right;
};
typedef bst_node_t * bst_t;

bst_node_t* bst_newNode(bst_key_t, bst_inf_t);
bst_key_t &bst_getKey(bst_node_t *);
bst_inf_t &bst_getInf(bst_node_t *);
bst_t &bst_getLeft(bst_node_t *);
bst_t &bst_getRight(bst_node_t *);


void bst_insert(bst_t&, bst_node_t*);
void bst_delete(bst_t&, bst_node_t*);
bst_node_t *bst_search(bst_t&, bst_key_t);