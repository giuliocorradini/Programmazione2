/*
Traccia: Scrivere un programma che legga da tastiera due numeri naturali k e j,
e ruoti a sinistra di j posizioni la rappresentazione binaria del numero k.
-> La rotazione a sinistra di j posizioni di una configurazione di bit si 
comporta come la traslazione (shift) a sinistra di j posizioni, 
eccetto il fatto che, i j bit piu' significativi di tale configurazione 
divengono i j bit meno significativi della nuova configurazione (mentre, nel 
caso della traslazione i j bit piu' significativi sarebbero stati buttati via).

-> Attenzione sempre al caso j > 31 e notare che anche in questo
esercizio, dobbiamo scrivere il programma in maniera tale che funzioni
bene nel caso j=0.
*/

#include <iostream>
using namespace std;

int main() {
    unsigned int k, j, z;

    cin >> k >> j;

    z = (k << j) | (k >> (32 - j));

    cout << z;

    return 0;
}