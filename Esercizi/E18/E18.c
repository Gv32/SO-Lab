#include <stdio.h>
#include <stdlib.h>
#include <fnctl.h>
#include <unistd.h>

int fd[2];

void sem_init(){
    if (pipe(fd)==-1){
        printf("Errore inizializzaizone\n");
        exit(1);
    }
    return;
}

void wait(){
    char c;
    if(read(fd[0],&c,1)!=1){
        printf("Errore\n");
        exit(1);
    }
    return;
}

void signal(){
    char c="X";
    if(write(fd[0],&c,1)!=1){
        printf("Errore\n");
        exit(1);
    }
    return;
}