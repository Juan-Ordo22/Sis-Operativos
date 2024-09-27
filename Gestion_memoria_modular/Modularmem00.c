/*************
Fecha: 27-08-2024
Autor: Juan David Ordoñez
Materia: Sistemas Operativos
Tema:Gestion de Memoria, Punteros, Compilacion Modular
Descripción: Gestion de memoria(dinamica, estatica) Manipulacion de espacio de memoria 
segun necesite la aplicacion, por parte del usuario.
Se presenta la memoria estatica que solo se dispone en tiempo de compilación. Variables globales, vectores fijos, etc. No es necesario liberar memoria 
dinamica que en el tiempo de compilacion y siempre es de tamaño fijo.

Se presenta la memoria dinamica que el usuario en funcion del problema
puede cambiar, modificar, el espacio de memoria que necesite. El tema a señalar es que se debe liberar la memoria final.
Punteros son variables auxiliares como herramientas a disposicion del usuario
      para de forma ligera señalar espacios de memoria o contenedores (estructuras de datos, etc)
      y obtener de forma precisa la direccion de memoria.
      Utiles cuando se quiere que el programa sea ligero al administrar el uso de memoria.
Compilacion Modular representa crear biblioteca de funciones con su interfaz correspondiente. 
De forma que quede la biblioteca a disposicion de otros programas o usuarios.
Adicional, se crea un fichero que se llama Makefile cuyo proposit es el de automatizar compilación.


***************/

#include <stdio.h>
#include <stdlib.h>

#define CAPACIDAD_INICIAL 4

/* Creación de la estructura de datos para el vector dinámico */
typedef struct vectorDinamico{
    int capacidad;         // Capacidad actual del vector
    int totalElementos;    // Número total de elementos en el vector
    void **elementos;      // Puntero a los elementos del vector
} vectorDinamico;

/* Inicializa el vector dinámico, asignando memoria y estableciendo 
   la capacidad inicial y el conteo de elementos a cero. */
void vectorInicio(vectorDinamico *V){
    V->capacidad = CAPACIDAD_INICIAL;
    V->totalElementos = 0;
    V->elementos = malloc(sizeof(void *) * V->capacidad); 
}

/* Retorna el total de elementos actuales en el vector. */
int totalVector(vectorDinamico *V){
    return V->totalElementos;
}

/* Redimensiona el vector a una nueva capacidad. Se usa realloc para ajustar el tamaño. */
static void resizeVector(vectorDinamico *V, int capacidad){
    printf("Redimensión: %d a %d \n", V->capacidad, capacidad);

    void **elementos = realloc(V->elementos, sizeof(void *) * capacidad);
    if(elementos){
        V->elementos = elementos;
        V->capacidad = capacidad;
    }
}

/* Agrega un nuevo elemento al vector. Si el vector está lleno, lo redimensiona. */
void addVector(vectorDinamico *V, void *elemento){
    if(V->capacidad == V->totalElementos)
        resizeVector(V, V->capacidad * 2);
    V->elementos[V->totalElementos++] = elemento;
}

/* Libera la memoria asignada para los elementos del vector. */
void freeVector(vectorDinamico *V){
    free(V->elementos);
}

/* Obtiene un elemento del vector en un índice específico. 
   Devuelve NULL si el índice está fuera de rango. */
void *getVector(vectorDinamico *V, int indice){
    if(indice >= 0 && indice < V->totalElementos)
        return V->elementos[indice];
    return NULL;
}

/* Establece un nuevo valor para el elemento en un índice específico. 
   No realiza verificación si el índice está fuera de rango. */
void setVector(vectorDinamico *V, int indice, void *elemento){
    if(indice >= 0 && indice < V->totalElementos)
        V->elementos[indice] = elemento;
}

/* Borra un elemento en el índice especificado, desplazando los elementos posteriores hacia la izquierda.
   Redimensiona el vector si el total de elementos cae a 1/4 de la capacidad. */
void borrarVector(vectorDinamico *V, int indice){
    if(indice < 0 || indice >= V->totalElementos)
        return; 

    V->elementos[indice] = NULL;

    for(int i = indice; i < V->totalElementos - 1; i++){
        V->elementos[i] = V->elementos[i + 1];
        V->elementos[i + 1] = NULL; 
    }
    V->totalElementos--;
    if(V->totalElementos > 0 && V->totalElementos == V->capacidad / 4)
        resizeVector(V, V->capacidad / 2);
}
 
int main(){
    int i;
    vectorDinamico editor;
    vectorInicio(&editor); // Inicializa el vector

    // Agrega varios elementos al vector
    addVector(&editor, "Hola ");
    addVector(&editor, "Profesional ");
    addVector(&editor, "en ");
    addVector(&editor, "Formación ");
    addVector(&editor, "en ");
    addVector(&editor, "ingenieria ");
     
    printf("\n \n");
  
    // Imprime los elementos actuales del vector
    for (i = 0; i < totalVector(&editor); i++)
        printf("%s", (char *) getVector(&editor, i));

    printf("\n \n");
  
    // Borra elementos desde el final hasta el segundo elemento
    while(i > 1){
        borrarVector(&editor, i);
        i--;
    }
  
    // Establece un nuevo valor en el segundo índice y agrega un nuevo elemento
    setVector(&editor, 1, "Buenos ");
    addVector(&editor, "días  ");
  
    printf("\n \n");
         
    // Imprime los elementos restantes en el vector
    for (i = 0; i < totalVector(&editor); i++)
        printf("%s ", (char *) getVector(&editor, i));
  
    // Libera la memoria del vector antes de salir
    freeVector(&editor);
    return 0;
}
