#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>


int main (){
	int v;	
	int fout;
	char nomeFile[20]={"output.txt"};
	fout = creat (nomeFile, 0666);
	int vet[4] = {3,4,5,6};
	for(int i =0;i<4;i++){
		write(fout,&vet[i],sizeof(int));
		}
	close(fout);
	fout = open (nomeFile, O_RDONLY);
	for (int i=3 ; i>=0; i--){
		lseek (fout,i*sizeof(int),SEEK_SET);
		read (fout, &v, sizeof(int));
		printf("%d",v);
		}
	close(fout);
}
