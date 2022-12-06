#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<string.h>

typedef struct{
    char nomein[200];
    char nomeout[200];
} trarg;

void *funzione(trarg *diz){
    FILE *fin, *fout;
    fin = fopen(diz->nomein,"r");
    fout = fopen(diz->nomeout, "w");
    int ntot;
    int vet[20];
    int comodo;
    fscanf(fin, "%d", &ntot);
    for (int i = 0; i< ntot; i++){
        fscanf(fin, "%d", &vet[i]);
    }
    
    for(int i = 0; i < ntot - 1; i++){
        for(int j = i + 1; j < ntot; j++){
            if(vet[i] > vet[j]){
                comodo = vet[i];
                vet[i] = vet[j];
                vet[j] = comodo;
            }
        }
    }

    for(int i = 0; i<ntot;i++){
        fprintf(fout,"%d\n", vet[i]);
    }


    return;
}

int main(int argc, char **argv){

    int n = atoi(argv[1]);
    char Nuno[20], Ndue[20];
    strcpy(Nuno,argv[2]);
    strcpy(Ndue,argv[3]);
    trarg diz[n];

    pthread_t id[n];

    for(int i = 0; i<n ;i++){
        sprintf(diz[i].nomein,"%s%d.txt",Nuno,i+1);
        sprintf(diz[i].nomeout,"%s%d.txt",Ndue,i+1);
    }
    for(int i = 0; i<n ; i++){
        pthread_create(&id[i],NULL,funzione,(void *) &diz[i]);
    }

    pthread_exit(NULL);
}