#include "Fonctions.h"
#include <stdio.h>   // printf (prompt), getline (lecture de ligne)
#include <stdlib.h>  // exit, EXIT_SUCCESS
#include <string.h>  // strcmp (tester cmd.nom contre "cd", "exit"...)


int main(){
    
    while(1){
         size_t taille = 0;
        char* ligne = NULL;
        printf("mini_shell> ");
         getline(&ligne, &taille, stdin);
        int argc;
        char* argv[256];
        decouper(ligne, argv, &argc);
        printf("%s\n", argv[1]);
        if (strcmp(argv[0], "exit") == 0)
        {
           break;
        }


        commande_introuvable(); // surement à améliorer pour si argc > 1;
        

    }
   
    
   


  
}
