#include <stdio.h>   // printf (prompt), getline (lecture de ligne)
#include <stdlib.h>  // exit, EXIT_SUCCESS
#include <string.h>  // strcmp (tester cmd.nom contre "cd", "exit"...)


int main(){
    char* c_interne[] = {"cd", "pwd", "exit","echo"};

    size_t taille = 0;
    char* ligne = NULL;
    printf("mini_shell> ");
    getline(&ligne, &taille, stdin);
    int argc;
    char* argv[256];
    decouper(ligne, argv, &argc);
    printf("%s", argv[0]);
}
