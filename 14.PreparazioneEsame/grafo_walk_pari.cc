#include <iostream>
#include <fstream>
#include "utils/coda-bfs.h"
#include "utils/grafo.h"
using namespace std;

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

//x sorgente, y destinazione
//solo nodi pari pls
bool even_path(graph g, int x, int y) {
    //BFS iterativa, aggiungo i nodi in coda solo se pari, se vedo la dst mi fermo
    bool *visited = new bool[g.dim];
    visited[x-1] = true;

    codaBFS frontier = newQueue();
    enqueue(frontier, x);

    while(!isEmpty(frontier)) {
        int fnode = dequeue(frontier);
    
        //read adj list
        adj_list fnode_adj = get_adjlist(g, fnode);

        //walk adj list
        while(fnode_adj) {
            visited[fnode-1] = true;
            int id = get_adjnode(fnode_adj);

            if(id == y) {
                delete[] visited;
                return true;
            }

            if(id % 2 == 0 && !visited[id-1])
                enqueue(frontier, id);

            fnode_adj = get_nextadj(fnode_adj);
        }
    }

    delete[] visited;
    return false;
}

void dfs_visit(graph g, int x, int y, bool *visited) {
    visited[x] = true;

    if(visited[y])
        return;

    adj_list x_edges = get_adjlist(g, x);

    while(x_edges) {
        int adj_node = get_adjnode(x_edges);

        if(!visited[adj_node] && (adj_node % 2 == 0 || adj_node == y))
            dfs_visit(g, adj_node, y, visited);

        x_edges = get_nextadj(x_edges);
    }
}

bool even_path_dfs(graph g, int x, int y) {
    bool *visited = new bool[g.dim+1];
    for(int i=0; i<=g.dim; i++)
        visited[i] = false;
    
    dfs_visit(g, x, y, visited);

    bool path_exists = visited[y];
    delete[] visited;
    return path_exists;
}


int main() {
    graph g;

    ifstream f("grafo_walk_pari_data");
    g = g_build(f, false, false);
    f.close();

    cout << "Cammino con BFS: " << even_path(g, 6, 7) << endl;

    cout << "Cammino con DFS: " << even_path_dfs(g, 6, 7) << endl;
}