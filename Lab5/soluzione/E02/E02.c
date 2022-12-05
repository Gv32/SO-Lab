#include<stdio.h>
#include<unistd.h>

int main(int argc, char **argv){
    int fd1[2];
    int fd2[2];

    char c;
    
    pipe(fd1);
    pipe(fd2);

    if(fork()!=0){

        while(1){
            if(argv[1]=='F'){
                c = 'F';
                fprintf(stdout,"I'm the father PID = %d", getpid());
                write(fd1[1], &c, 1);
            }else{
                read(fd2[0],&c,1);
                fprintf(stdout,"I'm the father PID = %d", getpid());
            }
        }

    }else{

        while(1){
            if(argv[1]=='C'){
                c = 'C';
                fprintf(stdout,"I'm the child PID = %d", getpid());
                write(fd2[1], &c, 1);
            }else{
                read(fd1[0],&c,1);
                fprintf(stdout,"I'm the child PID = %d", getpid());
            }
        }

    }

    exit(1);
    
}