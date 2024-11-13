#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void selectionSort(int array[], int n) {
    int i, j, minIndex, temp;

    for (i = 0; i < n - 1; i++) {
        minIndex = i;
        for (j = i + 1; j < n; j++) {
            if (array[j] < array[minIndex]) {
                minIndex = j;
            }
        }
        temp = array[minIndex];
        array[minIndex] = array[i];
        array[i] = temp;
    }
}

void generateRandomArray(int array[], int n) {
    for (int i = 0; i < n; i++) {
        array[i] = rand() % 100000;  // Gera números aleatórios entre 0 e 99.999
    }
}

int main() {
    int n[] = {1, 10, 100, 1000, 10000, 50000, 100000}; // Tamanhos de conjuntos de dados
    int size = sizeof(n) / sizeof(n[0]);
    clock_t inicio, fim;

    for (int i = 0; i < size; i++) {
        int *array = (int *)malloc(n[i] * sizeof(int));
        
        generateRandomArray(array, n[i]);

        printf("Ordenando array de tamanho %d\n", n[i]);
        inicio = clock();
        selectionSort(array, n[i]);
        fim = clock();

        double tempo_cpu = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
        printf("Tempo de execução para %d elementos: %f segundos\n", n[i], tempo_cpu);

        free(array);  // Libera a memória alocada para o array
    }

    return 0;
}
