#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<string.h>

#define nelem 6

void *funzione(int *vet){
    int comodo;
    for(int i = 0; i < nelem; i++){
        for(int j = i + 1; j < nelem; j++){
            if(vet[i] > vet[j]){
                comodo = vet[i];
                vet[i] = vet[j];
                vet[j] = comodo;
            }
        }
    }
    return;
}

void lentini(int *vet, int n){
    int comodo;
    for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
            if(vet[i] > vet[j]){
                comodo = vet[i];
                vet[i] = vet[j];
                vet[j] = comodo;
            }
        }
    }
    return;
}

int main(int argc, char **argv){

    int n = atoi(argv[1]);
    int MTot[n][nelem];
    char Nuno[20], Ndue[20];
    char nomeN[200];
    pthread_t id[n];
    FILE *fin, *fout;
    int vf[n*nelem];
    int z = 0;
    int j = 0;

    for(int i = 0; i< n*nelem;i++){
        vf[i]=10000;
    }

    strcpy(Nuno,argv[2]);
    strcpy(Ndue,argv[3]);

    for(int i = 0; i<n ;i++){
        sprintf(nomeN,"%s%d.txt",Nuno,i+1);
        fin = fopen(nomeN, "r");
        for(j = 0; j<nelem ; j++){
            fscanf(fin, "%d",&MTot[i][j]);
        }
    }

    for(int i = 0; i<n ; i++){
        pthread_create(&id[i],NULL,funzione,(void *) &MTot[i]);
        pthread_join(id[i],NULL);

        z = 0;
        for(j = i*nelem;j<i*nelem+nelem;j++){
            vf[j] = MTot[i][z];
            z++;
        }
        lentini(vf, j);
    }
    sprintf(nomeN,"%s.txt",Ndue);
    fout = fopen(nomeN, "w");
    for(int i = 0;i<n*nelem;i++){
        fprintf(fout,"%d\n",vf[i]);
    }


}