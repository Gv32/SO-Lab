#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/wait.h>

int main(){

    char x='a'-'A';
    int fd[2];
    pipe(fd);
    char c;
    char stringa[100];

    if (fork()){
        close(fd[0]);
        while(strcmp(stringa,"stop")!=0){
            sleep (1);
            printf("inserisci la stringa\n");
            scanf("%s",stringa);
            if(strcmp(stringa,"stop")!=0){
                write(fd[1],&stringa,strlen(stringa)*sizeof(char)+1);
            }
            else{
                c='/';
                write(fd[1],&c,sizeof(char));
            }

        }

    }

    else{
        close(fd[1]);
        while(1){
        while ( read(fd[0],&c,sizeof(char)) > 0 ){
            if(c=='/'){
                exit(0);
            }
            if(c >= 'a' && c <= 'z'){
                c=c-x;
                printf("%c",c);
            }
            else {
                c=c+x;
                printf("%c",c);
            }

            
          
        }
        printf("\n");
        }
    }
}