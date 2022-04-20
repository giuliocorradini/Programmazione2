#include "albero.h"
#include <cstddef>

node *new_node(tipo_inf i) {
    node *n = new node;

    copy(n->inf, i);
    n->parent = nullptr;
    n->firstChild = nullptr;
    n->nextSibling = nullptr;
    
    return n;
}

void insert_child(tree p, tree c) {
    node *p_children = p->firstChild;

    p->firstChild = c;
    c->parent = p;
    
    c->nextSibling = p_children;
}

void insert_sibling(node *n, tree t) {
    node *n_siblings = n->nextSibling;

    n->nextSibling = t;
    t->nextSibling = n_siblings;

    t->parent = n->parent;
}
