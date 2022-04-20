#include <iostream>
#include "albero.h"
using namespace std;

void serialize(tree t, ostream &out) {    
    cout << "(";
    
    if(t) {
        cout << t->inf;

        tree ch = t->firstChild;
        while(ch) {
            cout << " ";
            serialize(ch, out);
            ch = ch->nextSibling;
        }
    }

    cout << ")";
}

int altezza(tree t) {
    if(t == nullptr)
        return 0;

    if(t->firstChild == nullptr)
        return 0;
    
    int h_max = 0;
    for(tree child = t->firstChild; child != nullptr; child = child->nextSibling) {
        int child_h = altezza(child);
        if(child_h > h_max)
            h_max = child_h;
    }

    return h_max + 1;
}

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

    serialize(root, cout);
    cout << endl;

    cout << "Altezza: " << altezza(root);

    return 0;
}