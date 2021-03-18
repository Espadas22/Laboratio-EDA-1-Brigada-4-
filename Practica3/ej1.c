#include "ej1.h"
#include <stdlib.h>
#include <stdio.h>

COMPLEJO crear_lista(){
    COMPLEJO ci;
    //le fijamos valores al primer y ultimo elemento
    //asi podemos verificar si se ha modificado/esta vacia la lista
    ci.real = 0;
    ci.complejo = 0;
    return ci;
}

void suma(COMPLEJO *t1, COMPLEJO *t2, COMPLEJO *resultado){   
    resultado->real = t1->real + t2->real;
    resultado->complejo = t1->complejo + t2->complejo;
    printf("El resultado de la suma es: ");
    imprimir(*resultado);
    printf("\n");
}

void multiplicacion(COMPLEJO *t1, COMPLEJO *t2, COMPLEJO *resultado){
    resultado->real = (t1->real * t2->real) + ((-1)*(t1->complejo * t2->complejo));
    resultado->complejo = (t1->real * t2->complejo) + (t2->real * t1->complejo);
    printf("El resultado de la multiplicacion es: ");
    imprimir(*resultado);
}
void imprimir(COMPLEJO c1){
    printf("%.1f",c1.real); 
    if(c1.complejo>=0){
        printf("+");
    }
    printf("%.1fi",c1.complejo);
}
int main(){
    COMPLEJO resultado = crear_lista();
    COMPLEJO termino1 = crear_lista();
    COMPLEJO termino2 = crear_lista();

    printf("Bienvenido a la calculadora con numeros complejos.\n");
    printf("Trabajaremos con dos terminos para sumar o multiplicar.\n");

    printf("¿Cual seria el valor del termino real del primer termino?\n");
    scanf("%f",&termino1.real);
    //printf("%f",termino1.real);
    printf("¿Cual seria el valor del termino complejo del primer termino?\n");
    scanf("%f",&termino1.complejo);

    printf("¿Cual seria el valor del termino real del segundo termino?\n");
    scanf("%f",&termino2.real);
    //printf("%f",termino1.real);
    printf("¿Cual seria el valor del termino complejo del segundo termino?\n");
    scanf("%f",&termino2.complejo);
    
    suma(&termino1,&termino2,&resultado);
    multiplicacion(&termino1,&termino2,&resultado);
}
