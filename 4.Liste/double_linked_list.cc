/*
 *  Esempio di gestione di una double linked list, con implementazione della struttura dati
 *  e delle primitive per operare su di essa.
 * 
 *  Il programma consente all'utente di accedere ad una lista di URL.
 *  Il programma presenta un menù all'utente che può
 *  • creare una lista di n URL– ogni URL ha al più 50 caratteri - attraverso la funzione insert_elem()
 *  • cancellare un URL dato dalla lista attraverso la funzione delete_elem()
 *  • stampare la lista attraverso head() e tail()
 *  • cercare un URL nella lista e quindi consentire all'utente di muoversi a piacere avanti (F-forward) 
 *     e indietro (B-backward) nella lista a partire dalla posizione del sito cercato
 *     fino a quando non digita S-stop, utilizzando search()
 *
 *  (c) Giulio Corradini - 2022 
 */

#include <iostream>
#include <cstring>
using namespace std;

struct element_t {
    char info[51];
    struct element_t *prev;
    struct element_t *next;
};

typedef struct element_t * list;

char * head(list l) {
    return l->info;
}

list tail(list l) {
    return l->next;
}

void list_print(list l) {
    while(l) {
        cout << head(l) << endl;

        l = tail(l);
    }

    cout << endl;
}

list insert_element(list l, element_t *e) {
    e->next = l;
    e->prev = nullptr;

    if(l)
        l->prev = e;

    return e;
}

list delete_element(list l, element_t *e) {
    if(l == e) {
        l = tail(l);
        if(l)
            l->prev = nullptr;
    } else {
        list l1 = l;
        
        while((l1 = tail(l1))) {
            if(l1 == e) {
                l1->prev->next = l1->next;
                if(l1->next)
                    l1->next->prev = l1->prev;
            }
        }
    }

    return l;
}

list list_create(int n, istream &in) {
    list l = nullptr;

    for(int i=0; i<n; i++) {
        element_t *e = new element_t;
        in >> e->info;
        l = insert_element(l, e);
    }
    
    return l;
}

void list_destroy(list l) {
    element_t *lastElement;

    while(l) {
        lastElement = l;
        l = tail(l);
        delete lastElement;
    }
}

element_t *search(list l, char *v) {
    while(l != nullptr) {
        if(strcmp(head(l), v) == 0)
            return l;

        l = tail(l);
    }

    return nullptr;
}

list delete_value(list l, char *v) {
    element_t *currentPointer = l;

    while(currentPointer) {

        if(strcmp(head(currentPointer), v) == 0) {
            l = delete_element(l, currentPointer);
        }
        
        currentPointer = tail(currentPointer);
    }

    return l;
}

enum direction_t {
    FORWARD,
    BACKWARD
};

element_t * crawl(element_t *e, direction_t d) {
    if(d == FORWARD)
        return e->next;
    else
        return e->prev;
}

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
                        if(!currentCrawling)
                            cout << "Fine della lista" << endl;
                        else
                            cout << head(currentCrawling);
                        cin >> crawlAction;

                        switch(crawlAction) {
                            case 'F':
                                currentCrawling = crawl(currentCrawling, FORWARD);
                            break;
                            case 'B':
                                currentCrawling = crawl(currentCrawling, BACKWARD);
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
