/*******************************/
/* HEADER MODULO "carta" 	   */
/*******************************/

struct tipo_inf {
    char nominativo[41];
    int punti;
    bool acquisto_oggi;
};

int compare(tipo_inf,tipo_inf);
void copy(tipo_inf&,tipo_inf);
void print(tipo_inf);
