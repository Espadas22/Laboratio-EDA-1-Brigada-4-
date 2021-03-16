/*
    Autor: Brigada 4
    Fecha: 04/03/2021
*/
#include <stdio.h>

int main()
{
    int arr3[3][2][4];

    printf("Las direcciones de memoria del arreglo 3x2x4 son:\n\n");

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            for (int l = 0; l < 4; l++)
            {
                printf("La direccion de [%i][%i][%i] es: %p \n", i, j, l, &arr3[i][j][l]);
            }

            printf("\n");
        }

        printf("\n");
    }

    printf("\nLa direccion del arreglo 3x2x4 es: %p", &arr3);
    
    return 0;
}