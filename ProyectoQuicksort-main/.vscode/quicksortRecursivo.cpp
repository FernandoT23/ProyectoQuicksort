#include "quicksort.h"
#include <stdio.h>

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t; //t es temporal y es la funcion para que se intercambien los valores
}

int partition (int arr[], int low, int high){
    int pivot= arr[high];
    int i= (low-1);

    for (int j= low; j<= high-1; j++){
        if (arr[j]<pivot){
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i+1], &arr[high]);
    return(i+1);

}

    void quicksortRecursivo(int arr[], int low, int high){ //esto es el caso base de la recursividad
        if (low<high){
            int indexPivot= partition(arr, low, high);
            quicksortRecursivo(arr, low, indexPivot-1); //el arreglo izquierdo
            quicksortRecursivo(arr, indexPivot+1, high); //el arreglo derecho

        }
    }

    void imprimirArray(int arr[], int size){ //el imprimir el arreglo 
        for (int i=0; i<size; i++){
            printf("%d", arr[i]);
        }
    }
