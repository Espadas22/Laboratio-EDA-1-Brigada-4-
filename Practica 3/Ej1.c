#include "Ej1.h"
#include <stdlib.h>
#include <stdio.h>

COMPLEJO* crear_lista(float t1,float t2){
    COMPLEJO *ci;
    //le fijamos valores al primer y ultimo elemento
    //asi podemos verificar si se ha modificado/esta vacia la lista
    ci->real = t1;
    ci->complejo = t2;
    return ci;
}
void leerComplejo(COMPLEJO *c){
    printf("¿Cual seria el valor del termino real del numero?\n");
    scanf("%f",&c->real);
    //printf("%f",termino1.real);
    printf("¿Cual seria el valor del termino complejo del numero?\n");
    scanf("%f",&c->complejo);
    //imprimir(c);
}
void suma(COMPLEJO *t1, COMPLEJO *t2, COMPLEJO *resultado){
    resultado->real = (t1->real) + (t2->real);
    resultado->complejo = t1->complejo + t2->complejo;
}

void multiplicacion(COMPLEJO *t1, COMPLEJO *t2, COMPLEJO *resultado){
    resultado->real = (t1->real * t2->real) + ((-1)*(t1->complejo * t2->complejo));
    resultado->complejo = (t1->real * t2->complejo) + (t2->real * t1->complejo);
}
void imprimir(COMPLEJO *c1){
    printf("%.1f",c1->real); 
    if(c1->complejo>=0){
        printf("+");
    }
    printf("%.1fi",c1->complejo);
}
int main(){
    COMPLEJO *resultado = (COMPLEJO*)malloc(sizeof(COMPLEJO));
    
    COMPLEJO termino1; 
    COMPLEJO termino2;

    printf("Bienvenido a la calculadora con numeros complejos.\n");
    printf("Trabajaremos con dos terminos para sumar o multiplicar.\n");

    leerComplejo(&termino1);
    leerComplejo(&termino2);

    suma(&termino1,&termino2,resultado);
    printf("El resultado de la suma es: "); imprimir(resultado); printf("\n");

    multiplicacion(&termino1,&termino2,resultado);
    printf("El resultado de la multiplicacion es: "); imprimir(resultado);
}