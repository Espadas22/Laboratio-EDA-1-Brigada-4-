int main()
{
    COLA* cola = crear_cola();

    enqueue(cola, 5, 3);
    imprimir_cola(cola);

    enqueue(cola, 8, 2);
    imprimir_cola(cola);

    enqueue(cola, 7, 1);
    imprimir_cola(cola);

    enqueue(cola, 6, 1);
    imprimir_cola(cola);

    dequeue(cola);
    imprimir_cola(cola);

    enqueue(cola, 4, 2);
    imprimir_cola(cola);

    dequeue(cola);
    imprimir_cola(cola);

    enqueue(cola, 9, 3);
    imprimir_cola(cola);

    dequeue(cola);
    imprimir_cola(cola);

    enqueue(cola, 2, 1);
    imprimir_cola(cola);

    vaciar_cola(cola);
    free(cola);

    return 0;
}
