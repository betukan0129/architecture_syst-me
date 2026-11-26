#include "Fonction.h"
#include <stdio.h>   // printf (prompt), getline (lecture de ligne)
#include <stdlib.h>  // exit, EXIT_SUCCESS
#include <string.h>  // strcmp (tester cmd.nom contre "cd", "exit"...)


int main(){
  
  
  if(argc != 2){
        fprintf(stderr, "USAGE : \n\t%s REPERTOIRE \n", argv[0]);
        exit(EXIT_FAILURE);
    }
}
