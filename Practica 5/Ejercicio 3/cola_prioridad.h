#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 

#ifndef COLAPRIORIDAD_H
#define COLAPRIORIDAD_H

typedef struct _nodo NODO;

struct _nodo
{
    int Info;
    NODO* Siguiente;
    int Prioridad;
};

struct _cola
{
    NODO* Inicio;
    NODO* Fin;
    int Numero_nodos;
};

typedef struct _cola COLA;

COLA* crear_cola();
NODO* crear_nodo(int Info, int Prioridad);
bool es_vacia(COLA* Cola);
bool enqueue(COLA* Cola, int Info, int Prioridad);
bool dequeue(COLA* Cola);
bool imprimir_cola(COLA* Cola);
bool vaciar_nodo(NODO* Nodo);
bool vaciar_cola(COLA* Cola);
#endif