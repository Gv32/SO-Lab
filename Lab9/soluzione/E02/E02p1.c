#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>

typedef struct{
    float c,x;
    int n;
}monomio;

int main(int argc, char *argv[]){
    int fb;
    FILE *fas;
    monomio m;
    int n;

    fas = fopen(argv[1], "r");
    fb = creat(argv[2], 0666);

    while(fscanf(fas,"%f %f %d", &m.c, &m.x, &m.n) != EOF){
        write(fb, &m, sizeof(monomio));
    }

    fclose(fas);
    close(fb);

    fb = open(argv[2], O_RDONLY);
    while(read(fb, &m, sizeof(monomio))>0){
        printf("%f %f %d\n", m.c, m.x, m.n);
    }
}