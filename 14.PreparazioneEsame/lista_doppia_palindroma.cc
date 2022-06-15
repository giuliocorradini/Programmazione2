#include <iostream>
using namespace std;


struct elem {
    int inf;
    elem* pun;
    elem *prev;
};
typedef elem* lista;

int head(lista l) {
    return l->inf;
}

lista tail(lista l) {
    return l->pun;
}


bool palindroma(lista l) {

    //troviamo la coda della lista
    lista coda = l;
    while(coda && tail(coda)) { //scorre fino al penultimo elemento e gestisce anche le liste vuote
        coda = tail(coda);      //(condizione "coda")
    }

    while(l != coda && l->prev != coda) {
        if(l->inf != coda->inf) {
            return false;
        }

        l = tail(l);
        coda = coda->prev;
    }

    return true;
}

elem *new_element(int v) {
    elem *e = new elem;
    e->inf = v;
    e->pun = nullptr;
    e->prev = nullptr;

    return e;
}

int main() {
    lista l = nullptr;
    elem *e;

    //inizializza la lista in qualche modo
    e = new_element(1);
    l = e;

    e = new_element(4);
    l->prev = e;
    e->pun = l;
    l=e;

    e = new_element(2);
    l->prev = e;
    e->pun = l;
    l=e;

    e = new_element(1);
    l->prev = e;
    e->pun = l;
    l=e;
    
    /*e = new_element(1);
    l->prev = e;
    e->pun = l;
    l=e;*/

    cout << palindroma(l);
}