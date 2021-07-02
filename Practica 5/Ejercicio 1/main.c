#include "Ejercicio1.h"

int main()
{
    //Asignamos los arreglos que guardarán las cadenas
    char infija[150];
    char posfija[150];
    //Para llevar el control de los elementos dentro de la nueva cadena
    int elementos_pos = 0;
    //Auxiliares para la creacion de los nodos
    char operador;
    int prioridad;

    PILA *Operadores = crear_pila();

    printf("Introduce una cadena en notacion infija (sin espacios):\n");
    scanf("%s", infija);

    //Comenzamos a recorrer la cadena
    for (int i = 0; i < strlen(infija); i++)
    {
        // Los numeros pasan directo a la cadena posfija
        if (isalnum(infija[i]))
        {
            // Para tomar todos los dígitos que componen un numero
            while (isalnum(infija[i]))
            {
                posfija[elementos_pos] = infija[i];
                elementos_pos++;
                //Pasamos a la siguiente posicicion de la cadena
                i++;
            }
            //Se deja un espacio para poder hacer la distincion
            posfija[elementos_pos] = ' ';
            elementos_pos++;
        }
        
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
            while (Operadores->head->operador != '(')
            {
                posfija[elementos_pos] = Operadores->head->operador;
                elementos_pos++;
                posfija[elementos_pos] = ' ';
                elementos_pos++;
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
                    posfija[elementos_pos] = Operadores->head->operador;
                    elementos_pos++;
                    posfija[elementos_pos] = ' ';
                    elementos_pos++;
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
        posfija[elementos_pos] = Operadores->head->operador;
        elementos_pos++;
        posfija[elementos_pos] = ' ';
        elementos_pos++;
        pop(Operadores);
    }

    //Se agrega el caracter nulo y se imprime la cadena posfija
    posfija[elementos_pos] = '\0';
    printf("\nLa cadena posfija es:\n%s\n", posfija);

    return 0;
}