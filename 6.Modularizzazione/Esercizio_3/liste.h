#pragma once

#include "tipo.h"

struct element_t {
    tipo_inf info;
    struct element_t *prev;
    struct element_t *next;
};

typedef struct element_t * list;

char * head(list);
element_t *new_element(char *);
element_t *search(list, char *);


list tail(list);
list prev(list);
list insert_element(list, element_t *);
list delete_element(list, element_t *);
