#include "liste.h"

#include <cstddef>
#include <iostream>
#include <cstring>
using namespace std;

tipo_inf head(list l) {
    return l->info;
}

element_t *new_element(tipo_inf content) {
    element_t *elem = new element_t;
    copy(elem->info, content);

    return elem;
}


element_t *search(list l, tipo_inf v) {
    while(l != nullptr) {
        if(compare(head(l), v) == 0)
            return l;

        l = tail(l);
    }

    return nullptr;
}



list tail(list l) {
    return l->next;
}

list prev(list l) {
    return l->prev;
}

list insert_element(list l, element_t *e) {
    e->next = l;
    e->prev = nullptr;

    if(l)
        l->prev = e;

    return e;
}

list delete_element(list l, element_t *e) {
    if(l == e) {
        l = tail(l);
        if(l)
            l->prev = nullptr;
    } else {
        list l1 = l;
        
        while((l1 = tail(l1))) {
            if(l1 == e) {
                l1->prev->next = l1->next;
                if(l1->next)
                    l1->next->prev = l1->prev;
            }
        }
    }

    return l;
}
