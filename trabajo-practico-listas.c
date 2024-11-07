#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funciones-listas.h"



int main(){

chicos_buenos = NULL;
chicos_malos = NULL;

printf("\t\t\t\t********************************************************\n");
printf("\t\t\t\t*******Taller de programacion II / Ejercicio TDA********\n");
printf("\t\t\t\t********************************************************\n");

menu();

return 0;
}

void menu(){

char temaVotacion[100];

printf("Indique que proyecto de ley vamos a tratar: ");
fgets(temaVotacion, 100, stdin);
cadena_minuscula(temaVotacion);

printf("\n\t ---- Votacion a tratar: %s ---- \n", temaVotacion);
printf("\n\n Empezamos con el conteo de votos de los legisladores\n");
printf("\n--- Recuerde tipear (F)avorable, (D)esfavorable o (E)xit ---");

char mandato;
char legislador[TAMMAX];
while(mandato!='E')
{ 
  do {
  printf("\nTipo de voto: ");
  scanf("%c", &mandato);
  getchar();
  } while (mandato != 'F' && mandato != 'D' && mandato != 'E');
  
  if(mandato!='E'){
  printf("Nombre del Legislador: ");
  fgets(legislador, TAMMAX, stdin);
    
    cadena_minuscula(legislador);
  
    if(miembro(legislador, &chicos_buenos) && (mandato == 'D'))
    { 
      printf("\nEl voto de %s que pertenecia a Chicos Buenos fue desfavorable, ahora pertenecera a Chicos Malos", legislador);
      suprime(legislador, &chicos_buenos);
      inserta(legislador, &chicos_malos);
    } 
    else if(miembro(legislador, &chicos_malos) && (mandato == 'F'))
    {
      printf("\nEl voto de %s que pertenecia a Chicos Malos fue favorable, ahora pertenecera a Chicos Buenos", legislador);
      suprime(legislador, &chicos_malos);
      inserta(legislador, &chicos_buenos);
    }
    else if( !miembro(legislador, &chicos_malos) && !miembro(legislador, &chicos_buenos))
    {
        if(mandato=='F')
        {
          printf("\n%s es un nuevo legislador y sera agregado a Chicos Buenos", legislador);
          inserta(legislador, &chicos_buenos);
        } 
        else
        {
          printf("\n%s es un nuevo legislador y sera agregado a Chicos Malos", legislador);
          inserta(legislador, &chicos_malos);
        }
    }
    else
    mandato=='F'?printf("\nEl legislador %s se mantiene en Chicos Buenos", legislador):printf("\nEl legislador %s se mantiene en Chicos Malos", legislador);
  } 

}

printf("\n-----Chicos Buenos----\n");
mostrar(chicos_buenos);

printf("\n-----Chicos Malos----\n");
mostrar(chicos_malos);

char votacion;
printf("\n\nDesea realizar otra votacion? (S/n) \n>");
scanf("%c", &votacion);
votacion = tolower(votacion);
if(votacion=='s')menu();

}



void cadena_minuscula(char * cadena){
      for (int indice = 0; cadena[indice] != '\0'; ++indice)
      {
	    cadena[indice] = tolower(cadena[indice]);
	    if(cadena[indice]== '\n')cadena[indice]='\0';
      }
}




void inserta(char * nuevoLegislador, pchicos * l){

    if(*l==NULL)
    {
        *l = (pchicos)malloc(sizeof(chicos));
        if((*l)==NULL)
        {
          printf("No se pudo reservar memoria para newNodo");
          return;
        }
        strcpy((*l)->legislador, nuevoLegislador);
    }
    else
    {
        if(strcmp((*l)->legislador, nuevoLegislador)>0)
        {
          pchicos nuevoNodo = (pchicos)malloc(sizeof(chicos));
          if(nuevoNodo==NULL)
          {
          printf("No se pudo reservar memoria para newNodo");
          return;
          }
          strcpy(nuevoNodo->legislador, nuevoLegislador);
          nuevoNodo->sgte = *l;
          *l = nuevoNodo;
        } 
        else if (strcmp((*l)->legislador, nuevoLegislador)<0 && (*l)->sgte != NULL && strcmp((*l)->sgte->legislador, nuevoLegislador)>0)
        {
          pchicos nuevoNodo = (pchicos)malloc(sizeof(chicos));
          if(nuevoNodo==NULL)
          {
          printf("No se pudo reservar memoria para newNodo");
          return;
          }
          strcpy(nuevoNodo->legislador,nuevoLegislador);
          nuevoNodo->sgte = (*l)->sgte;
          (*l)->sgte = nuevoNodo;
        }
        else if (strcmp((*l)->legislador, nuevoLegislador)==0)
        {
          printf("Nodo ya existente");
        }
        else
        {
          inserta(nuevoLegislador, &(*l)->sgte);
        }
     
    }
}

void mostrar ( pchicos l ) {
    if( l != NULL ) 
    {
      printf ("%s\n" , l->legislador) ;
      mostrar ( l->sgte ) ;
    }
}

void suprime(char * legislador, pchicos * l)
{
  if(*l == NULL)
  {
    printf("\nNo existe elemento para borrar\n");
  }
  else
  {
    if(strcmp((*l)->legislador,legislador)==0)
    {
      printf("\nEliminando de la lista al legislador: %s\n", legislador);
      pchicos aux = (*l);
      *l = (*l)->sgte;
      free(aux);
    }
    else if(strcmp(legislador,(*l)->legislador) > 0 && (*l)->sgte != NULL &&  strcmp((*l)->sgte->legislador, legislador) == 0)
    {
      printf("\nEliminando de la lista al legislador: %s\n", legislador);
      pchicos aux = (*l)->sgte;
      (*l)->sgte = (*l)->sgte->sgte;
      free(aux);
    }
    else
      suprime(legislador, &(*l)->sgte);
  }
}

int miembro(char * legislador, pchicos * l)
{
  if(*l == NULL)
    return 0;
  else if(strcmp((*l)->legislador, legislador) == 0)
    return 1;
  else
    miembro(legislador, &(*l)->sgte);
}


