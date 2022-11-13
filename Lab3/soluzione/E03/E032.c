#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(){
	FILE *fin;
	char comando[50];
	char parametri[10][50];
	char *vet[10];
	fin = fopen("File1","r");
	while(!feof(fin)){
		fscanf(fin,"%s",comando);
		int i=0;
		fscanf(fin,"%s",parametri[i]);
		vet[i] = &parametri[i];
		while(strcmp(parametri[i],"end")!=0){
			i++;
			fscanf(fin,"%s",parametri[i]);
			vet[i] = &parametri[i];
			
			}
			vet[i]=NULL;
		
		if(fork()==0){
			execvp(comando,vet);
			}
		else{sleep(3);}
	}
}
