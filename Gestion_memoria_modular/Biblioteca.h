#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#include <stdio.h>
#include <stdlib.h>

#define CAPACIDAD_INICIAL 4


/*Creación Estructura de Datos para el Vector*/
typedef struct vectorDinamico{
        int capacidad;
        int totalElementos;
        void **elementos;
} vectorDinamico;

void vectorInicio(vectorDinamico *V);

int totalVector(vectorDinamico *V);

static void resizeVector(vectorDinamico *V, int capacidad);

void addVector(vectorDinamico *V, void *elemento);

void freeVector(vectorDinamico *V);

void *getVector(vectorDinamico *V, int indice);

void setVector(vectorDinamico *V, int indice, void *elemento);

void borrarVector(vectorDinamico *V, int indice);


#endif