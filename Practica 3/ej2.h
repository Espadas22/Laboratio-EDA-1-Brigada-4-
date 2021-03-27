/*
    Autor: Brigada 4
    Fecha: 18/03/2021
*/
#ifndef POLINOMIO_H
#define POLINOMIO_H

struct _Termino // Struct que almacena el coeficiente y el grado del termino
{
    int Coeficiente;
    int Exponente;
};

typedef struct _Termino TERMINO;

struct _Polinomio
{
    TERMINO* Terminos; // Arreglo dinámico para reservar los terminos del polinomio
    int Grado; // Variable para controlar los terminos de cada polinomio
};

typedef struct _Polinomio POLINOMIO;

POLINOMIO* Crear_polinomio(); // Regresa el apuntador al polinomio creado

void Imprimir_polinomio(POLINOMIO* Polinomio); // Muestra de forma gráfica el polinomio

// Reciben las direcciones de memoria de los polinomios que se van a sumar/restar
POLINOMIO* Sumar_polinomios(POLINOMIO* Polinomio_1, POLINOMIO* Polinomio_2);
POLINOMIO* Restar_polinomios(POLINOMIO* Polinomio_1, POLINOMIO* Polinomio_2);

void Liberar_polinomio(POLINOMIO* Polinomio); // Libera la memoria reservada para el polinomio

#endif
