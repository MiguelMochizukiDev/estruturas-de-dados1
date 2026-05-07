/**
 * matriz.h
 * Autor: Miguel Mochizuki Silva
 * Descricao:
 * Interface do TAD Matriz, implementado em src/matriz.c
 */
#ifndef MATRIZ_H
#define MATRIZ_H

/* ==============================
 * Includes
 * ============================== */

#include "status.h"

/* ==============================
 * Tipos
 * ============================== */

typedef struct matriz_t Matriz;

/* ==============================
 * Funcoes
 * ============================== */

/**
 * Aloca e retorna uma matriz de m linhas e n colunas, inicialmente preenchida com zeros
 *
 * Parametros:
 * int m: numero de linhas da matriz
 * int n: numero de colunas da matriz
 *
 * Retorna Matriz*: matriz de m linhas e n colunas; NULL se memoria insuficiente
 */
Matriz* matriz_cria(int m, int n);

/**
 * Libera a memoria de uma matriz previamente criada
 *
 * Parametros:
 * Matriz* mat: ponteiro para uma matriz
 *
 * Retorna Status: STATUS_OK se bem-sucedido; STATUS_ERR_NULL se ponteiro nulo
 */
Status matriz_libera(Matriz* mat);

/**
 * Retorna o numero de linhas de uma matriz
 *
 * Parametros:
 * Matriz* mat: ponteiro para uma matriz
 * int* linhas: armazena o numero de linhas da matriz
 *
 * Retorna Status: STATUS_OK se bem-sucedido; STATUS_ERR_NULL se algum ponteiro nulo
 */
Status matriz_linhas(Matriz* mat, int* linhas);

/**
 * Retorna o numero de colunas de uma matriz
 *
 * Parametros:
 * Matriz* mat: ponteiro para uma matriz
 * int* colunas: armazena o numero de colunas da matriz
 *
 * Retorna Status: STATUS_OK se bem-sucedido; STATUS_ERR_NULL se algum ponteiro nulo
 */
Status matriz_colunas(Matriz* mat, int* colunas);

/**
 * Retorna o elemento da linha i e coluna j de uma matriz
 *
 * Parametros:
 * Matriz* mat: ponteiro para uma matriz
 * int i: indice da linha do elemento a ser acessado
 * int j: indice da coluna do elemento a ser acessado
 * double* valor: armazena o valor do elemento da linha i e coluna j da matriz
 *
 * Retorna Status: STATUS_OK se bem-sucedido; STATUS_ERR_NULL se algum ponteiro nulo; STATUS_ERR_INDEX se indices fora dos limites
 */
Status matriz_acessa(Matriz* mat, int i, int j, double* valor);

/**
 * Atribui novo valor ao elemento da linha i e coluna j de uma matriz
 *
 * Parametros:
 * Matriz* mat: ponteiro para uma matriz
 * int i: indice da linha do elemento a ser atribuido
 * int j: indice da coluna do elemento a ser atribuido
 * double valor: valor a ser atribuido ao elemento da linha i e coluna j da matriz
 *
 * Retorna Status: STATUS_OK se bem-sucedido; STATUS_ERR_NULL se ponteiro nulo; STATUS_ERR_INDEX se indices fora dos limites
 */
Status matriz_atribui(Matriz* mat, int i, int j, double valor);

#endif
