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

SOLUZIONE GENERALE

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

struct lampioni_t {
    unsigned int stato;
    const int num;
};

/*
 *  Aggiorna lo stato della fila andando a marcare un lampione come guasto o funzionante.
 *
 *  @param lampioni Reference alla struct che rappresenta lo stato dei lampioni.
 *  @param lampione Numero del lampione di cui si vuole cambiare lo stato.
 *  @param stato Valore della enum che indica se il lampione è guasto (0) o riparato (1)
 */
void aggiorna_stato(struct lampioni_t &lampioni, unsigned int lampione, enum stato_t stato) {
    unsigned int validation_mask = (1 << lampioni.num) - 1;

    lampioni.stato &= ~(1 << lampione) & validation_mask;       //pulisci il bit lampione-esimo
    lampioni.stato |= (stato << lampione) & validation_mask;    //imposta se stato=1
}

bool risparmio_energetico(struct lampioni_t &lampioni) {
    unsigned int even_mask =
        (1 << lampioni.num) - 1 & 0x55555555;                   //0x55 = b01010101, bit in pos. pari

    return (lampioni.stato & even_mask) == even_mask;
}

int main() {
    const int NUMERO_LAMPIONI = 20;
    static_assert(NUMERO_LAMPIONI > 0 && NUMERO_LAMPIONI < 32, "Imposta un numero di lampioni compreso tra 1 e 31");
    //  Disattivare il flag -Werror quando si usano 31 lampioni, altrimenti viene segnalato un
    //  possibile overflow quando si genera la maschera per i bit abilitati     --> (1<<num) - 1
    //      - shifting a sinistra più della dimensione del tipo int                 (1 << 32)
    //
    //  Il caso con 32 lampioni non funziona, per come sono generate le maschere in modo da
    //  coprire dinamicamente tutti i casi.

    struct lampioni_t lampioni = {
        .stato = (1 << NUMERO_LAMPIONI) - 1,
        .num = NUMERO_LAMPIONI,
    };

    unsigned int lamp;
    char scelta;

    do {
        stampa_menu();
        cin >> scelta;

        switch(scelta) {
            case 'G':
                cout << "Che lampione si è guastato? ";
                cin >> lamp;
                aggiorna_stato(lampioni, lamp, GUASTO);
                break;

            case 'R':
                cout << "Che lampione hai riparato? ";
                cin >> lamp;
                aggiorna_stato(lampioni, lamp, RIPARATO);
                break;

            case 'L':
                //Stampa "righello"
                for(int i=lampioni.num - 1; i>=0; i--) {
                    cout << ' ';
                    if(i % 8 == 0) cout << i;
                    else cout << '-';
                }
                cout << endl;

                //Stampa lampioni
                for(int i=lampioni.num - 1; i>=0; i--) {
                    cout << ' ' << ((lampioni.stato & (1 << i)) >> i);
                    if(i>=16 && i%8==0)
                        cout << ' ';
                }
                cout << endl;

                break;

            case 'K':
                if(risparmio_energetico(lampioni))
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