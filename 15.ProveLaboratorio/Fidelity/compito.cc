#include <iostream>
#include <fstream>
#include "carta.h"
#include "bst.h"
using namespace std;


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

    return 0;
}