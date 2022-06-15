/*
Un picco di una sequenza S di valori è un elemento strettamente maggiore dei
suoi due elementi contigui o maggiore dell’elemento contiguo, se l’altro manca.
Esempio: Nella sequenza [4, 3, 3, 3, 0, −1, 3, −3, 4, 2], 4, 3 e 4 sono picchi.
Data una sequenza di valori interi memorizzati in una lista doppia dichiarata
sotto, si scriva la funzione ricorsiva int picchi(lista) che restituisce il
numero di picchi contenuti nella lista.
Esempio: Sulla sequenza [4, 3, 3, 3, 0, −1, 3, −3, 4, 2] deve restituire 3.
*/

struct elem {
    int inf;
    elem* pun;
    elem* prev;
};
typedef elem* lista;

int picchi(lista l) {
    int count = 0;
    
    while(l) {
        if(prev(l) && tail(l)) {
            if(head(l) > head(tail(l)) && head(l) > head(prev(l)))
                count++;
        } else if (prev(l)) {
            if(head(l) > head(prev(l)))
                count++;
        } else if(head(l) > head(tail(l)))
            count++;

        l = tail(l);
    }

    return count;
}