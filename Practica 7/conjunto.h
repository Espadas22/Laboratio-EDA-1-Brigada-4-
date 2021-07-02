#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int INFO;
typedef struct _nodo NODO;

struct _nodo{
    INFO info;
    NODO* siguiente;
};

struct _lista{
    NODO* head;
    NODO* tail;
    int num;
};

typedef struct _lista LISTA;

NODO* crear_nodo(INFO info);
bool insertar_inicio(LISTA* lista,INFO info);
bool insertar_final(LISTA* lista, INFO info); 
LISTA* crear_lista();
bool es_vacia(LISTA *lista);
bool vaciar(LISTA* lista);
void imprimir_lista(LISTA* lista);
void eliminar_nodo(NODO* nodo);
bool pertenencia(LISTA* lista, INFO info);
int cardinal(LISTA* lista);
bool comparar(INFO info_1, INFO info_2);
bool agregar(LISTA* lista, int nuevo_elemento);
bool insertar_elemento(LISTA* lista, int nuevo_elemento);