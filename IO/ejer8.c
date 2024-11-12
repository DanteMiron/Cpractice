#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(){

FILE * readFile = fopen("documento.txt", "r");
FILE * writeFile = fopen("documento-modificado.txt", "w");

char word[25];

while(!feof(readFile)){
fscanf(readFile, "%s", word);
if(strcmp(word,"vieja")==0){
  fprintf(writeFile, "nueva ");
} else {
  fprintf(writeFile, "%s ", word);
}
}


fclose(readFile);
fclose(writeFile);


return 0;
}
