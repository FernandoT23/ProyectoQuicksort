#include <iostream>
#include <stack>
using namespace std;

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSortIterativo(int arr[], int l, int h) {
    stack<int> pila;
    pila.push(l);
    pila.push(h);

    while (!pila.empty()) {
        h = pila.top(); pila.pop();
        l = pila.top(); pila.pop();

        int p = partition(arr, l, h);

        if (p - 1 > l) {
            pila.push(l);
            pila.push(p - 1);
        }
        if (p + 1 < h) {
            pila.push(p + 1);
            pila.push(h);
        }
    }
}

int main() {
    int arr[] = {4, 2, 6, 9, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    quickSortIterativo(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;

//probando
}