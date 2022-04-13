#include <iostream>
#include "albero.h"
using namespace std;

void print_tree(tree t) {
    #ifdef DEBUG
    if(t == nullptr)
        return;

    cout << t->inf << endl << endl;
    
    tree c = t->firstChild;
    while(c) {
        print_tree(c);
        c = c->nextSibling;
    }
    #endif
}

int main() {
    tree root;
    
    // Crea l'albero
    root = new_node("Luca");

    // Creiamo i figli
    node *paolo = new_node("Paolo");

    node *marco = new_node("Marco");
    node *lucia = new_node("Lucia");
    insert_child(marco, lucia);

    node *anna = new_node("Anna");

    // Inseriamo i figli a partire dalla radice
    insert_child(root, anna);
    insert_child(root, marco);
    insert_child(root, paolo);

    print_tree(root);

    return 0;
}