#include "tipo.h"
#include <cstring>
#include <iostream>
using namespace std;

int compare(tipo_inf a, tipo_inf b) {
    int cmp = strcmp(a.data, b.data);
    if(cmp != 0)
        return cmp;

    return strcmp(a.ora_i, b.ora_i);
}

void copy(tipo_inf &a, tipo_inf b) {
    strcpy(a.data, b.data);
    strcpy(a.ora_i, b.ora_i);
    strcpy(a.ora_f, b.ora_f);
    strcpy(a.descr, b.descr);
}

void print(tipo_inf a) {
    cout << a.data << " " << a.ora_i << " " << a.ora_f << " " << a.descr;
}