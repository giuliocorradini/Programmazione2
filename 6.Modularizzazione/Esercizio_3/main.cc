#include <iostream>
using namespace std;

#include "fun-app.h"

inline void print_menu() {
    cout << "Gestione della history del browser"                            << endl
         << " C - crea una lista di n URL"                                  << endl
         << " D - cancella un elemento dalla lista"                         << endl
         << " P - stampa la lista"                                          << endl
         << " S - cerca un URL nella lista e attiva modalità esplorazione"  << endl
         << " E - esci"                                                     << endl
         << endl << ">> ";
}

int main() {
    list history = nullptr;
    element_t *currentCrawling;
    char userMenuSelection;
    int urlNumber;
    char urlToDelete[51];
    char *urlToSearch = urlToDelete;
    char crawlAction;

    do {
        print_menu();
        cin >> userMenuSelection;

        switch(userMenuSelection) {
            case 'C':
                cout << "Quanti URL vuoi inserire? ";
                cin >> urlNumber;

                list_destroy(history);

                cout << "Adesso inserisci, separati da INVIO tutti gli URL (max 50 caratteri)" << endl;
                history = list_create(urlNumber, cin);
                break;

            case 'D':
                cout << "Che elemento vuoi cancellare? ";
                cin >> urlToDelete;

                delete_value(history, urlToDelete);
                break;

            case 'P':
                list_print(history);
                break;

            case 'S':
                cout << "Inserisci l'URL da cercare: ";
                cin >> urlToSearch;

                currentCrawling = search(history, urlToSearch);

                if(!currentCrawling)
                    cout << "Elemento non trovato" << endl;
                else {
                    cout << "Usa i tasti F e B navigare avanti (F) e indietro (B) nella history" << endl;
                    
                    do {
                        if(!currentCrawling) {
                            cout << "Fine della lista" << endl;
                            break;
                        } else
                            cout << head(currentCrawling);
                        cin >> crawlAction;

                        switch(crawlAction) {
                            case 'F':
                                currentCrawling = crawl(currentCrawling, FORWARD);
                            break;
                            case 'B':
                                currentCrawling = crawl(currentCrawling, BACKWARD);
                            break;
                            case 'S':
                            break;
                            default:
                                cout << "Azione non valida" << endl;
                                continue;
                        }
                    } while(crawlAction != 'S');

                }
                break;

            case 'E':
                cout << "Arrivederci" << endl;
                break;

            default:
                cout << "Operazione non consentita" << endl;
                break;
        }

    } while(userMenuSelection != 'E');

    return 0;
}
