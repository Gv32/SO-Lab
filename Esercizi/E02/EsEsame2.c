#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

int a = 0,b = 0,c = 0;

static void handler(int sig){
    if(sig == SIGUSR1){
        printf("Segnale ricevuto da P1\n");
        c = b;
        b = a;
        a = 1;
        printf("%d %d %d\n", a,b,c);
    }else if(sig == SIGUSR2){
        printf("Segnale ricevuto da P2\n");
        c = b;
        b = a;
        a = 2;
        printf("%d %d %d\n", a,b,c);
    }
    if(a == b && a == c){
        kill(0, SIGKILL);
    }
}

int main(){
    signal(SIGUSR1, handler);
    signal(SIGUSR2, handler);

    srand(time(NULL));

    if(fork()){
        if(!fork()){
            while(1){
                sleep(rand()%3);
                kill(getppid(),SIGUSR1);
            }
        }else{
            while(1){
                pause();
            }
        }
    }else{
        while(1){
            sleep(rand()%2);
            kill(getppid(),SIGUSR2);
        }
    }
}