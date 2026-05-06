/**
 * matriz.h
 * Autor: Miguel Mochizuki Silva
 * Descricao:
 * Interface do TAD Matriz, implementado em src/matriz.c
 */
#ifndef MATRIZ_H
#define MATRIZ_H

/* Tipo exportado */
typedef struct matriz_t Matriz;

/* Funcoes exportadas */

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
 * Retorna int: 0 se matriz liberada com sucesso; -1 se ponteiro nulo
 */
int matriz_libera(Matriz* mat);

/**
 * Retorna o numero de linhas de uma matriz
 *
 * Parametros:
 * Matriz* mat: ponteiro para uma matriz
 *
 * Retorna int: numero de linhas da matriz; -1 se ponteiro nulo
 */
int matriz_linhas(Matriz* mat);

/**
 * Retorna o numero de colunas de uma matriz
 *
 * Parametros:
 * Matriz* mat: ponteiro para uma matriz
 *
 * Retorna int: numero de colunas da matriz; -1 se ponteiro nulo
 */
int matriz_colunas(Matriz* mat);

/**
 * Retorna o elemento da linha i e coluna j de uma matriz
 *
 * Parametros:
 * Matriz* mat: ponteiro para uma matriz
 * int i: indice da linha do elemento a ser acessado
 * int j: indice da coluna do elemento a ser acessado
 * double* valor: armazena o valor do elemento da linha i e coluna j da matriz
 *
 * Retorna int: 0 se elemento acessado com sucesso; -1 se ponteiro nulo; -2 se indices fora dos limites da matriz
 */
int matriz_acessa(Matriz* mat, int i, int j, double* valor);

/**
 * Atribui novo valor ao elemento da linha i e coluna j de uma matriz
 *
 * Parametros:
 * Matriz* mat: ponteiro para uma matriz
 * int i: indice da linha do elemento a ser atribuido
 * int j: indice da coluna do elemento a ser atribuido
 * double valor: valor a ser atribuido ao elemento da linha i e coluna j da matriz
 *
 * Retorna int: 0 se elemento atribuido com sucesso; -1 se ponteiro nulo; -2 se indices fora dos limites da matriz
 */
int matriz_atribui(Matriz* mat, int i, int j, double valor);

#endif
