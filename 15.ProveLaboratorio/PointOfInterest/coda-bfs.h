#pragma once

struct elemBFS
{
    int inf;
    elemBFS* pun ;
};

typedef elemBFS* lista_bfs;

typedef struct {
    lista_bfs head;
    elemBFS* tail;
} codaBFS;

void enqueue(codaBFS &, int);
int dequeue(codaBFS&);
int first(codaBFS);
bool isEmpty(codaBFS);
codaBFS newQueue();
