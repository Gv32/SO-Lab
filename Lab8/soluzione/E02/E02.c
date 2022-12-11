#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void semaphore_init (int *S){
    if(pipe (S) == -1){
        printf("errore");
        exit(1);
    }
    return;
}

void semaphore_signal (int *S){
    char ctr = 'X';
    if(write(S[1],&ctr,sizeof(char))!=1){
        printf("errore");
        exit(2);
    }
    return;
}

void semaphore_wait (int *S){
    char crt;
    if(read(S[0],&crt,sizeof(char))!=1){
        printf("errore");
        exit(3);
    }
    return;
}

void B(int *S1,int *S2,int *S3,int *S4){

    semaphore_wait(S1);
    printf("B\n");
    semaphore_signal(S4);
    //I(S1,S2,S3,S4);
    return;

}

void C(int *S1,int *S2,int *S3,int *S4){
    semaphore_wait(S1);
    printf("C\n");
    semaphore_signal(S2);
    semaphore_signal(S2);
    if(fork()!=0){
        if(fork()!=0){

        }
        else{
            E(S1,S2,S3,S4);
        }
    }
    else{
        F(S1,S2,S3,S4);
    }
    return;
}

void E(int *S1,int *S2,int *S3,int *S4){
    semaphore_wait(S2);
    printf("E\n");
    semaphore_signal(S3);
    //G(S1,S2,S3,S4);
    return;
}

void F(int *S1,int *S2,int *S3,int *S4){
    semaphore_wait(S2);
    printf("F\n");
    semaphore_signal(S3);
    G(S1,S2,S3,S4);
    return;
}

void G(int *S1,int *S2,int *S3,int *S4){
    semaphore_wait(S3);
    semaphore_wait(S3);
    printf("G\n");
    semaphore_signal(S4);
    //I(S1,S2,S3,S4);
    return;
}

void DH(int *S1,int *S2,int *S3,int *S4){
    semaphore_wait(S1);
    printf("D\n");
    printf("H\n");
    semaphore_signal(S4);
    I(S1,S2,S3,S4);
    return;
}

void I(int *S1,int *S2,int *S3,int *S4){
    semaphore_wait(S4);
    semaphore_wait(S4);
    semaphore_wait(S4);
    printf("I\n");
    return;
}

int main(){
    int S1[2];
    int S2[2];
    int S3[2];
    int S4[2];

    semaphore_init(S1);
    semaphore_init(S2);
    semaphore_init(S3);
    semaphore_init(S4);

    while(1){

        printf("A\n");
        semaphore_signal(S1);
        semaphore_signal(S1);
        semaphore_signal(S1);

        if(fork()!=0){
            if(fork()!=0){
                if(fork()!=0){

                }
                else{
                    DH(S1,S2,S3,S4);
                }
            }
            else{
                C(S1,S2,S3,S4);
            }
        }
        else{
            B(S1,S2,S3,S4);
        }

    exit(0);
    sleep(8);

    
    }

}