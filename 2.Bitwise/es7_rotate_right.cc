/*
Traccia: Scrivere un programma che legge da tastiera due numeri naturali k e j,
e ruota a destra di j posizioni la rappresentazione binaria del numero k.
-> La rotazione a destra di j posizioni di una configurazione di bit, si 
comporta come la traslazione (shift) a destra di j posizioni, eccetto il fatto
che, i j bit meno significativi di tale configurazione divengono i j bit piu' 
significativi della nuova configurazione (mentre, nel caso della traslazione 
i j bit meno significativi sarebbero stati buttati via).

-> Attenzione al fatto che, se si immette j > 31, l'implementazione di
questo tipo di programma potrebbe cadere nel problema della
traslazione di un numero di posizioni maggiore di quelle 
contenute nella rappresentazione di un numero naturale. 
Come gia' detto, supponiamo che
non siano mai immessi valori che portano a tale effetto.  Notare che,
in questo esercizio, dobbiamo scrivere il programma in maniera tale
che funzioni bene nel caso j=0.
*/

#include <iostream>
using namespace std;

int main() {
    unsigned int k, j, z;

    cin >> k >> j;

    z = (k >> j) | (k << (32 - j));

    cout << z;

    return 0;
}