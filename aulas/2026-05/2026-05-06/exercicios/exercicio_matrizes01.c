/**
 * exercicio_matrizes01.c
 * Autor: Miguel Mochizuki Silva
 * Descricao:
 * Implemente duas versoes de uma funcao, seguindo
 * as diferentes estrategias discutidas para alocar matrizes,
 * que determine se uma matriz e simetrica quadrada ou nao.
 * (Retirado de Celes, pag. 116, exercicio 4.1)
 */
#include <stdio.h>
#include <stdlib.h>

/* ==============================
 * Funcoes
 * ============================== */

int eh_simetrica_aloc_vetor_linear(int* matriz, int n, int m);
int eh_simetrica_aloc_vetor_ponteiros(int** matriz, int n, int m);

/* ==============================
 * MAIN
 * ============================== */

/**
 * Funcao principal. Testa as funcoes de verificacao de simetria de matrizes.
 *
 * Retorna int: EXIT_SUCCESS (0) se sucesso; senao EXIT_FAILURE (1).
 */
int main(void) {
	int n; /* Numero de linhas da matriz */
	int m; /* Numero de colunas da matriz */

	int* matriz_linear; /* Vamos alocar como um vetor linear */
	int** matriz_vetor_ponteiros; /* Vamos alocar como um vetor de ponteiros */

	n = 3, m = 3;
	matriz_linear = malloc(n * m * sizeof(int));
	if (!matriz_linear) {
		return EXIT_FAILURE;
	}

	matriz_vetor_ponteiros = malloc(n * sizeof(int*));
	if (!matriz_vetor_ponteiros) {
		free(matriz_linear);
		return EXIT_FAILURE;
	}
	for (int i = 0; i < n; i++) {
		matriz_vetor_ponteiros[i] = malloc(m * sizeof(int));
		if (!matriz_vetor_ponteiros[i]) {
			for (int j = 0; j < i; j++) {
				free(matriz_vetor_ponteiros[j]);
			}
			free(matriz_vetor_ponteiros);
			free(matriz_linear);
			return EXIT_FAILURE;
		}
	}

	/* Preenche a matriz com valores simetricos */
	int valor = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			matriz_linear[i * m + j] = matriz_linear[j * m + i] = valor;
			matriz_vetor_ponteiros[i][j] = matriz_vetor_ponteiros[j][i] = valor;
			valor++;
		}
	}

	if (!eh_simetrica_aloc_vetor_linear(matriz_linear, n, m)) return EXIT_FAILURE;

	if (!eh_simetrica_aloc_vetor_ponteiros(matriz_vetor_ponteiros, n, m)) return EXIT_FAILURE;

	return EXIT_SUCCESS;
}

/* ==============================
 * Implementacoes
 * ============================== */

/**
 * Verifica se a matriz alocada como vetor linear e simetrica quadrada.
 *
 * Parametros:
 * int* matriz: Ponteiro para o vetor linear que representa a matriz.
 * int n: Numero de linhas da matriz.
 * int m: Numero de colunas da matriz.
 *
 * Retorna int: 1 se a matriz for simetrica quadrada; senao 0.
 */
int eh_simetrica_aloc_vetor_linear(int* matriz, int n, int m) {
	if (n != m) {
		return 0;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (matriz[i * m + j] != matriz[j * m + i]) {
				return 0;
			}
		}
	}

	return 1;
}

/**
 * Verifica se a matriz alocada como vetor de ponteiros e simetrica quadrada.
 *
 * Parametros:
 * int** matriz: Ponteiro para o vetor de ponteiros que representa a matriz.
 * int n: Numero de linhas da matriz.
 * int m: Numero de colunas da matriz.
 */
int eh_simetrica_aloc_vetor_ponteiros(int** matriz, int n, int m) {
	if (n != m) {
		return 0;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (matriz[i][j] != matriz[j][i]) {
				return 0;
			}
		}
	}

	return 1;
}
