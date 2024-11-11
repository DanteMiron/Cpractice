#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int comparar(const void *a, const void *b) {
    // Convertir los punteros void a punteros a cadenas de caracteres
    const char *str1 = *(const char **)a;
    const char *str2 = *(const char **)b;

    // Comparar las cadenas utilizando strcmp
    return strcmp(str1, str2);
}

int main (){

FILE * readFile;

readFile = fopen("nombres.txt", "r");
FILE * writeFile = fopen("nombres-ordenados.txt", "w");



if(readFile==NULL){
  printf("Ha ocurrido un error");
  return 1;
}
int sizeArray = 0;

char * nombre = (char*)malloc(20*sizeof(char));

while (!feof(readFile))
{
  if(fscanf(readFile, "%s", nombre)!=EOF)
    sizeArray++;
}

char ** nombres = (char**)malloc(sizeArray*sizeof(char*));
rewind(readFile);
int cont = 0;
while (!feof(readFile))
{ 
  if(fscanf(readFile, "%s", nombre)!=EOF){
    nombres[cont] = (char*)malloc(20*sizeof(char));
    printf("%s \n", nombre);
    strcpy(nombres[cont], nombre);
    cont++;
  }
}

qsort(nombres, sizeArray, sizeof(char *), comparar);

for(int i = 0; i<sizeArray; i++)
{
  fprintf(writeFile, "%d %s \n"  , i+1,nombres[i]);
}



fclose(readFile);


return 0;
}
