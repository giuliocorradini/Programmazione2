#include "tipo.h"
#include <iostream>
using namespace std;

int compare(tipo_inf a, tipo_inf b) {
    if(a==b)
        return 0;
    
    if(a > b)
        return 1;

    return -1;
}

void copy(tipo_inf &dst, tipo_inf src) {
    dst = src;
}

void print(tipo_inf x) {
    cout << x;
}
