#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (){

FILE * readFile;
char caca[100];

readFile = fopen("nombres.txt", "r");

if(readFile==NULL){
  printf("Ha ocurrido un error");
  return 1;
}

int tamañoArray = 6;

int i = 0;
char * nombres[tamañoArray];

while (!feof(readFile))
{
  if(fscanf(readFile, "%s", caca)!=EOF){
  strcpy(*(nombres+i), caca);
  printf("%s", nombres[i]);
  i++;
  }
}
printf("%d", i);








printf("\n La cantidad de palabras en el texto es: %d\n", tamañoArray);


fclose(readFile);


return 0;
}
