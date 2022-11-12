#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<sys/wait.h>
int main(int argc, char **argv){
int n = atoi(argv[1]);
int t = atoi(argv[2]);
int i = 0;
pid_t pidf1;
pid_t pidf2;
for(i = 0; i < n; i++){
   pidf1 = fork();
   if (pidf1 == 0){
      printf("figlio1 creato pid padre = %d \n", getppid());
   }
   else{
      pidf2 = fork();
      if(pidf2 == 0){
         printf("figlio2 creato pid padre = %d \n", getppid());
      }
      else{
	 printf("processo %d terminato \n", getpid());
         exit(0);
      }
   }
}
sleep(t);
printf("Il processo e' terminato");
}
