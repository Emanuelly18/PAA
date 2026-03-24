#include <stdio.h>
#include <time.h>

void bubbleSort(int v[], int n, int *operacoes) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            (*operacoes)++; // comparação
            if (v[j] > v[j + 1]) {
                int temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
                (*operacoes)++; // troca
            }
        }
    }
}

int main() {
    int v[] = {3, 7, 2, 9, 5, 4, 8, 11, 10};
    int n = 9;
    int operacoes = 0;

    clock_t inicio, fim;

    inicio = clock();

    bubbleSort(v, n, &operacoes);

    int maior = v[n - 1];
    int menor = v[0];

    fim = clock();

    double tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;

    printf("Menor: %d\n", menor);
    printf("Maior: %d\n", maior);
    printf("Operacoes: %d\n", operacoes);
    printf("Tempo: %f segundos\n", tempo);

    return 0;
}

/* Mesmo adicionando a parte de escolha, a complexidade continua O(n²), 
porque a ordenação domina o custo do algoritmo.
A escolha do maior e menor é O(1), então não impacta significativamente. */

/* Lembrete: O(n²) é pq compara varios pares repetidamente.
O(n) é apenas percorrer o vetor. */

// crescente
// Ordenação O(n^2) É a parte lenta do código.