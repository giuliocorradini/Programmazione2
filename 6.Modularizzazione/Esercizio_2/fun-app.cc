#include <iostream>
using namespace std;

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


// includi liste.cc
list tail(list);
list prev(list);
list insert_element(list, element_t *);
list delete_element(list, element_t *);


void list_print(list l) {
    while(l) {
        cout << head(l) << endl;

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

        if(strcmp(head(currentPointer), v) == 0) {
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

enum direction_t {
    FORWARD,
    BACKWARD
};

element_t * crawl(element_t *e, direction_t d) {
    if(d == FORWARD)
        return e->next;
    else
        return e->prev;
}
