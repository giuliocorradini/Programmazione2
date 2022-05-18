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

int * connected(graph &g, int *visited, int vertex, int id) {
    codaBFS c = newQueue();
    visited[vertex-1] = id;
    enqueue(c, vertex);

    int u;
    while(c.head != nullptr) {
        u = dequeue(c);

        adj_list u_adjPtr = get_adjlist(g, u);
        while(u_adjPtr != nullptr) {
            int thisNode = get_adjnode(u_adjPtr);
            if(!visited[thisNode - 1]) {
                visited[thisNode - 1] = id;
                enqueue(c, thisNode);
            }

            u_adjPtr = get_nextadj(u_adjPtr);
        }
    }

    return visited;
}

bool isConnected(graph &g, int vertex) {
    int *visited = new int[g.dim];
    for(int i=0; i<g.dim; i++)
        visited[i] = 0;

    connected(g, visited, vertex, 1);

    bool conn = true;

    for(int i=0; i<g.dim; i++) 
        if(visited[i] == 0)
            conn = false;

    delete[] visited;
    return conn;
}

void connected_component(graph &g) {
    int globalNodes = g.dim;
    int *components = new int[globalNodes];
    for(int i=0; i<globalNodes; i++) {
        components[i] = 0;
    }

    int componentCounter = 1;

    for(int i=0; i<globalNodes; i++) {
        if(components[i] == 0)
            connected(g, components, i+1, componentCounter++);
    }

    for(int j=1; j<componentCounter; j++) {
        cout << "componente connessa #" << j << ": ";
        for(int i=0; i<globalNodes; i++) {
            if(components[i] == j)
                cout << i + 1 << " ";
        }
        cout << endl;
    }
}

bool spanning_tree(graph &g, int vertex, int *father, int *visited) {
    int n = g.dim;
    for(int i=0; i<n; i++) {
        father[i] = -1;
        visited[i] = 0;
    }

    visited[vertex-1] = 1;

    codaBFS c = newQueue();

    enqueue(c, vertex);
    while(!isEmpty(c)) {
        int u = dequeue(c);
        adj_list wPtr = get_adjlist(g, u);
        while(wPtr) {
            int w = get_adjnode(wPtr);
            if(!visited[w-1]) {
                visited[w-1] = 1;
                father[w-1] = u-1;
                enqueue(c, w);
            }

            wPtr = get_nextadj(wPtr);
        }
    }

    int orphans = 0;
    for(int i=0; i<g.dim; i++) {
        if(father[i] == -1)
            orphans++;
    }

    return orphans <= 1;
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

    cout << "Is totally connected? " << (isConnected(g, 1) ? "yes" : "no") << endl;

    connected_component(g);

    cout << "Computing spanning tree. Enter start vertex: ";
    int v;
    cin >> v;
    int *visited = new int[g.dim];
    int *father = new int[g.dim];

    for(int i=0; i<g.dim; i++) {
        visited[i] = 0;
        father[i] = -1;
    }

    bool isSt = spanning_tree(g, v, father, visited);
    cout << "This is " << (isSt ? "" : "not") << " a spanning tree" << endl;
    if(isSt) {
        for(int i=0; i<g.dim; i++)
            cout << father[i] + 1 << endl;
    }

    return 0;
}
