#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Função para realizar a troca de dois elementos no array
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Função para "heapificar" o subárvore com a raiz no índice 'i', assumindo que os filhos já são heaps
void heapify(int arr[], int n, int i) {
    int largest = i;           // Inicializa largest como raiz
    int left = 2 * i + 1;      // Filho esquerdo
    int right = 2 * i + 2;     // Filho direito

    // Verifica se o filho esquerdo é maior que a raiz
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // Verifica se o filho direito é maior que a raiz ou o filho esquerdo
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // Se o maior não for a raiz, troca e "heapifica" recursivamente
    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

// Função para ordenar o array usando Heap Sort
void heapSort(int arr[], int n) {
    // Construção do heap (reorganiza o array para ser um max heap)
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    // Extrai os elementos do heap um por um
    for (int i = n - 1; i >= 0; i--) {
        // Move a raiz (o maior elemento) para o final
        swap(&arr[0], &arr[i]);

        // Chama heapify na subárvore que não contém o elemento no final
        heapify(arr, i, 0);
    }
}

// Função para medir o tempo de execução e realizar os testes com diferentes tamanhos de arrays
int main() {
    // Tamanhos dos arrays a serem testados
    int sizes[] = {100, 1000, 10000, 50000, 100000};
    int numTests = sizeof(sizes) / sizeof(sizes[0]);

    // Loop para testar os diferentes tamanhos de array
    for (int i = 0; i < numTests; i++) {
        int size = sizes[i];

        // Alocando memória para o array
        int *arr = (int*)malloc(size * sizeof(int));

        // Preenchendo o array com números aleatórios
        for (int j = 0; j < size; j++) {
            arr[j] = rand() % 1000000;  // Números aleatórios entre 0 e 999999
        }

        // Iniciando a medição do tempo
        clock_t start = clock();

        // Chamando a função heapSort para ordenar o array
        heapSort(arr, size);

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
