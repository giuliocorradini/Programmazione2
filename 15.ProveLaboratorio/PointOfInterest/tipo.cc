#include "tipo.h"
#include <cstring>
#include <iostream>
using namespace std;

int compare(tipo_inf a, tipo_inf b) {
    return a.id - b.id;
}

void copy(tipo_inf &dst, tipo_inf src) {
    dst.id = src.id;
    strcpy(dst.nome, src.nome);
    dst.tipo = src.tipo;
}

void print(tipo_inf x) {
    cout << x.id << " " << x.nome << " ";
    switch(x.tipo) {
        case 'p':
            cout << "piazza";
            break;
        case 'm':
            cout << "museo";
            break;
        case 'e':
            cout << "edificio";
            break;
        default:
            cout << "invalid_type";
            break;
    }
}
