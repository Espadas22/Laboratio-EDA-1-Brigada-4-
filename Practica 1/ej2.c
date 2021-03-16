/*
    Autor: Brigada 4
    Fecha: 04/03/2021
*/
#include <stdio.h>

int main()
{
    int matriz[3][3];
    
    printf("Direccion de memoria de los elementos de la matriz son:\n\n");
    
    for (int i = 0; i  < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            /* Usamos la progresion de los for para acceder a la direccion de 
               memoria de cada elemento */
            printf("Direccion de [%i][%i]: %p\n", i, j, &matriz[i][j]);
        }
    }
    
    printf("\nLa dirección de memoria del arreglo es: %p\n", &matriz);

    return 0;
} 