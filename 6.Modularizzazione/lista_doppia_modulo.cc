#include <iostream>
#include <cstring>
using namespace std;

/***************************/
/* INTESTAZIONE DEL MODULO */
/***************************/

const int STRING_DIM = 51;

struct element_t {
    char info[STRING_DIM];
    struct element_t *prev;
    struct element_t *next;
};

typedef struct element_t * list;

char *head(list);
list tail(list);
list insert_element(list, element_t *);
element_t *new_element(char *);
list crealista(int);
void stampalista(list);

/**************************/
/* DEFINIZIONE DEL MODULO */
/**************************/

char * head(list l) {
    return l->info;
}

list tail(list l) {
    return l->next;
}

list insert_element(list l, element_t *e) {
    e->next = l;
    e->prev = nullptr;

    if(l)
        l->prev = e;

    return e;
}

element_t *new_element(char *content) {
    element_t *elem = new element_t;
    strcpy(elem->info, content);

    return elem;
}

list crealista(int n) {
    list l = nullptr;
    char nodeContent[51];

    for(int i=0; i<n; i++) {
        cin >> nodeContent;
        element_t *e = new_element(nodeContent);

        l = insert_element(l, e);
    }

    return l;
}

void stampalista(list l) {
    while(l) {
        cout << head(l) << endl;

        l = tail(l);
    }

    cout << endl;
}

int main() {
    int numElementiLista;
    list theList;

    cout << "Quanti elementi? ";
    cin >> numElementiLista;

    cout << "Creo la lista. Inserisci gli elementi:" << endl;
    theList = crealista(numElementiLista);

    stampalista(theList);

    return 0;
}