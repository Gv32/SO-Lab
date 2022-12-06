#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

void binary(int *vet, int n){
    int i, j;
    pid_t pid1, pid2;

    for (i=0; i<=n; i++) {
        if (i == n) {
            for (j=0; j<n; j++) {
                printf("%d", vet[j]);
            }
            printf("\n");
            exit (0);
            } else {
            pid1 = fork ();       
            if (pid1 == 0) {
                // Child 1
                vet[i] = 0;
            } else {
                // Father
                pid2 = fork ();       
                if (pid2 == 0) {
                // Child 2
                vet[i] = 1;
                } else {
                wait ((int *) 0);
                wait ((int *) 0);
                exit (1);
                }
            }
        } 
    }
    exit (0);
}

int main(int argc, char **argv){
    int numero;
    int *vet;

    numero = atoi(argv[1]);
    vet = (int *)malloc(numero * sizeof(int));
    if (vet == NULL){
        printf("Allocatin Error.\n");
        exit(1);
    }
    printf("Numeri binari:\n");
    binary(vet,numero);
    free(vet);
}
