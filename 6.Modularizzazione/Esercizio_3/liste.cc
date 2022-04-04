#include <cstddef>

// includi liste-tipo.cc
const int STRING_DIMENSION = 51;
struct element_t {
    char info[STRING_DIMENSION];
    struct element_t *prev;
    struct element_t *next;
};
typedef struct element_t * list;
char * head(list);
element_t *new_element(char *);
element_t *search(list, char *);


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
