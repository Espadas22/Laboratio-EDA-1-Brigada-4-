/*
    Autor: Brigada 4
    Fecha: 11/03/2021
*/
#include <stdio.h>

int main(){
    int arr[10]={0,1,2,3,4,5,6,7,8,9};
    int *ptr;
    
    arr[1]=5; // equivale a *(arr+1)= 5
    ptr = &arr[2];

    // Se envia la direccion de memoria contenida en el apuntador (arr[2])
    printf("a) ptr: %p\n", ptr);

    // Se envia el valor dentro de la direccion de memoria contenida en ptr (2)
    printf("b) *ptr: %d\n", *ptr);
    
    // Mostramos la direccion del indice 0 del apuntador
    printf("c) ptr(0): %p\n", &ptr[0]);
    
    // Se esta imprimiendo el valor contenido en ptr (2) mas 6 unidades (8) 
    printf("d) *ptr + 6: %d\n", *ptr + 6);
    
    /* 
        Se esta avanzando 6 posiciones en el arreglo desde la posicion a la que apunta ptr
        para despues imprimir el valor que contiene (8)
    */
    printf("e) *(ptr + 6): %d\n", *(ptr+6));
    
    /* Se retrocede una posicion desde la que esta siendo apuntada por ptr (arr[2]) 
        hasta arr[1] y se imprime su valor (5)
    */
    printf("f) *ptr(-1): %d\n", ptr[-1]);
    
    // Imprime una direccion de memoria anterior a la que apunta ptr
    printf("g) ptr(-1): %p\n", &ptr[-1] );
    
    /* 
        Imprime 9 posicion delante de la cual apunta ptr; como ptr ya apuntaba a arr[2]
        esta direccion ya se encuentra fuera del arreglo
    */
    printf("h) ptr(9): %p\n", &ptr[9]);
    
    // Direccion del primer elemento del arreglo
    printf("i) Escriba la dirección de arr: %p\n", &arr);
    
    // Direccion donde se guardan los datos del puntero
    printf("j) Escriba la dirección de ptr: %p\n", &ptr);
    
    // Direccion guardada dentro del puntero
    printf("k) Escriba la dirección a la que apunta ptr: %p\n", ptr);
    
    return 0;
}