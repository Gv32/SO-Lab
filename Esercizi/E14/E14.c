#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <semaphore.h>

#define N_r 10

sem_t S1,SM;
int risorse[N_r] = {0};

int request(){
    sem_wait(&S1);
    sem_wait(&SM);
    for (int i = 0 ; i < N_r;i++){
        if(risorse[i] == 0){
            risorse[i]=1;
            sem_post(&SM);
            break;
        }
    }
    return i;
}

void release(int i){
    sem_wait($SM);
    risorse[i] = 0;
    sem_post(&S1);
    sem_post(&SM);
}


int main(){

    sem_init(&S1,0,N_r);
    sem_init(&S1,0,1);

}