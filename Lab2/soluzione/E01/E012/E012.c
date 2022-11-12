#include<unistd.h>
#include<stdio.h>
int main(){
int i = 0;
for(i=3; i>1; i--) {
  if (fork ())
    printf ("%d\n", i);
}
printf ("%d\n", i);
}
