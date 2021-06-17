int main(){
    LISTA* lista;

    lista = crear_lista();

    insertar_inicio(lista, 5);
    imprimir_lista(lista);

    insertar_final(lista, 7);
    imprimir_lista(lista);

    insertar(lista, 4, 1);
    imprimir_lista(lista);

    insertar(lista, 9, 2);
    imprimir_lista(lista);

    vaciar(lista);

    return 0;
}