
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertionSort(int array[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = array[i];
        j = i - 1;

        while (j >= 0 && array[j] > key) {
            array[j + 1] = array[j];
            j = j - 1;
        }

        array[j + 1] = key;
    }
}
void generateRandomArray(int array[], int n) {
    for (int i = 0; i < n; i++) {
        array[i] = rand() % 100000;  // Gera números aleatórios entre 0 e 99.999
    }
}

int main() {
    int n[] = {1, 10, 100, 1000, 10000, 50000, 100000};  // Diferentes tamanhos de arrays
    int size = sizeof(n) / sizeof(n[0]);
    clock_t inicio, fim;

    for (int i = 0; i < size; i++) {
        int *array = (int *)malloc(n[i] * sizeof(int));  // Aloca memória dinamicamente para o array
        
        generateRandomArray(array, n[i]);

        printf("Ordenando array de tamanho %d\n", n[i]);

        inicio = clock();
        insertionSort(array, n[i]);
        fim = clock();

        double tempo_cpu = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
        printf("Tempo de execução para %d elementos: %f segundos\n", n[i], tempo_cpu);

        free(array);  // Libera a memória alocada para o array
    }

    return 0;
}