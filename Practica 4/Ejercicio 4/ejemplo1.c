#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv){
    int *array = NULL, *array2 = NULL,num, cont;
    printf("¿Cuantos elementos tiene el arreglo?");
    scanf("%d",&num);
    array = (int*)calloc(num, sizeof(int));
    if(array != NULL){
        printf("Vector reservado: \n\t[");
        for(cont = 0; cont < num; cont++){
            printf("Ingresa el elemento %d\n", cont+1);
            scanf("%d",(array+cont));
        }
        printf("Vector reservado: \n\t");
        for(cont = 0; cont < num; cont++){
            printf("\tvalor:%d dir: %p", *(array+cont),array+cont);   
        }
        printf("\t]\n");
        num /= 3;
        array2 = (int*)realloc(array,num*sizeof(int));
        if(array != NULL){
            printf("Vector reservado: \n\t[");
            for(; cont < num; cont++){
                printf("Ingresa el elemento %d\n", cont+1);
                scanf("%d",(array+cont));
            }
            printf("Vector reservado: \n\t");
            for(cont = 0; cont < num; cont++){
                printf("\tvalor:%d dir: %p", *(array+cont),array+cont);   
            }
        }
        printf("\t]\n");
        printf("La memoria esta liberada.");
        free(array);
    }
    return 0;
}