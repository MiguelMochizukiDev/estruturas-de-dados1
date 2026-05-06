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
	if (mat == NULL) {
		printf("Memoria insuficiente!\n");
		exit(1);
	}

	mat->lin = m;
	mat->col = n;

	mat->dados = (double*)malloc(m * n * sizeof(double));
	if (mat->dados == NULL) {
		printf("Memoria insuficiente!\n");
		free(mat); /* Libera espaco previamente alocado para a matriz */
		exit(1);
	}

	/* Zera valores da matriz */
	for (int i = 0; i < m * n; i++) {
		mat->dados[i] = 0;
	}

	return mat;
}

void matriz_libera(Matriz* mat) {
	free(mat->dados);
	free(mat);
}

int matriz_linhas(Matriz* mat) {
	return mat->lin;
}

int matriz_colunas(Matriz* mat) {
	return mat->col;
}

double matriz_acessa(Matriz* mat, int i, int j) {
	if (i < 0 || i >= mat->lin || j < 0 || j >= mat->col) {
		printf("Indice fora dos limites da matriz!\n");
		exit(1);
	}
	return mat->dados[i * mat->col + j]; /* Acessa o elemento usando row-major indexing */
}

void matriz_atribui(Matriz* mat, int i, int j, double valor) {
	if (i < 0 || i >= mat->lin || j < 0 || j >= mat->col) {
		printf("Indice fora dos limites da matriz!\n");
		exit(1);
	}
	mat->dados[i * mat->col + j] = valor; /* Atribui o valor usando row-major indexing */
}
