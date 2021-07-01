#ifndef BICOLA_H
#define BICOLA_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int INFO;
typedef struct _nodo NODO;

struct _nodo{
    INFO info;
    NODO* siguiente;
    NODO* anterior;
};

struct _cola{
    NODO* head;
    NODO* tail;
    int num;
};

typedef struct _cola COLA;

COLA* crear_cola();
NODO* crear_nodo(INFO info);
bool insertar_fin(COLA* cola, INFO info);
bool insertar_inicio(COLA* cola, INFO info);
bool eliminar_fin(COLA* cola);
bool eliminar_inicio(COLA* cola);
void imprimir_cola(COLA* cola);
bool vaciar(COLA* cola);

#endif // "Bicola_h"