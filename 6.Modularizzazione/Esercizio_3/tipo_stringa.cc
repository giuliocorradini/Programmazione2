#include "tipo.h"
#include <cstring>
#include <iostream>
using namespace std;

int compare(tipo_inf a, tipo_inf b) {
    return strcmp(a, b);
}

void copy(tipo_inf &dst, tipo_inf src) {
    strcpy(dst, src);
}

void print(tipo_inf x) {
    cout << x;
}
