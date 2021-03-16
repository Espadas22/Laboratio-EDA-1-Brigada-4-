#include <stdio.h>

int main(){
    int arr[10]={0,1,2,3,4,5,6,7,8,9};
    int *ptr;
    
    arr[1]=5; // equivale a *(arr+1)= 5
    ptr &arr[2];

    printf("a) ptr: %d\n", &ptr);
    printf("b) *ptr: %d\n", *ptr);
    printf("c) ptr[0]: %d\n", &ptr[0]);
    printf("d) *ptr+ 6: %d\n", *ptr+6);
    printf("e) *(ptr+6): %d\n", *(ptr+6));
    printf("f) *ptr(-1): %d\n", *ptr(-1));
    printf("g) ptr[-1]: %d\n", &ptr[-1] );
    printf("h) ptr[9]: %d\n", &ptr[9]);
    printf("i) Escriba la dirección de arr: %p\n", &arr);
    printf("j) Escriba la dirección de ptr: %p\n", &ptr);
    printf("k) Escriba la dirección a la que apunta ptr: %p\n", ptr);
    
    return 0;
}