/*
 * Punto 1: Creare un progetto (e il corrispondente makefile) per l’acquisizione
 * del grafo. Il progetto include il modulo “grafo” e il file compito.cc. Il main
 * nel file compito.cc deve contenere il codice per l’acquisizione del grafo
 * orientato contenuto nel file graph quindi richiamare la procedura stampa(graph)
 * da codificare nel file compito.cc che stampa gli archi del grafo.
*/

#include <iostream>
#include <fstream>
#include "grafi.h"
using namespace std;

graph parser() {
    ifstream in("graph");
    graph g;

    int nodes;
    in >> nodes;

    g = new_graph(nodes);

    while(in) {
        int from, to;
        in >> from >> to;

        add_arc(g, from, to, 1);
    }

    in.close();
    return g;
}

void stampa(graph g) {
    for(int i=1; i<=g.dim; i++) {
        adj_list neigh = get_adjlist(g, i);

        while(neigh) {
            cout << i << " " << get_adjnode(neigh) << endl;
            neigh = get_nextadj(neigh);
        }
    }
}

int main() {
    graph g = parser();
    stampa(g);
}
