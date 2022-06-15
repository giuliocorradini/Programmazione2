/*
Data una sequenza di valori interi memorizzati in una lista doppia dichiarata sotto,
si scriva la funzione int max(elem*) che dato un elemento della lista (posizione non nota)
conta il numero di valori nella sequenza maggiori del valore dell’elemento in ingresso.
La funzione deve implementare l’algoritmo con un solo ciclo.
*/

struct elem {
    int inf;
    elem* pun;
    elem* prev;
};

int max(elem* e) {
    int count = 0;
    elem *sx_cursor = prev(e);
    elem *dx_cursor = next(e);

    while(sx_cursor || dx_cursor) {
        if(sx_cursor && head(sx_cursor) > head(e)) {
            count++;
            sx_cursor = prev(sx_cursor);
        }

        if(dx_cursor && head(dx_cursor) > head(e)) {
            count++;
            dx_cursor = tail(dx_cursor);
        }
    }

    return count;
}