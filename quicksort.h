#ifndef QUICKSORT_H
#define QUICKSORT_H

void imprimirArray(int arr[], int size);
int partition(int arr[], int low, int high);
void swap(int* a, int* b);

void quicksortRecursivo(int arr[], int low, int high);
void quicksortIterativo(int arr[], int low, int high);

#endif // QUICKSORT_H
