#include "stringa.h"

struct node {
    tipo_inf inf;
    node *parent;
    node *firstChild;
    node *nextSibling;
};
typedef struct node* tree;

node *new_node(tipo_inf i);

/*
 *  Aggiorna p inserendo il sottoalbero radicato in c come primo figlio di p
 *  Inserimento in testa
 */
void insert_child(tree p, tree c);

/*
 *  Aggiorna n inserendo il sottoalbero radicato in t come
 *  fratello successivo di n
 */
void insert_sibling(node *n, tree t);
