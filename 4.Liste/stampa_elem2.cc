#include <iostream>
using namespace std;

typedef struct elem {
    int inf;
    struct elem *pun;
};
typedef elem* lista;

int head(lista l) {
    return l->inf;
}

lista tail(lista l) {
    return l->pun;
}

void stampa_lista(lista l) {
    while(l != nullptr) {
        cout << head(l) << " ";
        l = tail(l);
    }

    cout << endl;
}

int main() {
    lista ll;

    elem *a = new elem;
    a->inf = 3;

    elem *b = new elem;
    b->inf = 7;

    a->pun = b;
    b->pun = nullptr;

    ll = a;

    stampa_lista(ll);

    return 0;
}