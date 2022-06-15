#include <iostream>
#include <fstream>
#include "tipo.h"
#include "liste.h"


using namespace std;

int carica(lista& pi) {
    ifstream in("PI.txt");
    
    int npoi = 0;

    while(in) {
        tipo_inf poi;
        in >> poi.id; in.get();
        in.getline(poi.nome, 20);
        in >> poi.tipo;

        if(in) {
            npoi++;
            elem *poi_list_elem = new_elem(poi);
            pi = ord_insert_elem(pi, poi_list_elem);
        }
    }

    return npoi;
}

tipo_inf search_pi(lista pi, int id) {
    for(int i=1; i<id; i++)
        pi = tail(pi);

    return head(pi);
}

int main() {
    lista pi = nullptr;
    int npoi = carica(pi);

    int user_in = 0;

    do {
        cout << "Inserisci il numero del PoI da ricercare: ";
        cin >> user_in;

        if(user_in <= 0)
            cout << "Arrivederci" << endl;

        else if(user_in <= npoi) {
            tipo_inf risultato = search_pi(pi, user_in);
            print(risultato);
            cout << endl;
        } else {
            cout << "Numero del PoI non valido" << endl;
        }

    } while(user_in > 0);
}