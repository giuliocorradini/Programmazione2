#include <iostream>

using namespace std ;

#include "coda-bfs.h"

static elemBFS* new_elem(int n){
	elemBFS* p = new elemBFS ;
	p->inf=n;
	p->pun=NULL;
	return p;
}

void enqueue(codaBFS &c, int i){
	elemBFS *e=new_elem(i);
	if(c.tail!=NULL)
			c.tail->pun=e;
	c.tail=e;
	if(c.head==NULL)
		c.head=c.tail;
}

int dequeue(codaBFS& c){
	int ris=(c.head)->inf;
	c.head=(c.head)->pun;
	return ris;
};

int first(codaBFS c){
	return (c.head)->inf;
};


bool isEmpty(codaBFS c){
	if(c.head==NULL)
		return true;
	return false;
}

codaBFS newQueue(){
	codaBFS c={NULL, NULL};
	return c;
}


