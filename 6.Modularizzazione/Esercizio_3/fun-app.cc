#include <iostream>
using namespace std;

#include "fun-app.h"

void list_print(list l) {
    while(l) {
        print(head(l));
        cout << endl;

        l = tail(l);
    }

    cout << endl;
}

list list_create(int n, istream &in) {
    list l = nullptr;

    for(int i=0; i<n; i++) {
        element_t *e = new element_t;
        in >> e->info;
        l = insert_element(l, e);
    }
    
    return l;
}

list delete_value(list l, char *v) {
    element_t *currentPointer = l;

    while(currentPointer) {

        if(compare(head(currentPointer), v) == 0) {
            l = delete_element(l, currentPointer);
        }
        
        currentPointer = tail(currentPointer);
    }

    return l;
}

void list_destroy(list l) {
    element_t *lastElement;

    while(l) {
        lastElement = l;
        l = tail(l);
        delete lastElement;
    }
}

element_t * crawl(element_t *e, direction_t d) {
    if(d == FORWARD)
        return e->next;
    else
        return e->prev;
}
