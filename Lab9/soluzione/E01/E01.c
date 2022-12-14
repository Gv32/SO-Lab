#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include<semaphore.h>
#include<string.h>

void *leggi();
void *inverti();
void *scrivi();

sem_t S1,S2,S3;
pthread_t idA, idB, idC;
FILE *fpR, *fpW;
char line[102];

int main(int argc, char *argv[]){
    fpR = fopen(argv[1],"r");
    fpW = fopen(argv[2], "w");

    sem_init(&S1,0,1);
    sem_init(&S2,0,0);
    sem_init(&S3,0,0);

    pthread_create(&idA,NULL,leggi,NULL);
    pthread_create(&idB,NULL,inverti,NULL);
    pthread_create(&idC,NULL,scrivi,NULL);

    pthread_join (idA, NULL);
    pthread_join (idB, NULL);
    pthread_join (idC, NULL);
}

void *leggi(){
    int vai=1;
    printf("Thread lettura\n ");
    do {
    sem_wait (&S1);
    if (fgets (line, 102, fpR) == NULL) {
            strcpy (line, "quit");
            vai = 0;
        }
        sem_post (&S2);
    }while (vai==1);

    printf("Thread lettura chiuso\n");

    pthread_exit ((void *) 1); 
}

void *inverti(){
    printf("Thread inverti\n");
    int vai = 1;
    char c;
    int len, i;
    do{
        sem_wait(&S2);
        if (strcmp (line, "quit") == 0) {
            vai = 0;
        }else{  
            len = strlen (line) - 1;
            for (i=0; i<len; i++) {
                line[i] = toupper(line[i]);
            }
            for (i=0; i<((int) ((len-1)/2)); i++) {
                c = line[i];
                line[i] = line[len-1-i];
                line[len-1-i] = c;
            }
        }
        sem_post(&S3);
    }while(vai == 1);
    printf("Thread inverti chiuso\n");
    pthread_exit ((void *) 1); 
}

void *scrivi(){
    int vai = 1;
  
    printf("Thread scrittura\n");
  
    do {
        sem_wait (&S3);
        if (strcmp (line, "quit") == 0) {
        vai = 0;
        }else{   
            fprintf (fpW, "%s", line);
            sem_post(&S1);
        }
    }while (vai == 1);

  printf("Thread scrittura chiuso\n");
  
  pthread_exit ((void *) 1); 
}