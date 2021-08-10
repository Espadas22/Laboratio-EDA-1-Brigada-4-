#include "posfija.h"

int main()
{
    //Asignamos los arreglos que guardarán las cadenas
    char infija[150];
    //Auxiliares para la creacion de los nodos
    char operador;
    int prioridad;

    PILA* Operadores = crear_pila();
    COLA* Posfija = crear_pila();

    printf("Introduce una cadena en notacion infija:\n");
    gets(infija);

    //Comenzamos a recorrer la cadena
    for (int i = 0; i < strlen(infija); i++)
    {
        // Si hay espacio en la cadena original, estos no se procesan
        while(isspace(infija[i]))
            i++;
        // Los numeros pasan directo a la cadena posfija
        if (isalnum(infija[i]))
        {
            // Para tomar todos los dígitos que componen un numero
            while (isalnum(infija[i]))
            {
                encolar(Posfija, 0, infija[i], false);
                i++;
            }
            //Se deja un espacio para poder hacer la distincion entre numeros consecutivos
            encolar(Posfija, 0, ' ', false);
        }
        
        // Se vuelven a eliminar los espacio se la cadena
        while(isspace(infija[i]))
            i++;
        
        // Los operadores pasan a la pila

        //Determinamos la prioridad
        operador = infija[i];
        prioridad = determinar_prioridad(operador);

        if (es_vacia(Operadores))
        {
            push(Operadores, prioridad, operador);
        }
        // El parentesis de apertura se coloca sin medir prioridad
        else if (operador == '(')
        {
            push(Operadores, prioridad, operador);
        }
        // En los parentesis de cierra vaciamos la pila
        else if (operador == ')')
        { // Vaciamos los operadores hasta encontrar un "("
            while (Operadores->head->caracter != '(')
            {
                encolar(Posfija, Operadores->head->prioridad, Operadores->head->caracter, true);
                encolar(Posfija, 0, ' ', false);
                pop(Operadores);
            }
            // Eliminamos el "("
            pop(Operadores);
        }
        else // Colocamos los casos en los que se validan operadores
        {    // Si tiene mayor prioridad se agrega directamente
            if (prioridad > Operadores->head->prioridad)
            {
                push(Operadores, prioridad, operador);
            }
            /* En los casos de mayor o igual prioridad se sacan
                operadores hasta encontrae uno con mayor prioridad*/
            else
            {
                while (prioridad <= Operadores->head->prioridad)
                {
                    encolar(Posfija, Operadores->head->prioridad, Operadores->head->caracter, true);
                    encolar(Posfija, 0, ' ', false);
                    pop(Operadores);
                    // Si la lista se vacia, terminamos el ciclo
                    if (es_vacia(Operadores))
                        break;
                }
                // Una vez fuera los operadores mayores introducimos el nuevo
                push(Operadores, prioridad, operador);
            }
        }
    }

    // Se sacan los operadores restantes de la pila
    while (!es_vacia(Operadores))
    {
        encolar(Posfija, Operadores->head->prioridad, Operadores->head->caracter, true);
        encolar(Posfija, 0, ' ', false);
        pop(Operadores);
    }

    printf("\nLa cadena posfija es: ");
    imprimir_cola(Posfija);

    eliminar_pila(Operadores);
    eliminar_pila(Posfija);

    return 0;
}
