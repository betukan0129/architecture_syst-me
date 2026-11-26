#include "Fonctions.h"
#include <stdio.h>     // printf, fprintf, perror, FILE, fopen, fclose
#include <stdlib.h>    // malloc, free, exit, getenv
#include <string.h>    // strtok, strcmp, strlen
#include <unistd.h>    // fork, execvp, chdir, getcwd
#include <sys/wait.h>  // waitpid, WIFEXITED, WEXITSTATUS
#include <sys/types.h> // pid_t
#include <errno.h>     // errno (détail des erreurs système)
#include <time.h>      // time, localtime, strftime (pour le log)

void decouper(char* ligne, char** argv, int* nb_mots) {
    *nb_mots = 0;
    char* mot = strtok(ligne, " ");

    while (mot != NULL) {
        argv[*nb_mots] = mot;          
        (*nb_mots)++;
        mot = strtok(NULL, " ");
    }
}
