#include "posfija.h"

PILA* crear_pila()
{
    PILA* nueva_pila = (PILA*) malloc(sizeof(PILA));
    nueva_pila -> head = nueva_pila -> tail = NULL;
    return nueva_pila;
}

NODO* crear_nodo(int prioridad, char caracter, bool operador)
{
    NODO *nuevo_nodo  = (NODO*) malloc(sizeof(NODO));
    nuevo_nodo -> siguiente = NULL;
    nuevo_nodo -> prioridad = prioridad;
    nuevo_nodo -> caracter = caracter;
    nuevo_nodo -> operador = operador;
    return nuevo_nodo;
}

bool push(PILA *pila, int prioridad, char caracter)
{
    NODO* nuevo = crear_nodo(prioridad, caracter, true);
    
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

bool encolar(COLA* cola, int prioridad, char caracter, bool operador)
{
    NODO* temporal = crear_nodo(prioridad, caracter, operador);

    if (cola -> num == 0)
    {
        cola -> head = cola -> tail = temporal;
        cola -> num++;
    }
    else
    {
        cola -> tail -> siguiente = temporal;
        cola -> tail = temporal;
        cola -> num++;
    }

    return true;

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

void imprimir_cola(COLA* cola)
{
    NODO *temporal = cola -> head;

    if (es_vacia(cola))
    {
        printf("NULL");
        return;
    }

    if (cola -> num > 1)
    {
        while(temporal -> siguiente != NULL)
        {
            printf("%c", temporal -> caracter);
            temporal = temporal -> siguiente;
        }
    }
    printf("%c\n", temporal -> caracter);
}

int determinar_prioridad(char caracter)
{
    int prioridad = 0;
    
    switch (caracter)
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
