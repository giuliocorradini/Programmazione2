#include <iostream>
#include <fstream>
#include <cstring>
#include "lista.h"
using namespace std;

/**
 *  Aggiunge un evento in agenda. Se l'inizio dell'evento coincide con un evento già presente (come ora di inizio
 *  e data) viene stampato un messaggio di errore.
 *  L'inserimento è ordinato rispetto alla lista degli eventi.
 *  @param ag - Reference alla lista di eventi
 *  @param a - l'evento da inserire
 */
void agenda(lista &ag, tipo_inf a) {
    lista agptr = ag;
    lista last_elem = nullptr;

    if(ag == nullptr) {

        elem *e = new_elem(a);
        ag = e;

    } else {

        int cmp = 1;

        while(agptr && cmp > 0) {
            cmp = compare(a, head(agptr));

            if(cmp > 0) {
                last_elem = agptr;
                agptr = tail(agptr);
            }
        }


        if(cmp == 0)
            cout << "Non posso inserire " << a.descr << " perché c'è già un evento il " << a.data << " alle " << a.ora_i << endl;

        elem *e = new_elem(a);

        if(agptr == nullptr) { //&& cmp > 0 per forza, devo inserire in coda
            last_elem->pun = e;
            e->prev = last_elem;
        }

        else if(cmp < 0) { //inserimento prima del nodo agptr
            e->pun = agptr;
            e->prev = agptr->prev;
            agptr->prev = e;
            
            if(agptr == ag) //se devo inserire in testa
                ag = e;
            else
                e->prev->pun = e;
        }

    }
}

/**
 *  Stampa su stdout tutti gli eventi in agenda. Gli eventi potrebbero non essere stampati ordinati.
 *  @param l - la lista degli eventi in agenda
 */
void stampa(lista l) {
    while(l) {
        print(head(l));
        cout << endl;

        l = tail(l);
    }
}

/**
 *  Carica la lista di eventi per l'agenda leggendo da file. Utilizza il file "agenda.txt"
 *  nella directory corrente
 *  @param ag - la lista che rappresenta gli eventi in agenda
 */
void carica(lista &ag) {
    ifstream in("agenda.txt");

    char trash;
    tipo_inf evt;
    while(in) {
        in >> skipws >> evt.data >> evt.ora_i >> evt.ora_f >> noskipws >> trash;
        in.getline(evt.descr, 50);

        if(in)
            agenda(ag, evt);
    }

    in.close();
}

/**
 *  Stampa il numero di appuntamenti che precedono e seguono nello stesso giorno.
 *  @param agenda - puntatore alla lista degli eventi in agenda
 *  @param a - l'evento di cui cercare i precedenti e i successivi
 */
void quanti(lista agenda, tipo_inf a) {
    int prev=0, post=0;
    
    while(agenda) {
        if(strcmp(head(agenda).data, a.data) == 0) {
            int cmp = strcmp(a.ora_i, head(agenda).ora_i);
            
            if(cmp > 0)
                post++;
            else if (cmp < 0)
                prev++;
        }

        agenda = tail(agenda);
    }

    cout << prev << (prev!=1 ? " appuntamenti" : " appuntamento");
    cout << " prima e " << post << (post!=1 ? " appuntamenti" : " appuntamento") << " dopo" << endl;
}

int main() {
    lista ag = nullptr;
    carica(ag);
    stampa(ag);

    tipo_inf palestra;
    
    cout << "Inserisci i dati dell'appuntamento" << endl;
    cout << "Data: ";
    cin >> palestra.data;
    cout << "Ora di inizio: ";
    cin >> palestra.ora_i;

    quanti(ag, palestra);

    return 0;
}