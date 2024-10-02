/*************************************************************************************************************************
Fecha: 24-09-2024
Autor: Juan David Ordoñez
Materia: Sistemas Operativos
Tema: Comunicación Bi-direccional con Piped Named (FIFO)
Descripción: Este programa simula un servidor que se comunica de manera bi-direccional con un cliente utilizando un FIFO (pipe nombrado). 
El servidor recibe una cadena, invierte el texto, y lo envía de vuelta al cliente.
*************************************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <fcntl.h>

#define ARCHIVO_FIFO "/tmp/fifo_bidireccional"  // Definición del archivo FIFO

// Prototipo de la función que invierte la cadena
void invertir_cadena(char *);

int main() {
    int fd;                   // Descriptor de archivo para el FIFO
    char buffer_lectura[80];   // Buffer para almacenar la cadena leída
    char finalizar[10];        // Cadena que representa el mensaje de finalización
    int fin_transmision;       // Indicador de finalización
    int bytes_leidos;          // Cantidad de bytes leídos del FIFO

    /* Crear el FIFO si no existe */
    mkfifo(ARCHIVO_FIFO, S_IFIFO | 0640);

    // Copiar el mensaje de finalización
    strcpy(finalizar, "fin");

    // Abrir el archivo FIFO en modo lectura/escritura
    fd = open(ARCHIVO_FIFO, O_RDWR);

    // Bucle principal del servidor
    while (1) {
        // Leer datos del FIFO
        bytes_leidos = read(fd, buffer_lectura, sizeof(buffer_lectura));
        buffer_lectura[bytes_leidos] = '\0';  // Añadir el terminador de cadena

        printf("SERVIDOR_FIFO: Cadena recibida: \"%s\" y su longitud es %d\n", buffer_lectura, (int)strlen(buffer_lectura));

        // Verificar si el mensaje recibido es "fin" para finalizar la comunicación
        fin_transmision = strcmp(buffer_lectura, finalizar);
  
        if (fin_transmision == 0) {
            close(fd);  // Cerrar el FIFO
            break;      // Finalizar el bucle
        }

        // Invertir la cadena recibida
        invertir_cadena(buffer_lectura);
        printf("SERVIDOR_FIFO: Enviando cadena invertida: \"%s\" y su longitud es %d\n", buffer_lectura, (int)strlen(buffer_lectura));

        // Escribir la cadena invertida de vuelta al FIFO
        write(fd, buffer_lectura, strlen(buffer_lectura));

        /*
        sleep - Este retraso asegura que otro proceso lea este mensaje,
        de lo contrario, este proceso recuperaría el mensaje inmediatamente.
        */
        sleep(2);
    }

    return 0;
}

// Función para invertir una cadena
void invertir_cadena(char *cadena) {
    int ultimo, limite, primero;
    char temporal;

    // Calcular la posición del último carácter
    ultimo = strlen(cadena) - 1;
    limite = ultimo / 2;  // Limite para el intercambio de caracteres
    primero = 0;

    // Intercambiar caracteres desde los extremos hacia el centro
    while (primero < ultimo) {
        temporal = cadena[primero];
        cadena[primero] = cadena[ultimo];
        cadena[ultimo] = temporal;
        primero++;
        ultimo--;
    }

    return;
}                                