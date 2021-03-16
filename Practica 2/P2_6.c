/*
    Autor: Brigada 4
    Fecha: 11/03/2021
*/

#include <stdio.h>
#include <stdlib.h>

// Generamos los prototipos de las funciones, que usaran apuntadores
void Suma(float *Operando_1, float *Operando_2, float *Resultado);
void Resta(float *Operando_1, float *Operando_2, float *Resultado);
void Multiplicacion(float *Operando_1, float *Operando_2, float *Resultado);
void Division(float *Operando_1, float *Operando_2, float *Resultado);

int main()
{
    // Inicializamos las variables en 0 para evitar que contengan basura
    float Operando_1 = 0;
    float Operando_2 = 0;
    float Resultado = 0;
    int Opcion = 0;

    printf("Bienvenido, ¿que operacion quiere realizar?\n");
    printf("1)Suma\n");
    printf("2)Resta\n");
    printf("3)Multiplicacion\n");
    printf("4)Division\n");
    scanf("%d", &Opcion);
    
    // Creamos un switch para llamar la funcion elegida por el usuario
    switch (Opcion)
    {
    case 1:
        printf("\n¿Cual seria el valor del primer operando?\n");
        scanf("%f", &Operando_1);
        printf("\n¿Cual seria el valor del segundo operando?\n");
        scanf("%f", &Operando_2);
        Suma(&Operando_1, &Operando_2, &Resultado);
        break;
    case 2:
        printf("\n¿Cual seria el valor del primer operando?\n");
        scanf("%f", &Operando_1);
        printf("\n¿Cual seria el valor del segundo operando?\n");
        scanf("%f", &Operando_2);
        Resta(&Operando_1, &Operando_2, &Resultado);
        break;
    case 3:
        printf("\n¿Cual seria el valor del primer operando?\n");
        scanf("%f", &Operando_1);
        printf("\n¿Cual seria el valor del segundo operando?\n");
        scanf("%f", &Operando_2);
        Multiplicacion(&Operando_1, &Operando_2, &Resultado);
        break;
    case 4:
        printf("\n¿Cual seria el valor del primer operando?\n");
        scanf("%f", &Operando_1);
        printf("\n¿Cual seria el valor del segundo operando?\n");
        scanf("%f", &Operando_2);
        Division(&Operando_1, &Operando_2, &Resultado);
        break;
    }

    // Se muestra el resultado al usuario
    printf("El resultado de la opercion es: %f\n", Resultado);

    return 0;
}

/*
    Implementacion de las funciones.
    Al ser llamadas usan los valores guardados en el operando para
    realizar la operacion que se almacenara en el resultado
*/

void Suma(float *Operando_1, float *Operando_2, float *Resultado)
{
    *Resultado = *Operando_1 + *Operando_2;
}

void Resta(float *Operando_1, float *Operando_2, float *Resultado)
{
    *Resultado = *Operando_1 - *Operando_2;
}

void Multiplicacion(float *Operando_1, float *Operando_2, float *Resultado)
{
    *Resultado = *Operando_1 * *Operando_2;
}

void Division(float *Operando_1, float *Operando_2, float *Resultado)
{
    *Resultado = *Operando_1 / *Operando_2;
}