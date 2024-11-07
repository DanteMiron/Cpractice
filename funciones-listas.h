#ifndef TDA_PILA_H
#define TDA_PILA_H
#define TAMMAX 25

typedef struct Nodo{
	char legislador[TAMMAX];
	struct Nodo * sgte;
}chicos;

typedef struct Nodo * pchicos;

pchicos chicos_buenos, chicos_malos;

void mostrar(pchicos);
void inserta(char *, chicos**);
void suprime(char *, chicos**);
int miembro(char * legislador, pchicos * l);
void cadena_minuscula(char * cadena);
void menu();


#endif
