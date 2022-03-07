/*
    Scrivere un programma che:
    –Richieda se effettuare un'operazione di addizione, sottrazione,
    moltiplicazione o divisione tra due interi
    –A seconda dell'operazione scelta, invochi una funzione che
    fornisca il risultato corretto
    –La selezione della funzione avvenga senza costrutti
    if, switch, etc.
*/

#include <iostream>
using namespace std;

int addizione(int a, int b) {
    return a+b;
}

int sottrazione(int a, int b) {
    return a-b;
}

int moltiplicazione(int a, int b) {
    return a*b;
}

int divisione(int a, int b) {
    return a/b;
}

int (* operazioni[4])(int, int) = {
    addizione,
    sottrazione,
    moltiplicazione,
    divisione
};

int main() {

    int opr;   //operatore
    int op1, op2;

    cout << "Inserisci gli operandi:";
    cin  >> op1 >> op2;

    cout << "Operazioni disponibili:"   << endl
         << "0. Addizione"              << endl
         << "1. Sottrazione"            << endl
         << "2. Moltiplicazione"        << endl
         << "3. Divisione"              << endl;

    cout << "Che operazione vuoi effettuare? ";
    cin  >> opr;

    cout << "Ecco il risultato: " << operazioni[opr](op1, op2) << endl;
    
    return 0;
}