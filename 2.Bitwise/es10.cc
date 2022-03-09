/*
Traccia: Scrivere un programma che legga da tastiera un numero
naturale n, calcoli il piu' grande numero naturale pari i, tale che
i<=n, e stampi il risultato sullo schermo  (ovviamente, se n e' pari
i sara' uguale ad n, mentre, se n e' dispari, i sara' uguale a n-1).
Suggerimento: lavorare sulla configurazione di bit che rappresenta n.
*/

#include <iostream>
using namespace std;

int main() {
    unsigned int n;
    cin >> n;

    n &= ~(0x01);

    cout << n;

    return 0;
}