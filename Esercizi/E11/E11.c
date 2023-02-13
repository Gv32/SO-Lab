#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

sem_t SA,SB;
sem_t SC;
int i=0;

void *A(){
    sem_wait(&SA);
    printf("A%d ",i+1);
    sem_post(&SB);
    pthread_exit((void *) 0);
}

void *B(){
    sem_wait(&SB);
    printf("B%d\n",i+1);
    sem_post(&SC);
    pthread_exit((void *) 0);
}

int main(int argc,char **argv){
    sem_init(&SA,0,0);
    sem_init(&SB,0,0);
    sem_init(&SC,0,0);
    int N = atoi(argv[1]);
    pthread_t idA[N];
    pthread_t idB[N];
    for(i = 0;i<N;i++){
        pthread_create(&idA[i],NULL,A,NULL);
        pthread_create(&idB[i],NULL,B,NULL);
        sem_post(&SA);
        sem_wait(&SC);
    }
    pthread_exit((void *) 0);
}