#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>

void figlio( int fd, int j){
    int v1, v2;
    lseek(fd, j*sizeof(int), SEEK_SET);
    read(fd, &v1, sizeof(int));
    lseek(fd, (j+1)*sizeof(int), SEEK_SET);
    read(fd, &v2, sizeof(int));
    if(v1 > v2){
        lseek(fd, j*sizeof(int), SEEK_SET);
        write(fd, &v2, sizeof(int));
        lseek(fd, (j+1)*sizeof(int), SEEK_SET);
        write(fd, &v1, sizeof(int));
    }
}

int main (int argc,char **argv)
{
    int N = 10;
    char nome[10] = {"input.txt"};
    int vet[10] = {0,5,7,4,6,8,9,1,2,3};
    int i, j, v1, v2;
    int fd;
    fd = creat(nome, 0666);
    
    fprintf(stdout,"Salvo il vettore nel file\n");
    for(i = 0; i < 10; i++){
        write(fd, &vet[i], sizeof (int));
    }
    close(fd);
    
    fprintf(stdout,"Ordino\n");
    fd = open (nome, O_RDWR);
    for(i = 0; i < N-1;i++){
        for(j = 0; j < N - 1 - i; j++){
            if (fork() != 0){
                wait((int *) 0);
            }else{
                figlio(fd,j);
                exit(1);
            }
        }
    }
    close(fd);
    
    fprintf(stdout,"Stampo ordinato\n");
    fd = open(nome, O_RDONLY);
    for(i = 0; i < N; i++){
        lseek(fd, i*sizeof(int),SEEK_SET);
        read(fd, &v1, sizeof(int));
        fprintf(stdout, "%d", v1);
    }
    fprintf(stdout,"\n");
}

