#include <iostream>
using namespace std;

/*
Si scriva la funzione int compare(persona, persona) che implementa la seguente
relazione d’ordine: compare(e1,e2)=0 se nome e id coincidono compare (e1,e2)<0
se il nome di e2 precede il nome di e2 e oppure coincidono e l’id di e1 è minore
dell’id di e2 compare(e1,e2)>0 altrimenti
*/

struct persona{
    char* nome;
    int id;
};

int compare(persona e1, persona e2) {
    if(e1.id == e2.id && strcmp(e1, e2) == 0)
        return 0;

    if(strcmp(e1, e2) <= 0 && e1.id < e2.id)
        return -1;

    return 1;
}

/*
Si assuma una lista ordinata di elementi di tipo persona. Scrivere il tipo di
dato elem (elemento della lista) e il tipo di dato lista (puntatore alla testa
della lista)
*/

struct elem {
    persona inf;
    struct elem *pun;
};

typedef struct elem *lista;

persona head(lista l) {
    return l->inf;
}

lista tail(lista l) {
    return l->pun;
}

/*
Scrivere la primitiva lista ord_insert_elem(lista,elem*) che aggiunge un
elemento ad una lista ordinata. La funzione deve usare la funzione compare
(punto a) e le primitive head e tail.
*/

lista ord_insert_elem(lista l, elem *e) {
    lista last = nullptr;
    lista curr = l;

    while(curr && compare(head(e), head(curr)) > 0) {
        last = curr;
        curr = tail(curr);
    }

    if(last != nullptr)
        last->pun = e;
    else
        l = e;
    
    e->pun = curr;

    return l;
}

/*
Scrivere la procedura ricorsiva diff(lista l1, lista l2) che stampa l’elenco
delle persone che sono presenti nella lista ordinata l1 ma non nella lista
ordinata l2. La procedura deve sfruttare l’ordinamento implementando un
algoritmo con complessità O(n).
*/

void diff(lista l1, lista l2) {
    while(l1) {

        while(compare(head(l1), head(l2)) > 0)
            l2 = tail(l2);

        if(compare(head(l1), head(l2)) < 0)
            cout << head(l1).nome;

        l1 = tail(l1);
    }
}

/*
Dato la seguente dichiarazione per un binary search tree (BST)
*/
struct bnode {
    persona key;
    bnode* left;
    bnode* right;
    bnode* parent;
};
typedef bnode* bst;
bst get_left(bst); //restituisce il sottoalbero sinistro
bst get_right(bst); //restituisce il sottoalbero destro

/*
Scrivere la procedura stampa_inv(bst) che stampa l’elenco delle persone in ordine
inverso (dal più grande al più piccolo). La procedura deve usare le primitive sopra definite.
*/

//navigo il BST con la ricorsione e faccio la stampa post-order

void stampa_inv(bst b) {
    if(b) {
        stampa_inv(get_right(b));
        stampa_inv(get_left(b));

        cout << b->key.nome << endl;
    }
}