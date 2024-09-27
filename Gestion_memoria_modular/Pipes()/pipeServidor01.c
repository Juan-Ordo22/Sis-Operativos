/*************************************************************************************************************************
Fecha: 03-09-2024
Autor: Juan David Ordoñez
Materia: Sistemas Operativos
Tema:Piped named 
Descripción: Servidor
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
    char BusMensaje[80];
    char final[10];
    int fin;
     int cantidadBytes;
     printf("\n \t\t>>>>>>>>>>> INICIO SERVIDOR  <<<<<<<<<<<<<<<<<<<< \n");
     /* Create the FIFO if it does not exist */
     mknod(FIFO_FILE, S_IFIFO|0640, 0);
     strcpy(final, "fin");
     while(1) {
       ArchivoDesc=open(FIFO_FILE,O_RDONLY);
       cantidadBytes= read(ArchivoDesc,BusMensaje,sizeof(BusMensaje));
       printf("Cadena recibida: \"%s\" y cantidad de bytes %d\n",BusMensaje,(int) strlen(BusMensaje));
         fin = strcmp(BusMensaje, final);
       if (fin == 0) {
           close(ArchivoDesc);
          break;
        }
     }
  return 0;
}