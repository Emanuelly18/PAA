#include <stdio.h>
#include <time.h>

void bubbleSort(int v[], int n, int *operacoes) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            (*operacoes)++;
            if (v[j] > v[j + 1]) {
                int temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
                (*operacoes)++;
            }
        }
    }
}

void testarVetor(int v[], int n) {
    int operacoes = 0;
    clock_t inicio, fim;

    inicio = clock();

    bubbleSort(v, n, &operacoes);

    int menor = v[0];
    int maior = v[n - 1];

    fim = clock();

    double tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;

    printf("\nResultado:\n");
    printf("Menor: %d\n", menor);
    printf("Maior: %d\n", maior);
    printf("Operacoes: %d\n", operacoes);
    printf("Tempo: %f segundos\n", tempo);
}

int main() {

    int vetor1[] = {3, 7, 2, 9, 5, 4, 8, 11, 10};
    int vetor2[] = {10, 4, 6, 8, 1, 15, 3, 12, 1, 2, 7, 11, 5, 14};

    int n1 = 9;
    int n2 = 14;

    printf("=== Vetor 1 ===\n");
    testarVetor(vetor1, n1);

    printf("\n=== Vetor 2 ===\n");
    testarVetor(vetor2, n2);

    return 0;
}
