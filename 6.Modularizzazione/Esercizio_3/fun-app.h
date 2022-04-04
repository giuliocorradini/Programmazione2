#include <iostream>
using namespace std;

#include "liste.h"

#pragma once

void list_print(list);
list list_create(int, istream &);
list delete_value(list, tipo_inf);
void list_destroy(list);
enum direction_t {
    FORWARD, BACKWARD
};
element_t *crawl(element_t *, direction_t);