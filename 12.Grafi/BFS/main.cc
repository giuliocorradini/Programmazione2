#include <iostream>
#include <fstream>
#include "grafo.h"
#include "coda-bfs.h"
using namespace std;

/*
 * Legge dallo stream g il numero dei nodi (prima riga), genera il corrispondente
 * grafo e lo popola aggiungendo gli archi specificati nelle righe successive del file.
 * g_build deve creare un grafo orientato o meno in base al parametro booleano d
 * e deve leggere i pesi dal file se w è TRUE
 */
graph g_build(ifstream &g, bool oriented, bool weighted) {
    int numNodi;
    g >> numNodi;

    graph gr = new_graph(numNodi);

    while(g) {
        int s, d, w;

        g >> s >> d;

        if(g.fail())
            break;

        if(weighted)
            g >> w;
        else
            w = 1;

        if(oriented)
            add_arc(gr, s, d, w);
        else
            add_edge(gr, s, d, w);
    }

    return gr;
}

bool connected(graph &g, int vertex) {
    int nodes = g.dim;
    bool *visited = new bool[nodes];

    for(int i=0; i<nodes; i++) {
        visited[i] = false;
    }

    codaBFS c = newQueue();
    visited[vertex-1] = true;
    enqueue(c, vertex);

    int u;
    while(c.head != nullptr) {
        u = dequeue(c);

        adj_list u_adjPtr = get_adjlist(g, u);
        while(u_adjPtr != nullptr) {
            int thisNode = get_adjnode(u_adjPtr);
            if(!visited[thisNode - 1]) {
                visited[thisNode - 1] = true;
                enqueue(c, thisNode);
            }

            u_adjPtr = get_nextadj(u_adjPtr);
        }
    }

    for(int i=0; i<nodes; i++) 
        if(visited[i] == false)
            return false;

    return true;
}

int main(int argc, char *argv[]) {
    if(argc != 4) {
        cout << "usage: " << argv[0] << " filename <1 if oriented> <1 if weighted>" << endl;
        return -1;
    }

    char *filename = argv[1];
    char *orientedOption = argv[2];
    char *weightedOption = argv[3];

    bool isOriented = *orientedOption == '1';
    bool isWeighted = *weightedOption == '1';

    ifstream in(filename);

    graph g = g_build(in, isOriented, isWeighted);

    in.close();
    
    for(int i=1; i<=get_dim(g); i++) {
        cout << i << " - ";
        adj_list a = get_adjlist(g, i);

        bool first=true;
        while(a) {
            if(!first)
                cout << ", ";
            else
                first = false;
            
            cout << get_adjnode(a);

            a = get_nextadj(a);
        }

        cout << endl;
    }

    cout << "Is connected? " << connected(g, 1) << endl;

    return 0;
}
