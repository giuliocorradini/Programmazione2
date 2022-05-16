#pragma once

struct adj_node {
    int node;
    float weight;
    struct adj_node *next;
};

typedef struct adj_node* adj_list;

struct graph {
    adj_list *nodes;
    int dim;
};

graph new_graph(int n);

/*
 * Aggiunge l’arco orientato (s,d) con peso w alla lista di adiacenza del nodo s
 */
void add_arc(graph& g,int s,int d,float w);

/*
 * Aggiunge l’arco non orientato (s,d) con peso w alla lista
 * di adiacenza del nodo s e del nodo d
 */
void add_edge(graph& g,int s,int d,float w);

/*
 * Restituisce il numero n dei nodi del grafo
 */
int get_dim(graph &);

/*
 * Restituisce la testa della lista di adiacenza del nodo con
 * identificativo in ingresso
 */
adj_list get_adjlist(graph &, int);

/*
 * Restituisce l’identificativo del nodo contenuto nell’elemento
 * della lista di adiacenza
 */
int get_adjnode(adj_node*);

/*
 * Restituisce il prossimo elemento della lista di adiacenza
 */
adj_list get_nextadj(adj_list);

float get_adjweight(adj_node *);
