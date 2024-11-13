#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Função de troca utilizada em alguns algoritmos
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Implementação do Selection Sort
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(&arr[minIndex], &arr[i]);
    }
}

// Implementação do Insertion Sort
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Implementação do Bubble Sort
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

// Função auxiliar para o Merge Sort
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }

    while (i < n1)
        arr[k++] = L[i++];
    while (j < n2)
        arr[k++] = R[j++];
}

// Implementação do Merge Sort
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

// Função auxiliar para o Quick Sort
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// Implementação do Quick Sort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Função auxiliar para o Heap Sort
void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

// Implementação do Heap Sort
void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i >= 0; i--) {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

int main() {
    int n = 1000; // Exemplo de tamanho do array
    int arr[n];

    // Preencher o array com números aleatórios
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 10000;
    }

    // Medir o tempo de execução para cada algoritmo de ordenação
    clock_t start, end;

    start = clock();
    selectionSort(arr, n);
    end = clock();
    printf("Selection Sort: %lf segundos\n", ((double)(end - start)) / CLOCKS_PER_SEC);

    start = clock();
    insertionSort(arr, n);
    end = clock();
    printf("Insertion Sort: %lf segundos\n", ((double)(end - start)) / CLOCKS_PER_SEC);

    start = clock();
    bubbleSort(arr, n);
    end = clock();
    printf("Bubble Sort: %lf segundos\n", ((double)(end - start)) / CLOCKS_PER_SEC);

    start = clock();
    mergeSort(arr, 0, n - 1);
    end = clock();
    printf("Merge Sort: %lf segundos\n", ((double)(end - start)) / CLOCKS_PER_SEC);

    start = clock();
    quickSort(arr, 0, n - 1);
    end = clock();
    printf("Quick Sort: %lf segundos\n", ((double)(end - start)) / CLOCKS_PER_SEC);

    start = clock();
    heapSort(arr, n);
    end = clock();
    printf("Heap Sort: %lf segundos\n", ((double)(end - start)) / CLOCKS_PER_SEC);

    return 0;
}
