/*************************************************************************************************************************
Fecha: 24-09-2024
Autor: Juan David Ordoñez
Materia: Sistemas Operativos
Tema: Comunicación Bi-direccional con Piped Named (FIFO)
Descripción: Cliente-Servidor - Comunicación Bi-direccional utilizando un pipe nombrado (FIFO).
*************************************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <fcntl.h>

#define ARCHIVO_FIFO "/tmp/fifo_bidireccional"  // Archivo FIFO utilizado para la comunicación

int main() {
    int fd;                     // Descriptor de archivo para el FIFO
    int fin_proceso;            // Indicador para finalizar el proceso
    int longitud_cadena;        // Longitud de la cadena ingresada
    int bytes_leidos;           // Cantidad de bytes leídos desde el FIFO
    char buffer_lectura[80];    // Buffer para almacenar las cadenas leídas
    char cadena_fin[5];         // Cadena que indica la finalización del proceso

    printf("CLIENTE_FIFO: Envíe mensajes indefinidamente. Para terminar, escriba \"fin\"\n");

    // Abrir el archivo FIFO con permisos de lectura y escritura
    fd = open(ARCHIVO_FIFO, O_CREAT | O_RDWR);

    // Copiar el mensaje de finalización
    strcpy(cadena_fin, "fin");

    // Bucle principal del cliente
    while (1) {
        printf("Ingrese una cadena: ");
        fgets(buffer_lectura, sizeof(buffer_lectura), stdin);  // Leer entrada del usuario
        longitud_cadena = strlen(buffer_lectura);
        buffer_lectura[longitud_cadena - 1] = '\0';  // Eliminar el carácter de nueva línea

        // Verificar si el usuario quiere finalizar el proceso
        fin_proceso = strcmp(buffer_lectura, cadena_fin);

        if (fin_proceso != 0) {
            // Enviar la cadena al servidor a través del FIFO
            write(fd, buffer_lectura, strlen(buffer_lectura));
            printf("CLIENTE_FIFO: Cadena enviada: \"%s\" y su longitud es %d\n", buffer_lectura, (int)strlen(buffer_lectura));

            // Leer la respuesta del servidor (cadena invertida)
            bytes_leidos = read(fd, buffer_lectura, sizeof(buffer_lectura));
            buffer_lectura[bytes_leidos] = '\0';  // Añadir terminador de cadena
            printf("CLIENTE_FIFO: Cadena recibida: \"%s\" y su longitud es %d\n", buffer_lectura, (int)strlen(buffer_lectura));
        } else {
            // Enviar el mensaje de finalización
            write(fd, buffer_lectura, strlen(buffer_lectura));
            printf("CLIENTE_FIFO: Cadena enviada: \"%s\" y su longitud es %d\n", buffer_lectura, (int)strlen(buffer_lectura));
            close(fd);  // Cerrar el archivo FIFO
            break;      // Salir del bucle
        }
    }
    return 0;
}
                                         