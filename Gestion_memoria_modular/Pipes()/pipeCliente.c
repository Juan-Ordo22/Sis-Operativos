/*************************************************************************************************************************
Fecha: 24-09-2024
Autor: Juan David Ordoñez
Materia: Sistemas Operativos
Tema:Piped named 
Descripción: Cliente
**************************************************************************************************************/
#include<stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include<sys/stat.h>
#include <string.h>
#include <fcntl.h>

#define FIFO_FILE "MYFIFO"
  int main() {
     int ArchivoDesc;
     int fin_proceso;
     int cadena;
     char BusMensaje[80];
     char senal_fin[5];
     printf("\n \t\t>>>>>>>>>>> INICIO SERVIDOR  <<<<<<<<<<<<<<<<<<<< \n");    
    
     printf("FIFO_CLIENT: Enviando Mensajes, Infinitamente, para finalizar \"fin\"\n");
     ArchivoDesc = open(FIFO_FILE, O_CREAT|O_WRONLY);
     strcpy(senal_fin, "fin");
 
     while (1) {
       printf("Ingrese Mensaje: ");
        fgets(BusMensaje, sizeof(BusMensaje), stdin);
        cadena = strlen(BusMensaje);
        BusMensaje[cadena - 1] = '\0';
        fin_proceso = strcmp(BusMensaje, senal_fin);
  
        //printf("end_process is %d\n", end_process);
       if (fin_proceso != 0) {
           write(ArchivoDesc, BusMensaje, strlen(BusMensaje));
          printf("Envie un mensaje: \"%s\" y tamaño es %d\n", BusMensaje, (int)    strlen(BusMensaje));
        } else {
          write(ArchivoDesc, BusMensaje, strlen(BusMensaje));
          printf("Mensaje enviado: \"%s\" y tamaño es %d\n", BusMensaje, (int)    strlen(BusMensaje));
          close(ArchivoDesc);
           break;
        }
    }
  return 0;
  }
