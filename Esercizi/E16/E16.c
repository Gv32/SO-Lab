#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

char stato[10]="RED";
sem_t SR,SG;
int conta[2];

sem_init(&SR,0,1);
sem_init(&SG,0,0);

void change(){
    if(strcmp(stato,"RED")==0){
        strcpy(stato,"GREEN");
        for(int i = 0;i<conta[1];i++){
            sem_post(&SG);
        }
    }else{
        strcpy(stato,"RED");
        for(int i = 0;i<conta[0];i++){
            sem_post(&SR);
        }
    }
}

void red(){
    if(strcmp(stato,"RED")!=0){
        conta[0] = conta[0] + 1;
        sem_wait(&SR);
    }
    SC();
}

void green(){
    if(strcmp(stato,"GREEN")!=0){
        conta[1] = conta[1] + 1;
        sem_wait(&SG);
    }
    SC();
}