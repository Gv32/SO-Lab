#include <stdio.h>

int main(int argc, char **argv){           
    FILE *f1, *f2;                          // Due puntatori a file
    char c;                                 // Variabile per il carattere
    char name[1024], buffer[1024];          // Variabili per il nome del file e per il buffer

    sprintf (name, "%s", argv[2]);          // Copia il nome del file
    f1 = fopen (argv[1], "r");              // Apre il file in lettura
    f2 = fopen (name, "w");                 // Apre il file in scrittura
    while (fscanf (f1, "%c", &c) != EOF)    // Legge un carattere
        fprintf (f2, "%c", c);              // Scrive un carattere
    fclose (f1);                            // Chiude il file
    fclose (f2);                            // Chiude il file

    return 0;
}