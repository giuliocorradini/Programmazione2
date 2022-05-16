#include "codaBFS.h"
#include <cstddef>
using namespace std;

static bfs_elem* new_elem(int content) {
    bfs_elem *e = new bfs_elem;
    
    *e = {
        .inf = content,
        .next = nullptr,
    };

    return e;
}

int first(bfs_queue q) {
    if(q == nullptr)
        return -1;

    return q->inf;
}

int dequeue(bfs_queue &q) {
    if(q == nullptr)
        return -1;

    bfs_elem *e = q;
    int firstNode = e->inf;
    q = q->next;
    delete e;

    return firstNode;
}

bfs_queue enqueue(bfs_queue q, int node) {
    bfs_elem *e = new_elem(node);
    
}