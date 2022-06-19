#include <iostream>
#include <fstream>
#include "carta.h"
#include "bst.h"
using namespace std;

/**
 *  Calcola il totale dei punti delle carte con codice compreso tra inf e sup nel bst.
 *  @param t - Struttura che rappresenta il bst
 *  @param inf - estremo inferiore dei codici
 *  @param sup - estremo superiore dei codici 
 */
int totalePunti(bst t, tipo_key inf, tipo_key sup) {
    if(!t)
        return 0;

    if(get_key(t) >= inf && get_key(t) <= sup)
        return get_value(t).punti + totalePunti(get_left(t), inf, sup) + totalePunti(get_right(t), inf, sup);
    
    else if(get_key(t) > sup)
        return totalePunti(get_left(t), inf, sup);
    
    else if(get_key(t) < inf)
        return totalePunti(get_right(t), inf, sup);

    return 0;
}


void aggiorna(bst t, tipo_key k, int punti) {
    bnode *carta = bst_search(t, k);
    if(carta) {
        carta->inf.punti += punti;
        cout << "Punteggio cliente aggiornato" << endl;
    } else {
        cout << "Carta non trovata" << endl;
    }
}


int main() {
    bst carte = nullptr;

    int n;
    char trash;
    tipo_key codice;
    tipo_inf carta;

    cout << "Numero carte: ";
    cin >> n;

    for(int i=1; i<=n; i++) {
        cout << "Carta #" << i << endl;
        cout << "Codice carta: ";
        cin >> codice >> noskipws >> trash;

        cout << "Nominativo: ";
        cin.getline(carta.nominativo, 40);

        cout << "Punti: ";
        cin >> skipws >> carta.punti;

        bnode *node = bst_newNode(codice, carta);
        bst_insert(carte, node);
    }

    print_values(carte);

    int inf, sup;
    cout << "Estremo inferiore: ";
    cin >> inf;
    cout << "Estremo superiore: ";
    cin >> sup;

    cout << "Totale dei punti: " << totalePunti(carte, inf, sup) << endl;

    int punti;
    cout << "Numero della carta: ";
    cin >> codice;
    cout << "Punti da inserire: ";
    cin >> punti;

    aggiorna(carte, codice, punti);

    print_values(carte);

    return 0;
}