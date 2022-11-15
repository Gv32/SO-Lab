#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdlib.h>

static void handler(int sig){
    if(sig == SIGUSR2){
        printf("Father wake up\n");
    }else{
        printf("Child wake up\n");
    }
    return;
}

int main(){
    signal(SIGUSR1, handler);
    signal(SIGUSR2, handler);
    
    for(int i = 0; i < 5; i++){
        if(fork() != 0){
            sleep(1);
            kill(0, SIGUSR2);
            wait((int*)0);
        }else{
            kill(getpid(),SIGUSR1);
            exit(1);
            }
    }
    
}
