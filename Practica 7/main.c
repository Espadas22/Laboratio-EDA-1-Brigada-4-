int main(){
    LISTA *conjunto = crear_lista();
    int repetir = 1;
    int nuevo_elemento = 0;
    
    do 
    {
        printf("\nAgrega un elemento entero al conjunto: ");
        scanf("%d", &nuevo_elemento);

        agregar(conjunto, nuevo_elemento);

        printf("\nQuieres agregar otro elemento? (1) Si (0)No\n");
        scanf("%d", &repetir);

    } while (repetir);
    
    printf("\nEl conjunto final es:\n");
    imprimir_lista(conjunto);
    
    vaciar(conjunto);
    free(conjunto);

    return 0;
}