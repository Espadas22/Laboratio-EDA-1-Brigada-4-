#include "bicola.h"

int main(){

    COLA *C1 = crear_cola();

    insertar_fin(C1, 1);
    imprimir_cola(C1); // 1 -> NULL
    insertar_inicio(C1, 3);
    imprimir_cola(C1); // 3 -> 1 -> NULL
    insertar_inicio(C1, 7);
    imprimir_cola(C1); // 7 -> 3 -> 1 -> NULL
    insertar_inicio(C1, 8);
    imprimir_cola(C1); // 8 -> 7 -> 3 -> 1 -> NULL
    insertar_fin(C1, 0);  
    imprimir_cola(C1); // 8 -> 7 -> 3 -> 1 -> 0 -> NULL
    insertar_fin(C1, 12); 
    imprimir_cola(C1); // 8 -> 7 -> 3 -> 1 -> 0 -> 12 -> NULL
    eliminar_fin(C1);
    imprimir_cola(C1); // 8 -> 7 -> 3 -> 1 -> 0 -> NULL
    eliminar_inicio(C1);
    imprimir_cola(C1); // 7 -> 3 -> 1 -> 0 -> NULL

    vaciar(C1); 

    free(C1);
    
    return 0;

}
