#include <iostream>
#include "bst.h"

//TODO: da completare

using namespace std;

int main() {
    bst_t bst = nullptr;

    bst_node_t *pippo = bst_newNode(2, "pippo");
    bst_node_t *pluto = bst_newNode(5, "pluto");
    bst_node_t *paperino = bst_newNode(4, "paperino");

    bst_insert(bst, pippo);
    bst_insert(bst, pluto);
    //bst_insert(bst, paperino);

    return 0;
}