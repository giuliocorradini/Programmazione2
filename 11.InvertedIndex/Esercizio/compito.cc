/*
Creare il file compito.cc contenente: Funzione parola* load(int& dim)
Carica dal file inverted l’inverted index. Tutte le parole sono memorizzate in un vettore dinamico di tipo parola. La
dimensione del vettore dinamico è letta dalla prima riga del file inverted.
La funzione restituisce il vettore dinamico e la sua dimensione nel parametro passato per riferimento
Procedura stampa(parola*, int)
Stampa il contenuto dell’inverted index (primo parametro vettore dinamico, secondo parametro dimensione
del vettore).
Un main che richiama in sequenza le due funzioni.
*/

#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

#include "liste.h"
#include "parola.h"

const char *FILENAME = "inverted";

parola *load(int &dim) {
    ifstream f(FILENAME);

    f >> dim;

    parola *index = new parola[dim];

    for(int i=0; i<dim; i++) {
        // Leggi la parola
        f >> index[i].p;
        
        // Dimensione della lista
        int listDimension, currentId;
        f >> listDimension;
        index[i].n_doc = listDimension;

        // ID nella lista
        index[i].l = nullptr;   //lista vuota
        for(int j=0; j<listDimension; j++) {
            f >> currentId;
            elem *e = new_elem(currentId);
            index[i].l = insert_elem(index[i].l, e);
        }
    }

    f.close();

    return index;
}

void stampa(parola *index, int dim) {
    for(int i=0; i<dim; i++) {
        cout << index[i].p << endl;
        cout << index[i].n_doc << endl;

        lista id_list = index[i].l;
        while(id_list) {
            print(head(id_list));
            cout << endl;
            id_list = tail(id_list);
        }
    }
}

void addDocumentToPostlist(parola &II, int docID) {
    if(!search(II.l, docID)) {
        // Il documento non è presente
        II.n_doc++;

        elem *e = new_elem(docID);
        II.l = insert_elem(II.l, e);
    }
}

void allargaVettore(parola *&II_vect, int oldN, int newN) {
    parola *new_II_vect = new parola[newN];
    memcpy(new_II_vect, II_vect, sizeof(parola) * oldN);
    delete II_vect;
    II_vect = new_II_vect;
}

/*
Aggiorna l’inverted index caricando il contenuto del documento contenuto nel file fileName.
Ogni file caricato ha la stessa struttura del file doc.
Il codice deve gestire il caso di aggiunta di una parola, di aggiunta di un id di
documento alla posting list di un parola già presente nell’inverted index.
Il parametro n contiene la nuova dimensione della vettore
*/

void update(parola* &II, char* filename, int& n) {
    ifstream f(filename);

    int docId;
    f >> docId;

    while(f) {
        char word[80];
        f >> word;

        bool found = false;
        for(int i=0; i<n && !found; i++) {
            if(strcmp(II[i].p, word) == 0) {
                found = true;
                addDocumentToPostlist(II[i], docId);
            }
        }

        if(!found) {
            allargaVettore(II, n, n+1);
            strcpy(II[n].p, word);
            II[n].l = nullptr;
            addDocumentToPostlist(II[n], docId);
            n++;
        }
    }

    f.close();
}

void AND(parola *II, char *word1, char *word2, int n) {
    lista docWord1 = nullptr, docWord2 = nullptr;

    // Cerca le parole nell'index
    for(int i=0; i<n; i++) {
        if(strcmp(II[i].p, word1) == 0)
            docWord1 = II[i].l;
        else if(strcmp(II[i].p, word2) == 0)
            docWord2 = II[i].l;
    }

    // Merge della lista
    while(docWord1) {
        lista dw2_ptr = docWord2;

        while(dw2_ptr) {
            if(compare(head(docWord1), head(dw2_ptr))) {
                cout << head(docWord1) << endl;
            }

            dw2_ptr = tail(dw2_ptr);
        }
        docWord1 = tail(docWord1);
    }

    
}

int main() {
    int indexDim;
    parola *index = load(indexDim);

    stampa(index, indexDim);

    cout << endl << "Aggiornato:" << endl;
    update(index, "doc", indexDim);
    stampa(index, indexDim);

    return 0;
}
