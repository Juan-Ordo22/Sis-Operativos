/**************************************************************
  *Fecha: 23 de agosto 2024
  *Autor:jhon corredor
  *estudiante Juan Ordoñez
  *Materia:Sistemas Operativos
  *Tema: Gestion de Memoria
  *Topico:Reserva de memoria con la funcion reaalloc().
  *La funcion malloc reserva un espacio de memoria de tamaño requerido
  * Devuelve un  puntero señalando el inicio del espacio de memoria
  *reservado
  *****************************************************************************/


//inclución de librerias
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  
  /*Declarar variables*/
  
  int *bloque00=malloc(4*sizeof(int));//Asignacion de vector de 4 tamaño int
  int *puntero=malloc(15*sizeof(*puntero));//Bloque de memoria de 15 int
  
  /*Bucle para llenar los espacios Primer Bloque Reservado (bloque00)*/
  for(int i=0;i<4;i++){
    bloque00[i]=i *2;
    printf("El vaor de memoria reservada bloque00 [%d]=%d\n\n", i, bloque00[i]);
    
  }
  /*Bucle para llenar los espacios Primer Bloque Reservado (puntero)*/
  if(puntero!=NULL){
    *(puntero+8)=9889;
    printf("El valor de la 9na posicion de puntero esw %d\n", *(puntero+8));
      printf("El valor de la 9na posicion de puntero esw %d\n", puntero[8]);
    
  }
  /*LIBERACION O RETORNO DE MEMORIA*/
  free(bloque00);
  free(puntero);
  return 0;
}