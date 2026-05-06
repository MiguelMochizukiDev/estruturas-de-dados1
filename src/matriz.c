/**
 * matriz.c
 * Autor: Miguel Mochizuki Silva
 * Descricao:
 * Implementa interface do TAD Matriz, conforme include/matriz.h
 */
#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"

/* ==============================
 * Implementacoes
 * ============================== */

/**
 * Estrutura para matriz
 *
 * Atributos:
 * int lin: numero de linhas da matriz
 * int col: numero de colunas da matriz
 * double* dados: ponteiro para os dados da matriz, armazenados em formato de vetor
 */
struct matriz_t {
    int lin;
    int col;
    double* dados; /* Implementamos como vetor unidimensional alocado dinamicamente */
};

Matriz* matriz_cria(int m, int n) {
	Matriz* mat = (Matriz*)malloc(sizeof(Matriz));
	if (mat == NULL) return NULL;

	mat->lin = m;
	mat->col = n;

	mat->dados = (double*)calloc(m * n, sizeof(double));
	if (mat->dados == NULL) {
		matriz_libera(mat);
		return NULL;
	}

	return mat;
}

int matriz_libera(Matriz* mat) {
	if (mat == NULL) return -1;
	free(mat->dados);
	free(mat);
	return 0;
}

int matriz_linhas(Matriz* mat) {
	if (mat == NULL) return -1;
	return mat->lin;
}

int matriz_colunas(Matriz* mat) {
	if (mat == NULL) return -1;
	return mat->col;
}

int matriz_acessa(Matriz* mat, int i, int j, double* valor) {
	if (mat == NULL || valor == NULL) return -1;
	if (i < 0 || i >= mat->lin || j < 0 || j >= mat->col) return -2;
	*valor = mat->dados[i * mat->col + j];
	return 0;
}

int matriz_atribui(Matriz* mat, int i, int j, double valor) {
	if (mat == NULL) return -1;
	if (i < 0 || i >= mat->lin || j < 0 || j >= mat->col) return -2;
	mat->dados[i * mat->col + j] = valor;
	return 0;
}
