#pragma once

#include "liste.h"

struct parola{
    char p[80]; //parola
    int n_doc; //numero di documenti che contengono la parola
    lista l; //lista dei documenti
};
