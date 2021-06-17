#include "linked_list.h"

NODO* crear_nodo(INFO info){
    NODO* nodo = (NODO*) malloc(sizeof(NODO));
    nodo->siguiente = NULL;
    nodo->info = info;
    printf("La direccion de memoria del nodo %d es: %p\n", nodo -> info,  nodo);
    return nodo;
}
bool insertar_inicio(LISTA* lista,INFO info){
    NODO* nuevo = crear_nodo(info); // Crear nodoºn
    if(lista->head==NULL && lista->tail==NULL){
        // Cuando la lista esta vacia
        lista->head = lista->tail = nuevo;
        lista->num++;
        return true;
    }else{
        // Cuando hay uno o mas nodos
        nuevo->siguiente = lista->head;
        lista->head = nuevo;
        lista->num++;
        return true;
    }
    return false;
}
bool insertar_final(LISTA* lista, INFO info){
    NODO* nuevo = crear_nodo(info); // Crear nodo
    if(lista->head==NULL && lista->tail==NULL){
        // Cuando la lista esta vacia
        lista->head = lista->tail = nuevo;
        lista->num++;
        return true;
    }else{
        lista->tail->siguiente = nuevo;
        lista->tail = nuevo;
        lista->num++;
        return true;
    }
    return false;
}

// Insertar en posicion p
bool insertar(LISTA* lista, INFO info, int pos){
    if(pos == 0) return insertar_inicio(lista,info);
    else if(pos==lista->num) return insertar_inicio(lista,info);
    else if(pos>0 && pos < lista->num){
        NODO* nuevo = crear_nodo(info);
        NODO* temporal = lista->head;
        int tpos;
        for(tpos = 0; tpos < pos-1;tpos++){
            temporal = temporal->siguiente;
        }
        nuevo->siguiente = temporal->siguiente;
        temporal->siguiente = nuevo;
        lista->num++;
        return true;
    }
    return false;
}
LISTA* crear_lista(){
    LISTA* l = (LISTA*) malloc(sizeof(LISTA));
    l->head = l->tail = NULL;
    l->num = 0;
    return l;
}

bool es_vacia(LISTA *lista){
    if(lista->head == NULL && lista->tail == NULL) return true;
    return false;
}
bool vaciar(LISTA* lista){
    NODO* temporal = lista->head;
    while(temporal != NULL){
        lista->head = temporal->siguiente;
        free(temporal);
        temporal = lista->head;
    }
    lista->head = lista->tail = NULL;
    lista->num = 0;
    return 0;
}

void imprimir_lista(LISTA* lista){
    NODO* t;
    for(t = lista->head; t != NULL; t = t->siguiente){
        printf("%d ---> ",t->info);
    }
    printf("NULL\n");
}

void eliminar_nodo(NODO* nodo)
{
    if (nodo->siguiente == NULL)
    {
        free(nodo);
        nodo = NULL;
    }
}

void eliminar_inicio(LISTA* lista)
{
    if (es_vacia(lista)) return;
    NODO* temporal = lista -> head;
    lista -> head = lista -> head -> siguiente;
    temporal->siguiente = NULL;
    eliminar_nodo(temporal);
    lista->num--;
}

void eliminar_fin(LISTA* lista)
{
    if (es_vacia(lista)) return;
    NODO* temporal;
    for(temporal = lista->head; temporal->siguiente != lista->tail; temporal = temporal->siguiente);
    temporal->siguiente = NULL;
    eliminar_nodo(lista->tail);
    lista->tail = temporal;
    lista->num--;
}

void eliminar(LISTA* lista, int posicion)
{
    if (posicion == 0) eliminar_inicio(lista);
    else if (posicion == lista->num-1) eliminar_fin(lista);
    else if (posicion > 0 && posicion < lista->num-1)
    {
        NODO* temporal = lista->head;
        NODO* temporal_2;
        
        for (int i = 0 ; i < posicion-1; i++)
            temporal = temporal -> siguiente;

        temporal_2 = temporal->siguiente;
        temporal->siguiente = temporal->siguiente->siguiente; // temporal -> siguiente = temporal_2 -> siguiente 
        temporal_2->siguiente = NULL;
        eliminar_nodo(temporal_2);
        lista->num--;
    }
}

INFO* buscar(LISTA* lista, int posicion)
{
    if (es_vacia(lista)) return NULL;
    if (posicion == 0) return &lista->head->info;
    if (posicion == lista->num-1) return &lista->tail->info;
    if (posicion > 0 && posicion < lista->num-1)
    {
        NODO* temporal = lista->head;
        
        for (int i = 0 ; i < posicion; i++)
            temporal = temporal -> siguiente;
        
        return &temporal->info;
    }
}

int localizar(LISTA* lista, INFO info)
{
    if (es_vacia(lista)) return -1;
    NODO* temporal = lista->head;
    int posicion = 0;

    while (temporal != NULL)
    {
        if (comparar(temporal->info, info)) return posicion;
        posicion++;
        temporal = temporal->siguiente;
    }

    return -1; // El dato no esta en la lista

}

bool comparar(INFO info_1, INFO info_2)
{
    if (info_1 == info_2) return true;
    return false;
}