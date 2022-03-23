/*
    Per verificare la bontà della mia soluzione prendi un simulatore e lancia il programma
    nella shell così:

    echo $PASSI | ./a.out | wc

    il primo campo dell'output indica il numero di mosse.
*/

#include <iostream>
using namespace std;

void hanoi(int n, char pioloSrc, char pioloDst, char pioloApp) {
    if(n == 1)
        cout << "Sposta disco da " << pioloSrc << " a " << pioloDst << endl;

    else {
        hanoi(n-1, pioloSrc, pioloApp, pioloDst);
        cout << "Sposta disco da " << pioloSrc << " a " << pioloDst << endl;    //sposta disco più grande
        hanoi(n-1, pioloApp, pioloDst, pioloSrc);
    }
}

int main() {
    int numeroDischi;

    cout << "Inserisci il numero di dischi: ";
    cin >> numeroDischi;

    // ok, let's gooooo
    hanoi(numeroDischi, 'A', 'B', 'C');

    return 0;
}