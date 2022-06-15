#include "grafo.h"
#include <cstddef>
using namespace std;

graph new_graph(int n) {
    graph g;
    g.dim = n;
    g.nodes = new adj_list[n];

    return g;
}

void add_arc(graph &g, int s, int d, float w) {
    if(s > 0 && s <= g.dim && d > 0 && d <= g.dim) {
        adj_node *new_arc = new adj_node;
        new_arc->node = d - 1;
        new_arc->weight = w;
        new_arc->next = g.nodes[s - 1];

        g.nodes[s-1] = new_arc;
    }
}

void add_edge(graph &g, int s, int d, float w) {
    add_arc(g, s, d, w);
    add_arc(g, d, s, w);
}

int get_dim(graph &g) {
    return g.dim;
}

adj_list get_adjlist(graph &g, int id) {
    if(id <= 0 || id > g.dim)
        return nullptr;

    return g.nodes[id - 1];
}

int get_adjnode(adj_node* n) {
    return n->node + 1;
}

adj_list get_nextadj(adj_list l) {
    return l->next;
}

float get_adjweight(adj_node *n) {
    return n->weight;
}
