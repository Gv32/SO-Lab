#include <stdio.h>
#include <stdlib.h>
#include <fnctl.h>
#include <unistd.h>
#include <pthread.h>


void *A(){
    signal(&B);
    wait(&A);
}

void *B(){
    signal(&A);
    wait(&B);
}

int main(){
    init(&A,0,0);
    init(&B,0,0);
}