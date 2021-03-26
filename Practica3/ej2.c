/*
    Autor: Brigada 4
    Fecha: 18/03/2021
*/

#include "ej2.h"
#include <stdlib.h>
#include <stdio.h>

int main()
{
    POLINOMIO* Polinomio = Crear_polinomio();
    Imprimir_polinomio(Polinomio);
    Liberar_polinomio(Polinomio);
    return 0;
}

POLINOMIO* Crear_polinomio()
{
    POLINOMIO* Polinomio = NULL; // Apuntador auxiliar para la funcion
    Polinomio = (POLINOMIO*) malloc(sizeof(POLINOMIO)); // Reservamos la memoria para el apuntador
    printf("De que grado sera el polinomio? ");
    scanf("%d", &Polinomio->Grado); // Capturamos el maximo grado del polinomio
    Polinomio -> Terminos = (TERMINO*) malloc((Polinomio -> Grado + 1) * sizeof(TERMINO)); // Generamos la memoria necesaria

    for (int i = Polinomio -> Grado; i >= 0; i--, Polinomio -> Terminos++) // Capturamos los coeficientes y exponentes de cada termino
    {
        if (i == 0) 
            printf("Ingresa el termino independiente: ");
        else
            printf("Ingresa el coeficiente para el exponente %d: ", i);
        
        scanf("%d", &Polinomio -> Terminos -> Coeficiente); // Se registra el coeficiente del termino
        Polinomio -> Terminos -> Exponente = i; // Se registra el exponente que representa
    }

    Polinomio -> Terminos -= Polinomio -> Grado+1; // Devolvemoss al apuntador a la posicion inicial

    return Polinomio;
}

void Imprimir_polinomio(POLINOMIO* Polinomio)
{
    for (int i = 0; i <= Polinomio -> Grado; i++, Polinomio -> Terminos++)
    {
        if (Polinomio -> Terminos -> Coeficiente == 0)
            continue; // Si el coeficiente es 0 no se imprime
        else if(i == Polinomio -> Grado)
            printf("%d\n", Polinomio -> Terminos -> Coeficiente);
        else
            printf("%dx^%d + ", Polinomio -> Terminos -> Coeficiente, Polinomio -> Terminos -> Exponente);
    }

    Polinomio -> Terminos -= Polinomio -> Grado + 1; // Devolvemos al apuntador a su posision original
}

bool Sumar_polinomios(POLINOMIO* Polinomio_1, POLINOMIO* Polinomio_2)
{

}

bool Restar_polinomios(POLINOMIO* Polinomio_1, POLINOMIO* Polinomio_2)
{

}

void Liberar_polinomio(POLINOMIO* Polinomio)
{
    free(Polinomio -> Terminos); // Liberamos el espacio de los terminos
    free(Polinomio); // Liberamos el espacio del polinomio
}
