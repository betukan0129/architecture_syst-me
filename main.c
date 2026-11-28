#include "Fonctions.h"
#include <stdio.h>   // printf (prompt), getline (lecture de ligne)
#include <stdlib.h>  // exit, EXIT_SUCCESS
#include <string.h>  // strcmp (tester cmd.nom contre "cd", "exit"...)


int main(){
    char* path;
    while(1){

        // On récupère la ligne saisit par l'user
        size_t taille = 0;
        char* ligne = NULL;
        
        char* repertoire = getcwd(path, 1024);
        printf("mini_shell %s > ", repertoire);
        getline(&ligne, &taille, stdin);
        int argc;
        char* argv[256];
        decouper(ligne, argv, &argc);
        
        // si 1 ou au moins un mots est passé dans le shell
        if(argc>0) {

            // Commande interne
            if (strcmp(argv[0], "exit") == 0)
                {
                
                ecrire_log(ligne, "commande interne",1);
                break;

                }
            else if (strcmp(argv[0], "pwd") == 0)
                {
                executer_pwd(repertoire, argv, &argc);
            }
                
            if (strcmp(argv[0], "echo") == 0)
                {
                executer_echo(argv,&argc);
                }
            
            /*if (strcmp(argv[0], "cd ") == 0)
                {
                executer_cd(argv, &argc);
                }*/
            
            // Commande interne

        else{
            commande_introuvable(ligne,0);
            free(ligne);
        }

        }

        // Sinon on continue 
        else{
            
            
            continue;
        }


    }
   
    
   


  
}
