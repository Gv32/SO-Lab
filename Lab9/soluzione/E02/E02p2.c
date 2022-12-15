#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<pthread.h>
#include<semaphore.h>

typedef struct{
    float c, x;
    int n;
}monomio;

int file,n ;
sem_t S1,S2,S3,S4;
pthread_t T1,T2,T3,T4;
float v1,v2,v3;

void *calcolo1(){
    while(1){
        sem_wait(&S1);
        monomio m;
        float tot = 1;
        n = read(file, &m, sizeof(monomio));
        if(n <= 0){
            printf("chiusura Thread 1\n");
            sem_post(&S2);
            break;
        }
        for(int i = 0; i < m.n;i++){
            tot = tot * m.x;
        }
        v1 = tot + m.c;
        sem_post(&S2);
    }

    pthread_exit ((void *) 1);
}

void *calcolo2(){
    while(1){
        sem_wait(&S2);
        monomio m;
        if(n <= 0){
            printf("chiusura Thread 2\n");
            sem_post(&S3);
            break;
        }
        read(file, &m, sizeof(monomio));
        float tot = 1;
        for(int i = 0; i < m.n;i++){
            tot = tot * m.x;
        }
        v2 = tot + m.c;
        sem_post(&S3);
    }

    pthread_exit ((void *) 1);
}

void *calcolo3(){
    while(1){
        sem_wait(&S3);
        monomio m;
        if(n <= 0){
            printf("chiusura Thread 3\n");
            sem_post(&S4);
            break;
        }
        read(file, &m, sizeof(monomio));
        float tot = 1;
        for(int i = 0; i < m.n;i++){
            tot = tot * m.x;
        }
        v3 = tot + m.c;
        sem_post(&S4);
    }

    pthread_exit ((void *) 1);
}

void *calcolo4(){
    while(1){
        sem_wait(&S4);
        if(n <= 0) {
            break;
            }
        float tot = v1 + v2 + v3;
        printf("Totale: %f\n",tot);
        sem_post(&S1);
    }
    printf("chiusura Thread 4\n");
    pthread_exit ((void *) 1);
}

int main(int argc, char *argv[]){
    file = open(argv[1], O_RDONLY);

    sem_init(&S1,0,1);
    sem_init(&S2,0,0);
    sem_init(&S3,0,0);
    sem_init(&S4,0,0);

    pthread_create(&T1,NULL,calcolo1,NULL);
    pthread_create(&T2,NULL,calcolo2,NULL);
    pthread_create(&T3,NULL,calcolo3,NULL);
    pthread_create(&T4,NULL,calcolo4,NULL);

    pthread_join (T1, NULL);
    pthread_join (T2, NULL);
    pthread_join (T3, NULL);
    pthread_join (T4, NULL);

}