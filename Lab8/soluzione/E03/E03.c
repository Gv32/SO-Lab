#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <semaphore.h>
#include <pthread.h>

typedef struct{
    sem_t S1;
    sem_t S2;
    sem_t S3;
    sem_t S4;
}Semaforo;

void B(Semaforo *sem){

    sem_wait(&sem->S1);
    printf("B\n");
    sem_post(&sem->S4);
    //I(S1,S2,S3,S4);
    return;

}

void C(Semaforo *sem){
    sem_wait(&sem->S1);
    printf("C\n");
    sem_post(&sem->S2);
    sem_post(&sem->S2);
}

void E(Semaforo *sem){
    sem_wait(&sem->S2);
    printf("E\n");
    sem_post(&sem->S3);
    //G(S1,S2,S3,S4);
    return;
}

void F(Semaforo *sem){
    sem_wait(&sem->S2);
    printf("F\n");
    sem_post(&sem->S3);
    //G(S1,S2,S3,S4);
    return;
}

void G(Semaforo *sem){
    sem_wait(&sem->S3);
    sem_wait(&sem->S3);
    printf("G\n");
    sem_post(&sem->S4);
    //I(S1,S2,S3,S4);
    return;
}

void D(Semaforo *sem){
    sem_wait(&sem->S1);
    printf("D\n");
    printf("H\n");
    sem_post(&sem->S4);
    //I(S1,S2,S3,S4);
    return;
}

void I(Semaforo *sem){
    sem_wait(&sem->S4);
    sem_wait(&sem->S4);
    sem_wait(&sem->S4);
    printf("I\n");
    return;
}

int main(){
    sem_t S1;
    sem_t S2;
    sem_t S3;
    sem_t S4;

    sem_init(&S1,0,0);
    sem_init(&S2,0,0);
    sem_init(&S3,0,0);
    sem_init(&S4,0,0);

    Semaforo sem;

    sem.S1 = S1;
    sem.S2 = S2;
    sem.S3 = S3;
    sem.S4 = S4;

    pthread_t id[7];

    while(1){
        
        printf("A\n");

        sem_post(&sem.S1);
        sem_post(&sem.S1);
        sem_post(&sem.S1);
        pthread_create(&id[0],NULL,B,&sem);
        pthread_create(&id[1],NULL,C,&sem);
        pthread_create(&id[2],NULL,D,&sem);
        pthread_create(&id[3],NULL,E,&sem);
        pthread_create(&id[4],NULL,F,&sem);
        pthread_create(&id[5],NULL,G,&sem);
        pthread_create(&id[6],NULL,I,&sem);

        sleep(2);
        printf("\n");

    }

}