/*
    Autor: Brigada 4
    Fecha: 11/03/2021
*/

#include <stdio.h>
#include <stdlib.h>

// Generamos los prototipos de las funciones, que usaran apuntadores
void suma(float *a, float *b, float *c);
void resta(float *a, float *b, float *c);
void multiplicacion(float *a, float *b, float *c);
void division(float *a, float *b, float *c);

int main()
{
    // Inicializamos las variables en 0 para evitar que contengan basura
    float operando1 = 0;
    float operando2 = 0;
    float resultado = 0;
    int opcion = 0;

    printf("Bienvenido, ¿que operacion quiere realizar?\n");
    printf("1)Suma\n");
    printf("2)Resta\n");
    printf("3)Multiplicacion\n");
    printf("4)Division\n");
    scanf("%d", &opcion);
    
    // Creamos un switch para llamar la funcion elegida por el usuario
    switch (opcion)
    {
    case 1:
        printf("\n¿Cual seria el valor del primer operando?\n");
        scanf("%f", &operando1);
        printf("\n¿Cual seria el valor del segundo operando?\n");
        scanf("%f", &operando2);
        suma(&operando1, &operando2, &resultado);
        break;
    case 2:
        printf("\n¿Cual seria el valor del primer operando?\n");
        scanf("%f", &operando1);
        printf("\n¿Cual seria el valor del segundo operando?\n");
        scanf("%f", &operando2);
        resta(&operando1, &operando2, &resultado);
        break;
    case 3:
        printf("\n¿Cual seria el valor del primer operando?\n");
        scanf("%f", &operando1);
        printf("\n¿Cual seria el valor del segundo operando?\n");
        scanf("%f", &operando2);
        multiplicacion(&operando1, &operando2, &resultado);
        break;
    case 4:
        printf("\n¿Cual seria el valor del primer operando?\n");
        scanf("%f", &operando1);
        printf("\n¿Cual seria el valor del segundo operando?\n");
        scanf("%f", &operando2);
        division(&operando1, &operando2, &resultado);
        break;
    }

    // Se muestra el resultado al usuario
    printf("El resultado de la operacion es: %.2f\n", resultado);

    return 0;
}

/*
    Implementacion de las funciones.
    Al ser llamadas usan los valores guardados en la direccion de memoria para
    realizar la operacion, por lo que no es necesario ningun valor de retorno
*/

void suma(float *a, float *b, float *c)
{
    *c = *a + *b;
}

void resta(float *a, float *b, float *c)
{
    *c = *a - *b;
}

void multiplicacion(float *a, float *b, float *c)
{
    *c = *a * *b;
}

void division(float *a, float *b, float *c)
{
    *c = *a / *b;
}
