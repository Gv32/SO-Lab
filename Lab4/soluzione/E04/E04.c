#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<string.h>

static void handler(){
    return;    
}

void consumatore(){
    FILE *fin;
    char stringa[50];
    int i = 0;
    int ppr;

    while(1){
        pause();
        fin = fopen("scrittura.txt", "r");
        fscanf(fin, "%s",stringa);
        fclose(fin);

        if(strcmp(stringa, "end") == 0){
            exit(1);
        }
        i = 0;
        while(stringa[i] != '\0'){
            stringa[i] = stringa[i] - ('a' - 'A');
            printf("%c\n",stringa[i]);
            i++;
        }


        sleep(2);

        kill(0, SIGUSR1);
    }
}

void produttore(){
    FILE *fin;
    char stringa[50];

    int pidp = getpid();
    while(1){
        printf("Inserire la stringa:  ");
        scanf("%s", stringa);

        fin = fopen("scrittura.txt", "w");
        fprintf(fin, "%s\n",stringa);
        fclose(fin);


        kill(0, SIGUSR1);

        if(strcmp(stringa,"end") == 0){
            exit(1);
        }

        pause();

    }
}

int main(){
    signal(SIGUSR1, handler);

    char stringa[20];
        
    if(fork() == 0){
        consumatore();
    }else{
        if(fork() == 0){
            produttore();
        }else{
            wait((int*)0);
        }
    }
}
