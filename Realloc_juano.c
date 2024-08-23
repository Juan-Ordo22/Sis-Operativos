/**************************************************************
  *Fecha: 23 de agosto 2024
  *Autor:Juan Ordoñez
  *Materia:Sistemas Operativos
  *Tema: Gestion de Memoria
  *Topico:Reserva de memoria con la funcion reaalloc().
  *La funcion realloc Cambia el tamaño de un bloque de memoria previamente asignado, conservando su contenido existente.
  * Devuelve un puntero al bloque de memoria redimensionado, que puede ser el mismo o uno nuevo si el tamaño cambia
  *****************************************************************************/
//inclución de librerias 
#include <stdio.h>
#include <stdlib.h>

int main(void) {

    // Declarar variables 
    int *bloque00 = malloc(4 * sizeof(int)); // Asignación de vector de 4 elementos de tamaño int

    // Verificación de asignación de memoria 
    if (bloque00 == NULL) {
        printf("Error al asignar memoria\n");
        return 1;
    }

    // Bucle para llenar los espacios del primer bloque reservado (bloque00) 
    for (int i = 0; i < 4; i++) {
        bloque00[i] = i * 2;
        printf("El valor de memoria reservada bloque00 [%d] = %d\n", i, bloque00[i]);
    }

    // Reasignar memoria usando realloc para ampliar el bloque00 a 8 elementos 
    bloque00 = realloc(bloque00, 8 * sizeof(int));
    if (bloque00 == NULL) {
        printf("Error al reasignar memoria\n");
        return 1;
    }

    // Llenar los nuevos espacios del bloque ampliado 
    for (int i = 4; i < 8; i++) {
        bloque00[i] = i * 3;
        printf("El valor de memoria reasignada bloque00 [%d] = %d\n", i, bloque00[i]);
    }

    // Asignación de memoria inicial para puntero 
    int *puntero = malloc(15 * sizeof(*puntero)); // Bloque de memoria de 15 int

    // Verificación de asignación de memoria 
    if (puntero == NULL) {
        printf("Error al asignar memoria\n");
        free(bloque00);
        return 1;
    }

    // Bucle para modificar un espacio específico en puntero 
    *(puntero + 8) = 9889;
    printf("El valor de la 9na posición de puntero es %d\n", *(puntero + 8));
    printf("El valor de la 9na posición de puntero es %d\n", puntero[8]);

    // LIBERACIÓN O RETORNO DE MEMORIA 
    free(bloque00);
    free(puntero);
    return 0;
}