/**
 * matriz.c
 * Autor: Miguel Mochizuki Silva
 * Descricao:
 * Implementa interface do TAD Matriz, conforme include/matriz.h
 */
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

Status matriz_libera(Matriz* mat) {
	if (mat == NULL) return STATUS_ERR_NULL;

	free(mat->dados);
	free(mat);
	return STATUS_OK;
}

Status matriz_linhas(Matriz* mat, int* linhas) {
	if (mat == NULL || linhas == NULL) return STATUS_ERR_NULL;
	*linhas = mat->lin;
	return STATUS_OK;
}

Status matriz_colunas(Matriz* mat, int* colunas) {
	if (mat == NULL || colunas == NULL) return STATUS_ERR_NULL;
	*colunas = mat->col;
	return STATUS_OK;
}

Status matriz_acessa(Matriz* mat, int i, int j, double* valor) {
	if (mat == NULL || valor == NULL) return STATUS_ERR_NULL;
	if (i < 0 || i >= mat->lin || j < 0 || j >= mat->col) return STATUS_ERR_INDEX;
	*valor = mat->dados[i * mat->col + j];
	return STATUS_OK;
}

Status matriz_atribui(Matriz* mat, int i, int j, double valor) {
	if (mat == NULL) return STATUS_ERR_NULL;
	if (i < 0 || i >= mat->lin || j < 0 || j >= mat->col) return STATUS_ERR_INDEX;
	mat->dados[i * mat->col + j] = valor;
	return STATUS_OK;
}
