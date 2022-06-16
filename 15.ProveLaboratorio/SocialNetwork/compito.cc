#include <iostream>
#include <fstream>
#include "grafi.h"
#include "node.h"
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

        if(in)
            add_arc(g, from, to, 1);
    }

    in.close();
    return g;
}

node *parser_nodi(int n) {
    node *nodes = new node[n];

    ifstream in("node");

    char trash;

    for(int i=0; i<n && in; i++) {
        in.getline(nodes[i].cont, 80);
        in >> nodes[i].tipo;
        in >> noskipws >> trash;
    }

    in.close();

    return nodes;
}

void stampa(graph g, node *nodi) {
    for(int i=1; i<=g.dim; i++) {
        adj_list neigh = get_adjlist(g, i);

        while(neigh) {
            node *n1, *n2;
            n1 = &nodi[i-1];
            n2 = &nodi[get_adjnode(neigh) - 1];

            cout << n1->cont << " ";
            if(n1->tipo == 'U' && n2->tipo == 'U')
                cout << "FOLLOW";
            else if (n1->tipo == 'U' && n2->tipo == 'T')
                cout << "LIKE";
            else if (n1->tipo == 'T' && n2->tipo == 'U')
                cout << "OWNER";

            cout << " " << n2->cont << endl;

            neigh = get_nextadj(neigh);
        }
        cout << endl;
    }
}

int main() {
    graph g = parser();
    node *nodi = parser_nodi(g.dim);

    stampa(g, nodi);
}
