#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char **argv){
    int fd1[2];
    int fd2[2];
    int conta = 0;
    int nmax = 0;
    char c;
    
    pipe(fd1);
    pipe(fd2);

    nmax = atoi(argv[2]);

    if(fork()!=0){

        while(1){
            if (conta == nmax && strcmp(argv[1],"F")==0){
                c = 'E';
                fprintf(stdout,"Father done\n");
                write(fd1[1],&c,1);
                exit(1);
            }
            if(strcmp(argv[1],"F")==0){
                c = 'F';
                fprintf(stdout,"I'm the father PID = %d\n", getpid());
                write(fd1[1], &c, 1);
            }else{
                read(fd2[0],&c,1);
                if(c == 'E'){
                    fprintf(stdout,"Father done\n");
                    exit(1);
                }
                fprintf(stdout,"I'm the father PID = %d\n", getpid());
            }
            conta++;
            sleep(2);
        }

    }else{

        while(1){
            if (conta == nmax && strcmp(argv[1],"C")==0){
                c = 'E';
                fprintf(stdout,"Child done\n");
                write(fd2[1],&c,1);
                exit(1);
            }
            if(strcmp(argv[1],"C")==0){
                c = 'C';
                fprintf(stdout,"I'm the child PID = %d\n", getpid());
                write(fd2[1], &c, 1);
            }else{
                read(fd1[0],&c,1);
                if(c == 'E'){
                    fprintf(stdout,"Child done\n");
                    exit(1);
                }
                fprintf(stdout,"I'm the child PID = %d\n", getpid());
            }
            conta++;
            sleep(2);
        }

    }

    exit(1);

}