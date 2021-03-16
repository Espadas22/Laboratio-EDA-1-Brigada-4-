/*
    Autor: Brigada 4
    Fecha: 04/03/2021
*/
#include <stdio.h>

int main(){
    int arr[10];
    
    printf("Direccion de memoria de elementos del arreglo:\n");
    
    for(int i = 0; i < 10; i++)
    {
        printf("%p\n",&arr[i]); // Segun el ciclo avanza se imprime la direccion de cada elemento
    }
    
    printf("La direccion del primer elemento es: %p\n",&arr[0]);
    printf("La direccion del arreglo es: %p", &arr);

    return 0;
}