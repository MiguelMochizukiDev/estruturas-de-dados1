/**
 * exercicio_vetores06.c
 * Autor: Miguel Mochizuki Silva
 * Descricao:
 * Mostrar de forma ordenada crescente,
 * a partir de outra função, um vetor
 * declarado em main(), sem que o vetor
 * original seja modificado.
 */
#include <stdio.h>
#include <stdlib.h>

/* ==============================
 * Funcoes
 * ============================== */

static int pivot(int*, int, int);
static void quicksort_auxiliar(int*, int, int);
static void swap(int*, int*);

int* copia_vetor(const int*, int);
void print_vetor(const int*, int);
void quicksort(int*, int);

/* ==============================
 * MAIN
 * ============================== */

/**
 * Funcao principal, conforme especificacao do enunciado
 *
 * Retorna int: EXIT_SUCCESS (0), para simplificacao
 */
int main(void) {
	int v[] = {1, 5, 9, 4, 2, -1, 124, 346, 100};
	int n = sizeof(v) / sizeof(int);

	int* copia = copia_vetor(v, n);
	if (copia) {
		printf("Vetor ordenado: ");
		quicksort(copia, n);
		print_vetor(copia, n);
		free(copia);
	} else {
		printf("Nao foi possivel criar a copia do vetor para ordenacao.\n");
	}

	printf("Vetor original: ");
	print_vetor(v, n);

	return EXIT_SUCCESS;
}

/* ==============================
 * Implementacoes
 * ============================== */

/**
 * Particiona um vetor para o algoritmo de ordenacao quicksort
 *
 * Parametros:
 * int* arr: ponteiro para o vetor a ser particionado
 * int low: indice inicial do vetor
 * int high: indice final do vetor
 *
 * Retorna int: indice do pivô após a partição
 */
static int pivot(int* arr, int low, int high) {
	int pivot_value = arr[high];

	int i = low - 1;
	for (int j = low; j < high; j++) {
		if (arr[j] < pivot_value) {
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);

	return i + 1;
}

/**
 * Auxiliar para algoritmo de quick sort.
 *
 * Parametros:
 * int* arr: ponteiro para o vetor a ser particionado
 * int low: indice inicial do vetor
 * int high: indice final do vetor
 */
static void quicksort_auxiliar(int* arr, int low, int high) {
	if (low < high) {
		int pi = pivot(arr, low, high);
		quicksort_auxiliar(arr, low, pi - 1);
		quicksort_auxiliar(arr, pi + 1, high);
	}
}

/**
 * Troca dois valores entre variaveis
 *
 * Parametros:
 * int* a: ponteiro para o primeiro valor
 * int* b: ponteiro para o segundo valor
 */
static void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * Copia vetor de origem para destino.
 *
 * Parametros:
 * int* source: ponteiro para o vetor de origem
 * int n: tamanho do vetor
 *
 * Retorna int*: ponteiro para o vetor de destino (dest), alocado dinamicamente
 */
int* copia_vetor(const int* source, int n) {
	if (!source || n <= 0) {
		return NULL;
	}

	int* dest = malloc(n * sizeof(int));
	if (!dest) {
		return NULL;
	}

	for (int i = 0; i < n; i++) {
		dest[i] = source[i];
	}
	return dest;
}

/**
 * Imprime vetor de tamanho n.
 *
 * Parametros:
 * int* v: ponteiro para o vetor
 * int n: tamanho do vetor
 */
void print_vetor(const int* v, int n) {
	for (int i = 0; i < n; i++) {
		printf("%d ", v[i]);
	}
	printf("\n");
}

/**
 * Ordena um vetor usando o algoritmo de quick sort.
 *
 * Parametros:
 * int* arr: ponteiro para o vetor a ser ordenado
 * int n: tamanho do vetor
 */
void quicksort(int* arr, int n) {
	if (n > 1) {
		quicksort_auxiliar(arr, 0, n - 1);
	}
}
