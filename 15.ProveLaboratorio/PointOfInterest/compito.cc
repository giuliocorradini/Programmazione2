#include <iostream>
#include <fstream>
#include "tipo.h"
#include "liste.h"
#include "grafo.h"
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

graph mappa(int n) {
    ifstream in("G.txt");
    graph g = new_graph(n);

    int from, to;

    while(in) {
        in >> from >> to;
        if(in) {
            add_edge(g, from, to, 1);
        }
    }

    return g;
}

void stampa_mappa(graph g,lista pi) {
    for(int i=1; i<=g.dim; i++) {
        //Stampa nome della partenza
        print(search_pi(pi, i));
        cout << " - ";

        //Stampa nomi dei collegati
        adj_list l = get_adjlist(g, i);
        bool first=true;
        while(l) {
            if(!first) {
                cout << ", ";
            } else {
                first = false;
            }
            print(search_pi(pi, get_adjnode(l)));

            l = get_nextadj(l);
        }

        cout << endl;
    }
}

int main() {
    lista pi = nullptr;
    int npoi = carica(pi);

    graph g = mappa(npoi);
    stampa_mappa(g, pi);

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