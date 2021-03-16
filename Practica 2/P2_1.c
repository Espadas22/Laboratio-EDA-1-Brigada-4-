#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Varibales de tipo 
    int Entero;
    char Char;
    double Doble;
    long Largo;
    float Flotante;
    short Corto;

    // Apuntadores a las variables
    int* Apuntador_Entero = &Entero;
    char* Apuntador_Char = &Char;
    double* Apuntador_Doble = &Doble;
    long* Apuntador_Largo = &Largo;
    float* Apuntador_Flotante = &Flotante;
    short* Apuntador_Corto = &Corto;
    
    // Comprobacion de direcciones de memoria
    printf("La direccion de la variable int es %p y la de su apuntador es %p\n", &Entero, Apuntador_Entero);
    printf("La direccion de la variable char es %p y la de su apuntador es %p\n", &Char, Apuntador_Char );
    printf("La dirección de la variable double es %p y la de su apuntador es %p\n", &Doble, Apuntador_Doble);
    printf("La direccion de la variable long es %p y la de su apuntador es %p\n", &Largo, Apuntador_Largo);
    printf("La direccion de la variable flotante es %p y la de su apuntador es %p\n", &Flotante, Apuntador_Flotante);
    printf("La direccion de la variable short es %p y la de su apuntador es %p\n\n", &Corto, Apuntador_Corto);

    // Asignacion de valor a las varibales
    Entero = 12695;
    Char = 'P';
    Doble = 987654321.12346789; 
    Largo = 2147483647214748;
    Flotante = 3.14159;
    Corto = 2;

    //Imprimir los valores de las variables
    printf("El valor de la variable int es: %d\n", *Apuntador_Entero);
    printf("El valor de la variable char es: %c\n", *Apuntador_Char);
    printf("El valor de la variable double es: %lf\n", *Apuntador_Doble);
    printf("El valor de la variable long es: %ld\n", *Apuntador_Largo);
    printf("El valor de la variable float es: %f\n", *Apuntador_Flotante);
    printf("El valor de la variable short es: %hd\n\n", *Apuntador_Corto);

    // Modificacion de valores usando apuntadores
    *Apuntador_Entero = 94357;
    *Apuntador_Char = 'L';
    *Apuntador_Doble = 12346789.987654321; 
    *Apuntador_Largo = -412748364877865423;
    *Apuntador_Flotante = 1.574862;
    *Apuntador_Corto = 7;

    // Impresion de las variables
    printf("El valor de la variable int es: %d\n", Entero);
    printf("El valor de la variable char es: %c\n", Char);
    printf("El valor de la variable double es: %lf\n", Doble);
    printf("El valor de la variable long es: %ld\n", Largo);
    printf("El valor de la variable float es: %f\n", Flotante);
    printf("El valor de la variable short es: %hd\n", Corto);

    return 0;
}
