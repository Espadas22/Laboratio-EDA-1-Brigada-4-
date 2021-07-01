#include "bicola.h"
#include <stdio.h>
#include <stdlib.h>

COLA* crear_cola()
{
    COLA* nueva_cola = (COLA*)malloc(sizeof(COLA));
    nueva_cola -> head = nueva_cola -> tail = NULL;
    return nueva_cola;
}

NODO* crear_nodo(INFO info)
{
    NODO* nuevo = (NODO*)malloc(sizeof(NODO));
    nuevo -> siguiente = NULL;
    nuevo -> anterior = NULL;
    nuevo -> info = info;
    return nuevo;
}

bool insertar_fin(COLA* cola, INFO info) // Insertar final
{
    NODO* nuevo = crear_nodo(info);
    if(cola->tail == NULL && cola-> head == NULL){
        cola -> tail = nuevo;
        cola ->head = nuevo;
        cola -> num++;
        return true;
    }
    else{
        nuevo -> anterior = cola -> tail;
        cola -> tail -> siguiente = nuevo;
        cola -> tail = nuevo;
        cola -> num++;
        return true;
    }
    return false;
}

bool insertar_inicio(COLA* cola, INFO info){ 
    NODO* nuevo = crear_nodo(info);
    if(cola->tail == NULL && cola-> head == NULL){
        cola -> tail = nuevo;
        cola ->head = nuevo;
        cola -> num++;
        return true;
    }
    else{
        nuevo -> siguiente = cola -> head;
        cola -> head -> anterior = nuevo;
        cola -> head = nuevo;
        cola -> num++;
        return true;
    }
    return false;
}

bool eliminar_inicio(COLA* cola) 
{
    if (cola -> num == 0) return false;
    
    NODO* temporal = cola -> head;
    cola -> head = cola -> head -> siguiente;
    temporal -> siguiente = NULL; 
    free(temporal);
    cola -> num--;
    return true;
}

bool eliminar_fin(COLA* cola){ 
    if (cola -> num == 0) return false;

    NODO* temporal = cola -> tail;
    cola -> tail = cola -> tail -> anterior;
    temporal -> siguiente = temporal -> anterior = NULL;
    free(temporal);
    cola -> num--;
    return true;
}

void imprimir_cola(COLA* cola){
    for(NODO* t = cola->head; t != cola -> tail -> siguiente ; t = t->siguiente){
        printf("%d -> ", t-> info);
    }
    printf(" NULL \n");
}

bool vaciar(COLA* cola){
    if(cola->head == NULL && cola -> tail == NULL) return false;
    NODO* temporal = cola->head;
    while(temporal != NULL){
        cola->head = temporal->siguiente;
        temporal->siguiente = NULL;
        free(temporal);
        temporal = cola->head;
    }
    cola->head = cola->tail = NULL;
    cola->num = 0;
    return true;
}
