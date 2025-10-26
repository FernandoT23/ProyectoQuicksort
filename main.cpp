#include <stdio.h>
#include <stdlib.h>
#include "quicksort.h"

/*Para que genere el ejecutable necesitan abrir la consola y poner esto " g++ main.cpp Quicksort.cpp -o main.exe " */
/*Y para que copile es " .\main.exe " no se pq no me genera el ejecutable siempre mm*/

void menu(){
    printf("\n---MENU PRINCIPAL---\n");
    printf("1. Ingrese datos del arreglo\n");
    printf("2. Ordenar con quicksort Recursivo\n");
    printf("3. Ordenar con quicksort Iterativo\n");
    printf("4. Mostrar arreglo\n");
    printf("5. Salir\n");
    printf("Ingrese su opcion: ");
}

int main() {
    int opcion, n;
    int *arr = NULL;  // puntero dinámico declarado fuera del switch

    do {
        menu();
        scanf("%d", &opcion);

        switch(opcion) {
            case 1: {
                printf("Ingrese el numero de elementos del arreglo: ");
                scanf("%d", &n);
                free(arr); // liberar memoria anterior si existía
                arr = (int*)malloc(n * sizeof(int));
                if (arr == NULL) {
                    printf("Error en la asignacion de memoria.\n");
                    exit(1);
                }
                printf("Ingrese los elementos del arreglo:\n");
                for(int i = 0; i < n; i++)
                    scanf("%d", &arr[i]);
                break;
            }

            case 2:
                quicksortRecursivo(arr, 0, n - 1);
                printf("Arreglo ordenado con quicksort Recursivo.\n");
                break;

            case 3:
                quicksortIterativo(arr, 0, n - 1);
                printf("Arreglo ordenado con quicksort Iterativo.\n");
                break;

            case 4:
                printf("Elementos del arreglo:\n");
                imprimirArray(arr, n);
                break;

            case 5:
                printf("Saliendo del programa.\n");
                break;

            default:
                printf("Opcion invalida. Intente de nuevo.\n");
        }
    } while(opcion != 5);

    free(arr);  // liberar memoria al final
    return 0;
}