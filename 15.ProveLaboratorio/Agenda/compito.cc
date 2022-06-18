#include <iostream>
#include <fstream>
#include "lista.h"
using namespace std;

/*
 *  Aggiunge un evento in agenda. Se l'inizio dell'evento coincide con un evento già presente (come ora di inizio
 *  e data) viene stampato un messaggio di errore.
 */
void agenda(lista &ag, tipo_inf a) {
    if(!search(ag, a)) {
        elem *e = new_elem(a);
        ag = insert_elem(ag, e);
    } else {
        cout << "Non posso inserire " << a.descr << " perché c'è già un evento il " << a.data << " alle " << a.ora_i << endl;
    }
}

/*
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

/*
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

int main() {
    lista ag = nullptr;
    carica(ag);
    stampa(ag);

    return 0;
}