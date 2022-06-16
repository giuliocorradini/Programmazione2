#include <iostream>
#include <fstream>
#include "grafi.h"
#include "node.h"
#include "coda.h"
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

int find_owner(graph g, node *n, int tw) {
    adj_list owner = get_adjlist(g, tw);
    while(owner) {
        if(n[get_adjnode(owner) - 1].tipo == 'U')
            return get_adjnode(owner);
        owner = get_nextadj(owner);
    }

    return -1;
}

int* totalLike(graph g, node *n) {
    int *v = new int[g.dim];
    for(int i=0; i<g.dim; i++)
        v[i] = 0;


    for(int i=1; i<=g.dim; i++)
        if (n[i-1].tipo == 'U') {

            adj_list likes = get_adjlist(g, i);
            while(likes) {
                if(n[get_adjnode(likes) - 1].tipo == 'T') {
                    //Find owner
                    int owner = find_owner(g, n, get_adjnode(likes));
                    v[owner-1]++;
                }
                likes = get_nextadj(likes);
            }

        }

    return v;
}

void follow(graph g, node *n, int u) {
    bool *visited = new bool[g.dim];
    for(int i=0; i<g.dim; i++)
        visited[i] = false;
    visited[u-1] = true;
    
    coda front = newQueue();
    front = enqueue(front, u);

    cout << "L'utente " << n[u-1].cont << " segue:" << endl;

    while(!isEmpty(front)) {
        int f = dequeue(front);

        adj_list neigh = get_adjlist(g, f);
        while(neigh) {
            int ne_id = get_adjnode(neigh);

            if(n[ne_id - 1].tipo == 'U' && !visited[ne_id-1]) {
                cout << n[ne_id-1].cont << endl;
                front = enqueue(front, ne_id);
            }
            visited[ne_id-1] = true;

            neigh = get_nextadj(neigh);
        }
    }

    delete[] visited;
}

int main() {
    graph g = parser();
    node *nodi = parser_nodi(g.dim);

    stampa(g, nodi);
    
    int *v = totalLike(g, nodi);
    
    int max_likes;
    // Trova max
    for(int i=1; i<=g.dim; i++)
        if(v[i-1] > max_likes)
            max_likes = v[i-1];

    // Stampa MIP(s)
    for(int i=1; i<=g.dim; i++)
        if(v[i-1] == max_likes)
            cout << nodi[i-1].cont << endl;

    follow(g, nodi, 8);

    return 0;
}
