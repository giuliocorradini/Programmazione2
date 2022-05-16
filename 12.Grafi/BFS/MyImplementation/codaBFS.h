#pragma once

struct bfs_elem {
    int inf;
    struct bfs_elem *next;
};

struct bfs_queue {
    struct bfs_elem *head;
    struct bfs_elem *tail;
};

bfs_queue createQueue

bfs_queue enqueue(bfs_queue, int);

int dequeue(bfs_queue&);

int first(bfs_queue);
