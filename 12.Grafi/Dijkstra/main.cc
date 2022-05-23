#include <iostream>
#include <fstream>
#include <limits>
#include "grafo.h"
#include "codap.h"
using namespace std;

const float Inf = numeric_limits<float>::infinity();


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


void dijkstra(graph &g, int start, int *prev, float *dist) {

    for(int i=0; i<g.dim; i++) {
        prev[i] = -1;
        dist[i] = Inf;
    }
    dist[start-1] = 0;

    codap q = nullptr;
    for(int i=1; i<=g.dim; i++) {
        q = enqueue(q, i, Inf);
    }
    q = Decrease_Priority(q, start, 0);

    while(!isEmpty(q)) {
        int u = dequeue(q);

        adj_list edge = get_adjlist(g, u);
        while(edge) {
            int v = get_adjnode(edge);

            if(dist[v-1] > dist[u] + get_adjweight(edge)) {
                dist[v-1] = dist[u] + get_adjweight(edge);
                prev[v-1] = u-1;
                q = Decrease_Priority(q, v, dist[v-1]);
            }

            edge = get_nextadj(edge);
        }
    }

}


/*
 *  @param dst index of destination node (dst_id - 1)
 */
void print_path(int dst, int *prev) {
    if(prev[dst] == -1) {
        cout << dst + 1;
        return;
    }

    print_path(prev[dst], prev);

    cout << " -> " << prev[dst] + 1;
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

    if(!isWeighted) {
        cout << "The graph is not weighted, why would perform Dijkstra on it?" << endl;
    }

    graph g = g_build(in, isOriented, isWeighted);

    in.close();
    
    cout << "Graph representation: " << endl;
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

    int *previous = new int[g.dim];
    float *distance = new float[g.dim];

    int start;
    cout << "Start node: ";
    cin >> start;

    dijkstra(g, start, previous, distance);

    for(int i=0; i<g.dim; i++) {
        cout << i + 1 << " - ";
        print_path(i, previous);
        cout << " with weight: " << distance[i] << endl;
        //cout << previous[i] << endl;
    }

    delete[] previous;
    delete[] distance;

    return 0;
}
