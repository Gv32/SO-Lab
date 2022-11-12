#include<stdio.h>
#include<unistd.h>
int main(){
int i=0;
for (i=2; i>=1; i--) {
  if (!fork ())
    printf ("%d\n", -i);
  else
    printf ("%d\n", i);
}
}
