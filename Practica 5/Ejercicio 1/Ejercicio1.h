#ifndef PILA_H
#define PILA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

typedef struct _nodo NODO;

struct _nodo{
    char operador;
    int prioridad;
    NODO* siguiente;
};

struct _pila{
    NODO* head;
    NODO* tail;
    int num;
};

typedef struct _pila PILA;

PILA* crear_pila();
NODO* crear_nodo(int prioridad, char operador);
bool push(PILA* pila, int prioridad, char operador);
bool pop(PILA* pila);
int* top(PILA* pila);
void eliminar_nodo(NODO* nodo);
bool es_vacia(PILA *pila);
bool vaciar(PILA *pila);
void eliminar_pila(PILA *pila);
int determinar_prioridad(char operador);
void imprimir_pila(PILA *pila);

#endif