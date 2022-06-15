/*******************************/
/* HEADER MODULO "tipo" */
/*******************************/




typedef struct{
	int id;
	char nome[21];
	char tipo;} tipo_inf;

int compare(tipo_inf,tipo_inf);
void copy(tipo_inf&,tipo_inf);
void print(tipo_inf);
