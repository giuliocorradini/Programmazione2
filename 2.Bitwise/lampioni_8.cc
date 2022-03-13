/*
Bisogna gestire lo stato di illuminazione di una strada in termini di lampioni funzionanti.
La lista dei lampioni funzionanti è mantenuta attraverso una configurazione di bit (supponiamo 8 bit).
Ad ogni lampione è associato un bit della configurazione, che ne indica lo stato: 1 se il lampione è funzionante, 0 se il lampione è guasto.
Le funzioni previste sono:
1.aggiornamento dello stato di un lampione, che puo' guastarsi o essere riparato
2.stampa dei lampioni funzionanti
3.controllo se i lampioni possono funzionare in modalità risparmio energetico, ovvero quelli di indice pari accesi e quelli di indice dispari spenti.
Nota bene: per essere verificata, tutti i lampioni di indice pari devono essere accesi e tutti quelli di indice pari spenti.

Utilizzare una sola funzione ausiliaria per guastare/riparare lampioni. All'inizio tutti i lampioni gestiti dal programma sono funzionanti.
Il programma deve fornire il seguente menù: Gestione lampioni
Comandi disponibili:
G Segnalare guasto ad un lampione
R Segnalare riparazione di un lampione
L Stampa lista lampioni funzionanti
K Controllo risparmio energetico
T Termina

VERSIONE A 8 LAMPIONI

(c) Giulio Corradini - 2022
*/

#include <iostream>
using namespace std;

inline void stampa_menu() {
    cout << "Gestione lampioni"                         << endl
         << "Comandi disponibili:"                      << endl
         << "G Segnalare guasto ad un lampione"         << endl
         << "R Segnalare riparazione di un lampione"    << endl
         << "L Stampa lista lampioni funzionanti"       << endl
         << "K Controllo risparmio energetico"          << endl
         << "T termina"                                 << endl;
}

enum stato_t {
    GUASTO,
    RIPARATO
};

/*
 *  Aggiorna lo stato della fila andando a marcare un lampione come guasto o funzionante.
 *
 *  @param stato_lampioni Reference a un bit vector che rappresenta lo stato dei lampioni.
 *  @param lampione Numero del lampione di cui si vuole cambiare lo stato.
 *  @param stato Valore della enum che indica se il lampione è guasto (0) o riparato (1)
 */
void aggiorna_stato(unsigned int &stato_lampioni, unsigned int lampione, enum stato_t stato) {
    lampione &= 0xff;

    stato_lampioni &= ~(1 << lampione);     //pulisci il bit lampione-esimo
    stato_lampioni |= stato << lampione;    //imposta se stato=1
}

bool risparmio_energetico(unsigned int &stato_lampioni) {
    return (stato_lampioni & 0x55) == 0x55;
}

int main() {

    unsigned int stato_lampioni = 0xff;     //8 lampioni funzionanti
    unsigned int lampione;

    char scelta;

    do {
        stampa_menu();
        cin >> scelta;

        switch(scelta) {
            case 'G':
                cout << "Che lampione si è guastato? ";
                cin >> lampione;
                aggiorna_stato(stato_lampioni, lampione, GUASTO);
                break;

            case 'R':
                cout << "Che lampione hai riparato? ";
                cin >> lampione;
                aggiorna_stato(stato_lampioni, lampione, RIPARATO);
                break;

            case 'L':
                cout << "7 - - - - - - 0" << endl;

                for(int i=7; i>=0; i--)
                    cout << ((stato_lampioni & (0x01 << i)) >> i) << ' ';
                
                cout << endl;
                break;

            case 'K':
                if(risparmio_energetico(stato_lampioni))
                    cout << "I lampioni possono funzionare in risparmio energetico." << endl;
                else
                    cout << "Risparmio energetico non consentito." << endl;
                break;

            case 'T':
                cout << "Arrivederci" << endl;
                break;

            default:
                cout << "Opzione non valida" << endl;
                break;
        }

    } while(scelta != 'T');

    return 0;
}