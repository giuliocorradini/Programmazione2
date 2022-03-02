/*
Scrivere un programma che stampi il contenuto di un vettore di
interi definito ed inizializzato a tempo di scrittura del programma
stesso e che contiene almeno un elemento di valore -1. In
particolare lo stesso vettore va stampato due volte, utilizzando
ciascuna volta una funzione diversa. Le due funzioni di stampa
devono avere un solo parametro formale, non devono utilizzare
variabili globali, e devono stampare gli elementi del vettore
fermandosi non appena incontrano l'elemento di valore -1 (senza
stamparlo).

La prima funzione non deve utilizzare l'operazione di selezione con
indice, mentre la seconda non deve utilizzare nè l'operazione di
selezione con indice nè alcuna variabile locale.
*/

#include <iostream>
using namespace std;

void stampa_vettore_1(int *vect) {
    bool stop = false;

    for(int i=0; !stop; i++) {
        if(*(vect+i) == -1)
            stop = true;
        else
            cout << *(vect+i) << " ";
    }

    cout << endl;
}

void stampa_vettore_2(int *vect) {
    while(*vect != -1)
        cout << *(vect++) << " ";

    cout << endl;
}

int main() {
    const int N = 5;
    int v[N] = {4, 12, 1, -1, 3};

    cout << "Stampa con funzione 1: " << endl;
    stampa_vettore_1(v);

    cout << "Stampa con funzione 2: " << endl;
    stampa_vettore_2(v);
    
    return 0;
}