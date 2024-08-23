/**************************************************************
  *Fecha: 13 de agosto 2024
  *Autor: Juan Ordoñez
  *Materia:Sistemas Operativos
  *Tema: Gestion de Memoria
  *Topico:Reserva de memoria con la funcion calloc().
  *La funcion calloc reserva Reserva memoria para un número específico de elementos y los inicializa a cero.
  
  * Devuelve un puntero al bloque de memoria asignado e inicializado a cero
  *Descripción programa: Asigna y llena un array de 4 enteros, otro de 15 enteros, e inicializa todo a cero. Luego, modifica un valor específico y libera la memoria.

  *****************************************************************************/

//inclución de librerias
#include <stdio.h>
#include <stdlib.h>

int main(void) {

    /* Declarar variables */
    int *bloque00 = calloc(4, sizeof(int)); // Asignación de vector de 4 elementos de tamaño int, inicializados a 0
    int *puntero = calloc(15, sizeof(*puntero)); // Bloque de memoria de 15 int, inicializados a 0

    /* Verificación de asignación de memoria */
    if (bloque00 == NULL || puntero == NULL) {
        printf("Error al asignar memoria\n");
        return 1;
    }

    /* Bucle para llenar los espacios del primer bloque reservado (bloque00) */
    for (int i = 0; i < 4; i++) {
        bloque00[i] = i * 2;
        printf("El valor de memoria reservada bloque00 [%d] = %d\n", i, bloque00[i]);
    }

    /* se modifica un espacio específico en puntero  y se imprime dicha posición*/
    *(puntero + 8) = 9889;
    printf("El valor de la 9na posición de puntero es %d\n", *(puntero + 8));
    printf("El valor de la 9na posición de puntero es %d\n", puntero[8]);

    /* LIBERACIÓN DE MEMORIA */
    free(bloque00);
    free(puntero);
    return 0;
}