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
    char* mot = strtok(ligne, " \n");

    while (mot != NULL) {
        argv[*nb_mots] = mot;          
        (*nb_mots)++;
        mot = strtok(NULL, " \n");
    }
    argv[(*nb_mots) +1] = NULL;  
    
}
void ecrire_log(char* argv, char* type, int code_retour){
    char* date = "rien pour le moment";
    FILE* fp = fopen("fichier_log.txt", "a");
    fprintf(fp, "%s - %s - %s - %d\n", date, argv, type, code_retour);
    fclose(fp);


}
void executer_pwd(char* path, char** argv, int* argc){
    if (*argc > 1) {
        printf("pwd: option(s) ignorée(s)\n");
        ecrire_log("pwd", "commande interne", 0);
    }
    
    if (getcwd(path, 1024) != NULL) {
        printf("%s\n", path);
        ecrire_log("pwd", "commande interne", 1);
    } else {
        perror("pwd");
        ecrire_log("pwd", "commande interne", 0);
    }
    
    
    

}
void commande_introuvable(char* ligne,int code_retour){
    ecrire_log(ligne, "Ce n'est pas une commande",0);
    printf("Commande introuvable \n");

}

void executer_echo(char** argv, int* argc){
    for(int i = 1 ; i < *argc ; i++){
        printf("%s ", argv[i]);
    }
    printf("\n");
}
