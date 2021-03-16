/*
    Autor: Brigada 4
    Fecha: 11/03/2021
*/
#include <stdio.h>
#include <stdlib.h>

int main(){

    //a) Declaracion de los apuntadores de distinto tipo
    int *ApuntadorInt;
    char *ApuntadorChar;
    double *ApuntadorDouble;
    long *ApuntadorLong;
    float *ApuntadorFloat;
    short *ApuntadorShort;

    //b) Reserva de memoria para los datos en esa dirección de memoria
    ApuntadorInt = (int*)malloc(sizeof(int));
    ApuntadorChar = (char*)malloc(sizeof(char));
    ApuntadorDouble = (double*)malloc(sizeof(double));
    ApuntadorLong = (long*)malloc(sizeof(long));
    ApuntadorFloat = (float*)malloc(sizeof(float));
    ApuntadorShort = (short*)malloc(sizeof(short));

    //c) Mostramos la direccion enviando a imprimir los apuntadores
    printf("La direccion de memoria del apuntador a entero es: %p\n", ApuntadorInt);
    printf("La direccion de memoria del apuntador a char es: %p\n", ApuntadorChar);
    printf("La direccion de memoria del apuntador a double es: %p\n", ApuntadorDouble);
    printf("La direccion de memoria del apuntador a long es: %p\n", ApuntadorLong);
    printf("La direccion de memoria del apuntador a float es: %p\n", ApuntadorFloat);
    printf("La direccion de memoria del apuntador a short es: %p\n\n", ApuntadorShort);

    //d) Asignamos valor usando la desferenciacion de los apuntadores
    *ApuntadorInt = 1224;
    *ApuntadorChar = 'M';
    *ApuntadorDouble = 320012.3287621; 
    *ApuntadorLong = -144565423;
    *ApuntadorFloat = 7.777777;
    *ApuntadorShort = 4;
    
    // Imprimir los valores de las variables usando el mismo operador '*'
    printf("El valor de la variable anonima int es: %d\n", *ApuntadorInt);
    printf("El valor de la variable anonima char es: %c\n", *ApuntadorChar);
    printf("El valor de la variable anonima double es: %lf\n", *ApuntadorDouble);
    printf("El valor de la variable anonima long es: %ld\n", *ApuntadorLong);
    printf("El valor de la variable anonima float es: %f\n", *ApuntadorFloat);
    printf("El valor de la variable anonima short es: %hd\n\n", *ApuntadorShort);

    //e) Cambiamos los valores
    *ApuntadorInt = 94357;
    *ApuntadorChar = 'L';
    *ApuntadorDouble = 12346789.987654321; 
    *ApuntadorLong = -412748364877865423;
    *ApuntadorFloat = 1.574862;
    *ApuntadorShort = 7;
    
    // Imprimir los valores de las variables
    printf("La modificacion de la variable anonima int es: %d\n", *ApuntadorInt);
    printf("La modificacion variable anonima char es: %c\n", *ApuntadorChar);
    printf("La modificacion variable anonima double es: %lf\n", *ApuntadorDouble);
    printf("La modificacion variable anonima long es: %ld\n", *ApuntadorLong);
    printf("La modificacion variable anonima float es: %f\n", *ApuntadorFloat);
    printf("La modificacion variable anonima short es: %hd\n\n", *ApuntadorShort);

    //f) Se libera la memoria reservada
    free(ApuntadorInt);
    free(ApuntadorChar);
    free(ApuntadorDouble);
    free(ApuntadorLong);
    free(ApuntadorFloat);
    free(ApuntadorShort);

}