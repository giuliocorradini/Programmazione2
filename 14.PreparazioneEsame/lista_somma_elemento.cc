lista somma_elemento(lista l, int p) {
    lista cursore = l;

    //cerca il valore del p-esimo elemento
    for(int i=0; i<p; i++) {
        cursore = tail(cursore);
    }

    int valore_da_sommare = head(cursore);
    cursore = l;

    while(cursore) {
        cursore->inf += valore_da_sommare;

        cursore = tail(cursore);
    }

    return l;
}