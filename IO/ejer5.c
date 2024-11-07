#include <stdio.h>
#include <stdlib.h>


int main (){

FILE * readFile;
char caca[100];

readFile = fopen("source.txt", "r");

if(readFile==NULL){
  printf("Ha ocurrido un error");
  return 1;
}

int cont = 0;

while (!feof(readFile))
{
  if(fscanf(readFile, "%s", caca)!=EOF)
    cont++;
}

printf("\n La cantidad de palabras en el texto es: %d\n", cont);


fclose(readFile);


return 0;
}
