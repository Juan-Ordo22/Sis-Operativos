#include <stdio.h>
#include <stdlib.h>

#include "Biblioteca.h"

int main(){
        int i;
        vectorDinamico editor;
        vectorInicio(&editor);

        addVector(&editor, "Hola ");
        addVector(&editor, "Profesional ");
        addVector(&editor, "en ");
        addVector(&editor, "Formación ");
        addVector(&editor, "en ");
        addVector(&editor, "ingenieria ");
         
        printf("\n \n");
  
        for (i = 0; i < totalVector(&editor); i++)
        printf("%s", (char *) getVector(&editor, i));

        printf("\n \n");
  
       while(i > 1){
           borrarVector(&editor, i);
            i--;
        }
  
        setVector(&editor, 1, "Buenos ");
        addVector(&editor, "días  ");
  
        printf("\n \n");
         
   
        for (i = 0; i < totalVector(&editor); i++)
        printf("%s ", (char *) getVector(&editor, i));
  
      freeVector(&editor);
     return 0;
  }