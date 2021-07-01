#include "Ejercicio1.h"

PILA* crear_pila()
{
    PILA* nueva_pila = (PILA*) malloc(sizeof(PILA));
    nueva_pila -> head = nueva_pila -> tail = NULL;
    return nueva_pila;
}

NODO* crear_nodo(int prioridad, char operador)
{
    NODO *nuevo_nodo  = (NODO*) malloc(sizeof(NODO));
    nuevo_nodo -> siguiente = NULL;
    nuevo_nodo -> prioridad = prioridad;
    nuevo_nodo -> operador = operador;
    return nuevo_nodo;
}

bool push(PILA *pila, int prioridad, char operador)
{
    NODO* nuevo = crear_nodo(prioridad, operador);
    
    if (pila -> num == 0)
    {
        pila -> head = pila -> tail = nuevo;
    }
    else
    {
        nuevo -> siguiente = pila -> head;
        pila -> head = nuevo;
    }
    pila -> num++;
    
    return true;
}

bool pop(PILA *pila)
{
    if (pila -> num == 0) return false;
    
    NODO *temporal = pila -> head;
    
    if (pila -> num == 1)
    {
        pila -> head = pila -> tail = NULL;
    }
    else
        pila -> head = pila -> head -> siguiente;
    
    temporal -> siguiente = NULL; 
    free(temporal);
    pila -> num--;
    
    return true;
}

int* top(PILA* pila){
    if(es_vacia(pila)) return NULL;
    return &pila->head->prioridad;
}

void eliminar_nodo(NODO *nodo){
    if(nodo->siguiente == NULL){
        free(nodo);
        nodo = NULL;
    }
}

bool es_vacia(PILA *pila){
    if(pila->head == NULL && pila->tail == NULL) return true;
    return false;
}

bool vaciar(PILA *pila){
    if(es_vacia(pila)) return false;
    NODO* temporal = pila->head;
    while(temporal != NULL){
        pila->head = temporal->siguiente;
        temporal -> siguiente = NULL;
        free(temporal);
        temporal = pila->head;
    }
    pila->head = pila->tail = NULL;
    pila->num = 0;
    return true;
}

void eliminar_pila(PILA *pila){
    if(pila == NULL) return;
    if(!es_vacia(pila)){
        vaciar(pila);
    }
    free(pila);
    pila = NULL;
}

void imprimir_pila(PILA *pila)
{
    NODO *temporal = pila -> head;

    if (es_vacia(pila))
    {
        printf("NULL");
        return;
    }

    if (pila -> num > 1)
    {
        while(temporal -> siguiente != NULL)
        {
            printf("%c (%d)--> ", temporal -> operador, temporal -> prioridad);
            temporal = temporal -> siguiente;
        }
    }
    printf("%c (%d)--> NULL\n", pila -> tail -> operador, pila -> tail -> prioridad);
}

int determinar_prioridad(char operador)
{
    int prioridad = 0;
    
    switch (operador)
    {
        case '(':
            prioridad = 0;
            break;
        case ')':
            prioridad = 0;
            break;
        case '+':
            prioridad = 1;
            break;
        case '-':
            prioridad = 1;
            break;
        case '*':
            prioridad = 2;
            break;
        case '/':
            prioridad = 2;
            break;
        case '^':
            prioridad = 3;
            break;
        default:
            break;
    }

    return prioridad;
}
