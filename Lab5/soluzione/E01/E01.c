#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#define N 132
int main(){
	int file[2];
	char stringa[N],stringa2[N];
	int i;
	int size1, size2;
	pid_t pid;
	char x = 'a' - 'A';
	char carattere;
	char line[N], tmp[N],tmp2[N];
		if(fork()!=0){
		wait((int*)0);
		}
		else{
		pipe(file);
		pid = fork();
		if(pid!=0){
			//produttore//
			while(1){
				printf("Inserisci la stringa:\n");
				scanf("%s",stringa);
				size1 = strlen (stringa);
				if(strcmp(stringa,"end")!=0){
						sprintf (tmp, "%d%s", size1, stringa);
    					write (file[1], tmp, (size1+1));
					}
				else{
					sprintf (tmp, "%d%s", size1, stringa);
    				write (file[1], tmp, (size1+1));
					exit(11);
					}
					sleep(1);
				}
				exit(1);
			}
		else{
			//consumatore
			while(1){
				read (file[0], tmp2, N);
    			sscanf (tmp2, "%d%s", &size2, stringa2);
				if(strcmp(stringa2,"end")==0){
					exit(100);					
					}
				i=0;
				while(i<size2){
						carattere = stringa2[i] - x;
						printf("%c\n",carattere);	
						i++;	
					}
				}	
				exit(1);			
			}
		}
exit(100);	
}
