#include <stdio.h>
#include <stdlib.h>


int main (){

FILE * readFile;
FILE * writeFile;

readFile = fopen("source.txt", "r");
writeFile = fopen("target.txt", "w");

if(readFile==NULL){
  printf("Ha ocurrido un error");
  return 1;
}

char string[200];

while (!feof(readFile))
{
  fputs(string, writeFile);
  fgets(string, 200, readFile);
}


fclose(readFile);
fclose(writeFile);


return 0;
}
