#include "cola_prioridad.h"

COLA* crear_cola()
{
    COLA* nueva_cola = (COLA*) malloc(sizeof(COLA));
    nueva_cola -> Inicio = nueva_cola -> Fin = NULL;
    nueva_cola -> Numero_nodos = 0;
    return nueva_cola;
}

NODO* crear_nodo(int Info, int Prioridad)
{
    NODO* nuevo_nodo = (NODO*) malloc((sizeof(NODO)));
    nuevo_nodo -> Info = Info;
    nuevo_nodo -> Prioridad = Prioridad;
    nuevo_nodo -> Siguiente = NULL;
    return nuevo_nodo;
}

bool es_vacia(COLA* Cola)
{
    if (Cola -> Inicio == NULL & Cola -> Fin == NULL)
        return true;
    return false;
}

bool enqueue(COLA* Cola, int Info, int Prioridad)
{
    NODO* nuevo_nodo = crear_nodo(Info, Prioridad);

    if (es_vacia(Cola))
    {
        Cola -> Inicio = Cola -> Fin = nuevo_nodo;
        Cola -> Numero_nodos++;
        return true;
    }

    NODO* temporal = Cola -> Inicio;

    // Para los casos en los que el nuevo nodo toma la posicion de inicio
    if (nuevo_nodo -> Prioridad < temporal -> Prioridad)
            {
                nuevo_nodo -> Siguiente = Cola -> Inicio;
                Cola -> Inicio = nuevo_nodo;
                Cola -> Numero_nodos++;
                return true;
            }

    // Recorre la lista hasta que encuentra la prioridad correcta
    for (; temporal -> Siguiente != NULL; temporal = temporal -> Siguiente)
    {
        if (nuevo_nodo -> Prioridad < temporal -> Siguiente -> Prioridad)
            {
                nuevo_nodo -> Siguiente = temporal -> Siguiente;
                temporal -> Siguiente = nuevo_nodo;
                Cola -> Numero_nodos++;
                return true;
            }
    }

    /* Si sale del for es porque no tiene prioridad sobre ningun otro, 
    le asigna el lugar de tail*/
    Cola -> Fin -> Siguiente = nuevo_nodo;
    Cola -> Fin = nuevo_nodo;
    nuevo_nodo -> Siguiente = NULL;
    Cola -> Numero_nodos++;
    return true;
}

bool dequeue(COLA* Cola)
{
    if (es_vacia(Cola))
        return false;
    
    NODO* temporal = Cola -> Inicio;
    Cola -> Inicio = Cola -> Inicio -> Siguiente;
    vaciar_nodo(temporal);
    Cola -> Numero_nodos--;
    return true;
}

bool vaciar_nodo(NODO* Nodo)
{
    Nodo -> Siguiente = NULL;
    free(Nodo);
    return true;
}

bool vaciar_cola(COLA* Cola)
{
    NODO* temporal = Cola -> Inicio;
    while(temporal != NULL)
    {
        Cola -> Inicio = temporal -> Siguiente;
        free(temporal);
        temporal = Cola -> Inicio;
    }

    Cola -> Inicio = Cola -> Fin = NULL;
    Cola -> Numero_nodos = 0;
    return true;
}

bool imprimir_cola(COLA* Cola)
{
    if (es_vacia(Cola))
        return false;

    for (NODO* temporal = Cola -> Inicio; temporal -> Siguiente != NULL; temporal = temporal -> Siguiente)
        {
            printf("%d", temporal -> Info);
            if (temporal -> Siguiente != NULL)
                printf(" -> ");
        }
        printf("%d\n", Cola -> Fin -> Info);
    return true;
}