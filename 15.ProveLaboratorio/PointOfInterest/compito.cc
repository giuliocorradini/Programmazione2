#include <iostream>
#include <fstream>
#include "tipo.h"
#include "liste.h"
#include "grafo.h"
#include "coda-bfs.h"
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

void trip(graph g, int node, lista pi) {
    tipo_inf start_poi = search_pi(pi, node);

    bool *visited = new bool[g.dim];
    codaBFS front = newQueue();
    enqueue(front, node);

    while(!isEmpty(front)) {
        int curr = dequeue(front);
        visited[curr-1] = true;

        adj_list adjs = get_adjlist(g, curr);
        while(adjs) {
            int cadj = get_adjnode(adjs);
            tipo_inf cadj_poi = search_pi(pi, cadj);

            if(cadj_poi.tipo == start_poi.tipo && !visited[cadj-1]) {
                enqueue(front, cadj);
            }

            adjs = get_nextadj(adjs);
        }
    }

    cout << "Raggiungibili da ";
    print(start_poi);
    cout << ":" << endl;

    for(int i=1; i<=g.dim; i++) {
        if(i != node && visited[i-1]) {
            print(search_pi(pi, i));
            cout << endl;
        }
    }

    delete[] visited;
}

int main() {
    lista pi = nullptr;
    int npoi = carica(pi);

    graph g = mappa(npoi);
    stampa_mappa(g, pi);

    int user_in;
    
    cout << "Inserisci il numero del PoI da cui far partire il trip: ";
    cin >> user_in;

    trip(g, user_in, pi);
}