#include <iostream>
using namespace std;

struct elem {
    int inf;
    struct elem *pun;
};
typedef struct elem * lista;

int head(lista l) {
    return l->inf;
}

lista tail(lista l) {
    return l->pun;
}

/* Stampa la lista */
void print_list(lista l) {
    while(l != nullptr) {
        cout << head(l) << " ";
        l = tail(l);
    }

    cout << endl;
}

/* Inserisci un elemento in testa alla lista */
lista insert_elem(lista l, elem *e) {
    e->pun = l;
    return e;
}

/* Crea una lista usando insert_elem */
lista create_list(int n, istream &in) {
    lista l = new elem;
    in >> l->inf;

    for(int i=1; i<n; i++) {
        elem *e = new elem;
        in >> e->inf;
        l = insert_elem(l, e);
    }
    
    return l;
}

/* Cancella un elemento dalla lista */
lista delete_elem(lista l, elem *e) {
    if(l == e)
        l = tail(l);

    else {
        lista l1 = l;

        while(tail(l1) != e)
            l1 = tail(l);

        l1->pun = tail(e);
    }

    delete e;
    return l;
}

/* Distruggi una lista */
void delete_list(lista l) {
    while(l) {
        l = delete_elem(l, l);
    }
}

elem *search(lista l, int v) {
    while(l != nullptr) {
        if(head(l) == v)
            return l;

        l = tail(l);
    }

    return nullptr;
}

int count(lista l, int v) {
    int c = 0;

    while((l=search(l,v))) {
        c++;
        l = tail(l);
    }

    return c;
}

lista delete_value(lista listHead, int value) {
    lista thisNode = listHead;
    lista prevNode;

    while(thisNode != nullptr) {
        if(head(thisNode) == value) {
            if(thisNode == listHead) {
                thisNode = tail(thisNode);
                delete listHead;
                listHead = thisNode;
            } else {
                prevNode->pun = thisNode->pun;
                delete thisNode;
                thisNode = tail(prevNode);
            }
        } else {
            prevNode = thisNode;
            thisNode = tail(thisNode);
        }
    }

    return listHead;
}

lista copy(lista srcList) {
    lista copiedList;
    elem *newCopiedElement = nullptr;
    elem *lastCopiedElement = nullptr;

    while(srcList) {
        newCopiedElement = new elem;
        newCopiedElement->inf = head(srcList);
        newCopiedElement->pun = nullptr;

        if(lastCopiedElement)   //se ho copiato la testa, lastCopiedElement è nullptr
            lastCopiedElement->pun = newCopiedElement;
        else    //sto copiando la testa
            copiedList = newCopiedElement;

        lastCopiedElement = newCopiedElement;
        srcList = tail(srcList);
    }

    return copiedList;
}

/* Implementare la primitiva delete_tail_elem() che cancella
   l’ultimo elemento della lista usando la primitiva tail()
*/
lista delete_tail_elem(lista l) {
    lista currentNode = l;
    lista previousNode;
    while(tail(currentNode)) {
        previousNode = currentNode;
        currentNode = tail(currentNode);
    }

    delete currentNode;

    if(currentNode == l)
        return nullptr;
    else {
        previousNode->pun = nullptr;
    }

    return l;
}

/* Scrivere la primitiva insert_tail_elem() che inserisce
   l’elemento in fondo alla lista invece che in testa
*/
lista insert_tail_elem(lista l, elem *e) {
    lista currentNode = l;
    e->pun = nullptr;

    while(tail(currentNode))
        currentNode = tail(currentNode);

    if(currentNode != nullptr) {
        currentNode->pun = e;
    } else {
        l = e;
    }

    return l;
}

/*
    Date due liste che implementano insieme di valori interi, implementare le funzioni
    insiemistiche union, intersect e difference che implementano unione insiemistica,
    intersezione insiemistica e differenza insiemistica, rispettivamente.

    Ogni funzione deve restituire una nuova lista quale risultato dell’operazione.
    Le funzioni devono far uso delle primitive dei tipi lista per scorrere le due
    liste e per creare la nuova lista.
*/

lista list_union(lista a, lista b) {
    lista unionList = nullptr;
    elem *newUniqueElement;

    while(a) {
        if(!search(unionList, head(a))) {
            newUniqueElement = new elem;
            newUniqueElement->inf = head(a);
            unionList = insert_elem(unionList, newUniqueElement);
        }

        a = tail(a);
    }
    
    while(b) {
        if(!search(unionList, head(b))) {
            newUniqueElement = new elem;
            newUniqueElement->inf = head(b);
            unionList = insert_elem(unionList, newUniqueElement);
        }

        b = tail(b);
    }

    return unionList;
}

lista list_intersection(lista a, lista b) {
    lista intersectionList = nullptr;
    elem *commonElement;

    while(a) {

        if(search(b, head(a)) && !search(intersectionList, head(a))) {
            commonElement = new elem;
            commonElement->inf = head(a);
            intersectionList = insert_elem(intersectionList, commonElement);
        }

        a = tail(a);
    }

    return intersectionList;
}

// exclusive disjunction
lista list_difference(lista a, lista b) {
    lista differenceList = nullptr;
    elem *exclusiveElement;

    while(a) {

        if(!search(b, head(a)) && !search(differenceList, head(b))) {
            exclusiveElement = new elem;
            exclusiveElement->inf = head(a);
            differenceList = insert_elem(differenceList, exclusiveElement);
        }

        a = tail(a);
    }

    return differenceList;
}

//#define INTERACTIVE

int main() {
    lista l;
    int num;
    elem *e;

#ifdef INTERACTIVE
    cout << "Inizializzazione lista" << endl;
    cout << "Inserisci la dimensione della lista: ";

    cin >> num;

    l = create_list(num, cin);

    print_list(l);


    cout << "Inserimento di un nuovo elemento" << endl;
    e = new elem;
    cin >> e->inf;

    l = insert_elem(l, e);

    print_list(l);


    cout << "Cancellazione del secondo elemento" << endl;
    l = delete_elem(l, l->pun->pun);

    print_list(l);


    cout << "Inserisci l'elemento da cercare: ";
    cin >> num;

    e = search(l, num);

    if(e)
        cout << "elemento trovato: " << head(e) << endl;
    else
        cout << "elemento non trovato" << endl;
    print_list(l);

    
    cout << "Inserisci l'elemento da contare";
    cin >> num;

    cout << count(l, num) << endl;

    
    cout << "Cancello la lista" << endl;
    delete_list(l);
#else
/*
    cout << "Inserisci 5 elementi nella lista:" << endl;
    l = create_list(5, cin);
    print_list(l);

    cout << "Inserisci l'elemento da eliminare: ";
    cin >> num;

    l = delete_value(l, num);
    print_list(l);

    cout << "Deep copy della lista e stampa" << endl;
    lista ll = copy(l);
    print_list(ll);

    cout << "Cancello l'elemento in coda" << endl;
    l = delete_tail_elem(l);
    print_list(l);

    cout << "Inserisci un elemento in coda";
    e = new elem;
    cin >> e->inf;
    insert_tail_elem(l, e);
    print_list(l);
    */

    lista a, b;
    cout << "Inserisci gli elementi di a (3)";
    a = create_list(3, cin);

    cout << "Inserisci gli elementi di b (5)";
    b = create_list(5, cin);

    cout << "a: ";
    print_list(a);
    
    cout << "b: ";
    print_list(b);

    cout << "unione: ";
    print_list(list_union(a, b));

    cout << "intersezione: ";
    print_list(list_intersection(a, b));

    cout << "differenza: ";
    print_list(list_difference(a, b));
    

#endif

    return 0;
}