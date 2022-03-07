/*
    Scrivere un programma che implementa una funzione per il calcolo
    della somma dei primi n valori di una generica funzione int f(int):
    somma(n,f) = f(1) + f(2) + f(3) + .... + f(n)
*/

#include <iostream>
using namespace std;

int quadrato(int a) {
    return a*a;
}

int cubo(int a) {
    return a*a*a;
}

int somma(int n, int(*f)(int)) {
    int accumulatore = 0;

    for(int i=1; i<=n; i++) {
        accumulatore += f(i);
    }

    return accumulatore;
}

int main() {
    int n;

    cout << "Quante iterazioni? ";
    cin >> n;

    cout << "Somma dei primi n quadrati: "
         << somma(n, quadrato) << endl;

    cout << "Somma dei primi n cubi: "
         << somma(n, cubo) << endl;
}