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
bool insertar(LISTA* lista,INFO info,int pos); 
LISTA* crear_lista();
bool es_vacia(LISTA *lista);
bool vaciar(LISTA* lista);
void imprimir_lista(LISTA* lista);
void eliminar_nodo(NODO* nodo);
void eliminar_inicio(LISTA* lista);
void eliminar_fin(LISTA* lista);
void eliminar(LISTA* lista, int posicion);
INFO* buscar(LISTA* lista, int posicion);
int localizar(LISTA* lista, INFO info);
bool comparar(INFO info_1, INFO info_2);