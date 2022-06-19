#include <iostream>
#include <cstring>
#include "carta.h"
using namespace std;

int compare(tipo_inf a, tipo_inf b) {
    return a.punti - b.punti;
}

void copy(tipo_inf &dst, tipo_inf src) {
    strcpy(dst.nominativo, src.nominativo);
    dst.punti = src.punti;
}

void print(tipo_inf x) {
    cout << x.nominativo << " - " << x.punti << " punti";
}