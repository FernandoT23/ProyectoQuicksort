#include <stdio.h>
#include "quicksort.h"
#define MAXSTACK 1000

/*intercambio de los elementos*/

void swap(int* a, int*b){
    int temp= *a;
    *a=*b;
    *b=temp;
}

/* la particion del quicksort*/

int partition (int arr[], int low, int high){
    int pivot= arr[high];
    int i= low-1;
    for(int j= low; j<= high-1; j++){
        if(arr[j]< pivot){
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i+1], &arr[high]);
    return (i + 1);
}

/*Parte recursiva*/
void quicksortRecursivo(int arr[], int low, int high){
    if(low< high){
        int indexPivot= partition(arr, low, high);
        quicksortRecursivo(arr, low, indexPivot-1); // arreglo izquierdo
        quicksortRecursivo(arr, indexPivot+1, high); // arreglo derecho
    }
}

void quicksortIterativo(int arr[], int low, int high){
    int stack[MAXSTACK];
    int top= -1;

    stack[++top]= low;
    stack[++top]= high;

    while(top>=0){
        high= stack[top--];
        low= stack[top--];

        int indexPivot= partition(arr, low, high);

        if(indexPivot-1> low){
            stack[++top]= low;
            stack[++top]= indexPivot-1;
        }

        if(indexPivot+1< high){
            stack[++top]= indexPivot+1;
            stack[++top]= high;
        }
    }
}

void imprimirArray(int arr[], int size){
    for(int i=0; i< size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}