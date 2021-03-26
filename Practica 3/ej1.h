/*
    Autor: Brigada 4
    Fecha: 18/03/2021
*/
#ifndef EJ1_H
#define EJ1_H


struct _NUM_COMPLEJO{
  
    float real;
    float complejo;
    //char c;
};

typedef struct _NUM_COMPLEJO COMPLEJO;

void suma(COMPLEJO *t1, COMPLEJO *t2, COMPLEJO *resultado);
void multiplicacion(COMPLEJO *t1, COMPLEJO *t2, COMPLEJO *resultado);
void leer(COMPLEJO *t1);
void imprimir(COMPLEJO c1);
#endif
