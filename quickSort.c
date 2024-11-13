#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Função para realizar a troca de dois elementos no array
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Função para particionar o array, escolhendo o último elemento como pivô
int partition(int arr[], int low, int high) {
    // Escolher o último elemento como pivô
    int pivot = arr[high];
    int i = (low - 1); // Índice do menor elemento

    // Reorganizar os elementos em torno do pivô
    for (int j = low; j <= high - 1; j++) {
        // Se o elemento atual for menor ou igual ao pivô, move para a esquerda
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    // Coloca o pivô no lugar correto
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// Função recursiva do Quick Sort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // Encontrar o índice do pivô que divide o array em duas partes
        int pi = partition(arr, low, high);

        // Chamar recursivamente para a sublista à esquerda e à direita do pivô
        quickSort(arr, low, pi - 1);   // Sublista à esquerda
        quickSort(arr, pi + 1, high);  // Sublista à direita
    }
}

// Função para medir o tempo de execução e testar o algoritmo com diferentes tamanhos de array
int main() {
    // Definindo os tamanhos dos arrays a serem testados
    int sizes[] = {100, 1000, 10000, 50000, 100000};
    int numTests = sizeof(sizes) / sizeof(sizes[0]);
    
    // Loop para testar os diferentes tamanhos de array
    for (int i = 0; i < numTests; i++) {
        int size = sizes[i];
        
        // Alocando memória para o array
        int *arr = (int*)malloc(size * sizeof(int));
        
        // Preenchendo o array com números aleatórios
        for (int j = 0; j < size; j++) {
            arr[j] = rand() % 1000000;  // Números aleatórios de até 1.000.000
        }

        // Iniciando a medição do tempo
        clock_t start = clock();
        
        // Chamando a função quickSort para ordenar o array
        quickSort(arr, 0, size - 1);
        
        // Parando a medição do tempo
        clock_t end = clock();
        
        // Calculando o tempo de execução
        double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

        // Exibindo o tempo de execução para o tamanho atual do array
        printf("Tempo de execução para array de tamanho %d: %.6f segundos\n", size, time_taken);
        
        // Liberando a memória alocada para o array
        free(arr);
    }
    
    return 0;
}
