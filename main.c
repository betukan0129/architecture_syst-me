#include "Fonctions.h"
#include <stdio.h>   // printf (prompt), getline (lecture de ligne)
#include <stdlib.h>  // exit, EXIT_SUCCESS
#include <string.h>  // strcmp (tester cmd.nom contre "cd", "exit"...)


int main(){
    
    while(1){

        // On récupère la ligne saisit par l'user
        size_t taille = 0;
        char* ligne = NULL;
        printf("mini_shell> ");
        getline(&ligne, &taille, stdin);
        
        int argc;
        char* argv[256];
        decouper(ligne, argv, &argc);
        
        // si 1 ou au moins un mots est passé dans le shell
        if(argc>0) {

            // Commande interne
            if (strcmp(argv[0], "exit") == 0)
                {
                
                ecrire_log(ligne, "commande interne");
                }
                
            /*if (strcmp(argv[0], "echo") == 0)
                {
                executer_exit(argv[0]);
                }
            if (strcmp(argv[0], "pwd") == 0)
                {
                executer_exit(argv[0]);
                }
            if (strcmp(argv[0], "cd ") == 0)
                {
                executer_exit(argv[0]);
                }*/
            


            // Commande interne
        }





        // Sinon on continue 
        else{
            continue;
        }


        
        


        //commande_introuvable(argv,&argc); // surement à améliorer pour si argc > 1;
        

    }
   
    
   


  
}
