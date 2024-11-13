#include <stdio.h>    // Biblioteca para entrada e saída
#include <stdlib.h>   // Biblioteca para funções gerais, como geração de números aleatórios
#include <time.h>     // Biblioteca para medir o tempo de execução

// Função para gerar um array de inteiros aleatórios
void generateRandomArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 10000; // Gera números entre 0 e 9999
    }
}

// Função auxiliar para mesclar dois subarrays em ordem
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;    // Tamanho do subarray esquerdo
    int n2 = right - mid;       // Tamanho do subarray direito
    int L[n1], R[n2];           // Arrays temporários para armazenar os subarrays

    // Copia os dados para os arrays temporários L[] e R[]
    for (int i = 0; i < n1; i++) {
        L[i] = arr[left + i];
    }
    for (int i = 0; i < n2; i++) {
        R[i] = arr[mid + 1 + i];
    }

    // Mescla os arrays temporários de volta em arr[]
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copia os elementos restantes de L[], se houver
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copia os elementos restantes de R[], se houver
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Função principal do Merge Sort
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;  // Encontra o ponto médio do array
        mergeSort(arr, left, mid);            // Ordena a primeira metade
        mergeSort(arr, mid + 1, right);       // Ordena a segunda metade
        merge(arr, left, mid, right);         // Mescla as duas metades ordenadas
    }
}

// Função para medir o tempo de execução do Merge Sort
double measureMergeSort(int arr[], int size) {
    clock_t start, end;                  // Variáveis para armazenar o tempo de início e fim
    start = clock();                     // Marca o tempo de início
    mergeSort(arr, 0, size - 1);         // Executa o Merge Sort
    end = clock();                       // Marca o tempo de fim
    return ((double)(end - start)) / CLOCKS_PER_SEC; // Retorna o tempo em segundos
}

// Função principal para teste
int main() {
    int sizes[] = {100, 1000, 10000, 50000, 100000}; // Tamanhos dos arrays para teste
    int numSizes = sizeof(sizes) / sizeof(sizes[0]); // Número de tamanhos de array
    double timeSpent;

    printf("Tempo de execução do Merge Sort:\n");

    for (int i = 0; i < numSizes; i++) {
        int size = sizes[i];
        int arr[size];
        
        // Gera um array aleatório e mede o tempo de execução
        generateRandomArray(arr, size);
        timeSpent = measureMergeSort(arr, size);

        // Imprime o tempo de execução para o tamanho atual do array
        printf("Tamanho do Array: %d -> Tempo: %f segundos\n", size, timeSpent);
    }

    return 0;
}
