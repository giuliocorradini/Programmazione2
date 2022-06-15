#include <iostream>
using namespace std;

struct elem {
    int v;
    elem* pun;
};
typedef elem* lista;

int head(lista l) {
    return l->v;
}

lista tail(lista l) {
    return l->pun;
}

lista split(lista &l) {
    lista l1 = nullptr;
    elem *l1_tail = nullptr;

    lista curr = l;
    lista last = nullptr;

    while(curr) {
        if(head(curr) % 2 == 0) {
            //extract element from list
            if(last != nullptr)
                last->pun = curr->  pun;
            curr->pun = nullptr;

            //element is now in curr
            if(l1 == nullptr) {
                l1 = curr;
            } else {
                l1_tail->pun = curr;
            }
            l1_tail = curr;

            curr = last;
        }

        last = curr;
        curr = tail(curr);
    }

    return l1;
}

elem *new_element(int v) {
    elem *e = new elem;
    e->v = v;
    e->pun = nullptr;

    return e;
}

int main() {
    lista l = nullptr;
    elem *e;

    //inizializza la lista in qualche modo
    for(int i=5; i>0; i--) {
        if(l==nullptr) {
            l = new_element(i);
        } else {
            e = new_element(i);
            e->pun = l;
            l = e;
        }
    }

    lista l1 = split(l);

    //stampa l1
    while(l1) {
        cout << head(l1) << endl;

        l1 = tail(l1);
    }
}