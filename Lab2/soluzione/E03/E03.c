#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main(){
   pid_t pidtmp;

   printf("P1\n");
   pidtmp = fork();
   if(pidtmp != 0){
      printf("P2\n");
      pidtmp = fork();
      if(pidtmp == 0){
         printf("P5\n");
         sleep(1);
         exit(1);
      }else{
         printf("P4\n");
	 wait((int *) 0);
      }
      printf("P7\n");
      wait((int *) 0);
   }else{
   printf("P3\n");
   pidtmp = fork();
   if(pidtmp == 0){
      printf("P6\n");
      sleep(1);
      exit(1);
   }else{
      wait((int *) 0);
   }
   printf("P8\n");
   sleep(1);
   exit(1);
   }
   printf("P9\n");
}
