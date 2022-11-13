#include<unistd.h>
#include<stdio.h>
#include<string.h>

int main(){
   FILE *fin;
   char comando[50];
   fin = fopen("File1","r");
   while(!feof(fin)){
      fgets(comando,50,fin);
      system(comando);
   }
}
