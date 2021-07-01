#include "conjunto.h"

NODO* crear_nodo(INFO info){
    NODO* t = (NODO*) malloc(sizeof(NODO));
    t->siguiente = NULL;
    t->info = info;
    return t;
}
bool insertar_inicio(LISTA* lista,INFO info){
    NODO* nuevo = crear_nodo(info); // Crear nodo
    if(lista->head==NULL && lista->tail==NULL){
        // Cuando la lista esta vacia
        lista->head = lista->tail = nuevo;
        lista->num++;
        return true;
    }
    else
    {
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
bool insertar(LISTA* lista,INFO info,int pos){
    if(pos == 0) return insertar_inicio(lista,info);
    else if(pos==lista->num) return insertar_inicio(lista,info);
    else if(pos>0 && pos < lista->num){
        NODO* nuevo = crear_nodo(info);
        NODO* temporal = lista->head;
        int tpos;
        for(tpos = 0; tpos < tpos-1;tpos++){
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
    return true;
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

bool pertenencia(LISTA* lista, INFO info)
{
    if (es_vacia(lista)) return false;
    
    NODO* temporal = lista->head;

    while (temporal != NULL)
    {
        if (comparar(temporal->info, info)) return true;
        temporal = temporal->siguiente;
    }
    return false; // El dato no esta en la lista
}

int cardinal(LISTA* lista)
{
    if (es_vacia(lista))
        return 0;
    return lista -> num;
}

bool comparar(INFO info_1, INFO info_2)
{
    if (info_1 == info_2) return true;
    return false;
}

bool agregar(LISTA* lista, int nuevo_elemento)
{
    if (es_vacia(lista))
    {
        insertar_inicio(lista, nuevo_elemento);
        return true;
    }
    else if (!(pertenencia(lista, nuevo_elemento)))
    {
        insertar_elemento(lista, nuevo_elemento);
        return true;
    }
    else
    {
        printf("\nEse elemento ya pertenece al conjunto\n");
        return false;
    }
}

bool insertar_elemento(LISTA* lista, int nuevo_elemento)
{
    if (nuevo_elemento < lista -> head -> info)
    {
        insertar_inicio(lista, nuevo_elemento);
        return true;
    }
    else if (nuevo_elemento > lista -> tail -> info)
    {
        insertar_final(lista, nuevo_elemento);
        return true;
    }
    else
    {
        NODO* temporal = lista -> head;

        while (temporal -> siguiente != NULL)
        {
            if (nuevo_elemento < temporal -> siguiente -> info)
            {
                NODO* nuevo_nodo = crear_nodo(nuevo_elemento);
                nuevo_nodo -> siguiente = temporal -> siguiente;
                temporal -> siguiente = nuevo_nodo;
                return true;
            }

            temporal = temporal -> siguiente;
        }
    }
        
    return false;
}