#include <iostream>
#include <cstring>
using namespace std;

const int STRING_DIMENSION = 51;

struct element_t {
    char info[STRING_DIMENSION];
    struct element_t *prev;
    struct element_t *next;
};

typedef struct element_t * list;

// includi liste.cc
list tail(list);
list prev(list);
list insert_element(list, element_t *);
list delete_element(list, element_t *);

char * head(list l) {
    return l->info;
}

element_t *new_element(char *content) {
    element_t *elem = new element_t;
    strcpy(elem->info, content);

    return elem;
}


element_t *search(list l, char *v) {
    while(l != nullptr) {
        if(strcmp(head(l), v) == 0)
            return l;

        l = tail(l);
    }

    return nullptr;
}
