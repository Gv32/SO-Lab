#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#define N 100

typedef struct record_s{
    int i;
    char s[N];
    float f;
}record_t;

int main(){
    int fd;
    record_t diz[30];
    char *riga;
    int posizione = 0;
    int not_end;
    int contriga = 1;
    int conta = 0;
    char c;

    
    fd = open("EsEsame.txt", O_RDONLY);
    do{
        riga = malloc(50*sizeof(char));
        do{
            not_end = read(fd,&c,sizeof (char));
            if(not_end != 0){
                riga[posizione] = c;
                posizione++;
            }
        }while(c!='\n');
        posizione = 0;
        if(not_end != 0){
            contriga++;
            sscanf(riga,"%d %s %f", &diz[conta].i, diz[conta].s, &diz[conta].f);
            conta++;
        }
        free(riga);
    }while(not_end != 0);

    for(int i = 0; i<conta;i++){
        printf("%d %s %f\n", diz[i].i, diz[i].s, diz[i].f);
    }

}