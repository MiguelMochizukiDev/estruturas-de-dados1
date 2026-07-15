/**
 * arvore_binaria.h
 * Autor: Miguel Mochizuki Silva
 * Descricao:
 * Interface do TAD ArvoreBinaria, implementado em src/arvore_binaria.c
 */
#ifndef ARVORE_BINARIA_H
#define ARVORE_BINARIA_H

/* ==============================
 * Includes
 * ============================== */

#include "status.h"

/* ==============================
 * Tipos
 * ============================== */

typedef struct arvore_binaria_t ArvoreBinaria;

/* ==============================
 * Funcoes
 * ============================== */

/**
 * Aloca e retorna uma arvore binaria vazia
 *
 * Retorna ArvoreBinaria*: arvore binaria vazia; NULL se memoria insuficiente
 */
ArvoreBinaria* arvore_binaria_cria(void);

/**
 * Libera a memoria de uma arvore binaria previamente criada
 *
 * Parametros:
 * ArvoreBinaria* arvore: ponteiro para a arvore binaria
 *
 * Retorna Status: STATUS_OK se bem-sucedido; STATUS_ERR_NULL se ponteiro nulo
 */
Status arvore_binaria_libera(ArvoreBinaria *arvore);

/**
 * Verifica se a arvore binaria esta vazia
 *
 * Parametros:
 * ArvoreBinaria* arvore: ponteiro para a arvore binaria
 * int* vazia: ponteiro para armazenar o resultado (1 se vazia, 0 se nao vazia)
 *
 * Retorna Status: STATUS_OK se bem-sucedido; STATUS_ERR_NULL se ponteiro nulo
 */
Status arvore_binaria_vazia(ArvoreBinaria *arvore, int *vazia);

/**
 * Retorna a altura da arvore binaria
 *
 * Parametros:
 * ArvoreBinaria* arvore: ponteiro para a arvore binaria
 * int* altura: ponteiro para armazenar a altura da arvore
 *
 * Retorna Status: STATUS_OK se bem-sucedido; STATUS_ERR_NULL se ponteiro nulo
 */
Status arvore_binaria_altura(ArvoreBinaria *arvore, int *altura);

/**
 * Retorna o tamanho (numero de elementos) da arvore binaria
 *
 * Parametros:
 * ArvoreBinaria* arvore: ponteiro para a arvore binaria
 * int* tamanho: ponteiro para armazenar o tamanho da arvore
 *
 * Retorna Status: STATUS_OK se bem-sucedido; STATUS_ERR_NULL se ponteiro nulo
 */
Status arvore_binaria_tamanho(ArvoreBinaria *arvore, int *tamanho);

/**
 * Insere um elemento na arvore binaria
 *
 * Parametros:
 * ArvoreBinaria* arvore: ponteiro para a arvore binaria
 * int elemento: elemento a ser inserido
 *
 * Retorna Status: STATUS_OK se bem-sucedido; STATUS_ERR_NULL se ponteiro nulo;
 *                 STATUS_ERR_MEM se memoria insuficiente
 */
Status arvore_binaria_insere(ArvoreBinaria *arvore, int elemento);

/**
 * Remove um elemento da arvore binaria
 *
 * Parametros:
 * ArvoreBinaria* arvore: ponteiro para a arvore binaria
 * int elemento: elemento a ser removido
 *
 * Retorna Status: STATUS_OK se bem-sucedido; STATUS_ERR_NULL se ponteiro nulo;
 *                 STATUS_ERR_VALOR se elemento nao encontrado
 */
Status arvore_binaria_remove(ArvoreBinaria *arvore, int elemento);

/**
 * Balanca a arvore binaria usando o algoritmo de balanceamento AVL
 *
 * Parametros:
 * ArvoreBinaria* arvore: ponteiro para a arvore binaria
 *
 * Retorna Status: STATUS_OK se bem-sucedido; STATUS_ERR_NULL se ponteiro nulo
 */
Status arvore_binaria_balanca(ArvoreBinaria *arvore);

/**
 * Verifica se um elemento esta presente na arvore binaria
 *
 * Parametros:
 * ArvoreBinaria* arvore: ponteiro para a arvore binaria
 * int elemento: elemento a ser verificado
 * int* encontrado: ponteiro para armazenar o resultado (1 se encontrado, 0 se nao)
 *
 * Retorna Status: STATUS_OK se bem-sucedido; STATUS_ERR_NULL se ponteiro nulo
 */
Status arvore_binaria_busca(ArvoreBinaria *arvore, int elemento, int *encontrado);

/**
 * Percorre e imprime a arvore binaria em ordem (in-order traversal)
 * Visita: filho esquerdo -> no atual -> filho direito
 *
 * Parametros:
 * ArvoreBinaria* arvore: ponteiro para a arvore binaria
 *
 * Retorna Status: STATUS_OK se bem-sucedido; STATUS_ERR_NULL se ponteiro nulo
 */
Status arvore_binaria_in_order_imprime(ArvoreBinaria *arvore);

/**
 * Percorre e imprime a arvore binaria em pre-ordem (pre-order traversal)
 * Visita: no atual -> filho esquerdo -> filho direito
 *
 * Parametros:
 * ArvoreBinaria* arvore: ponteiro para a arvore binaria
 *
 * Retorna Status: STATUS_OK se bem-sucedido; STATUS_ERR_NULL se ponteiro nulo
 */
Status arvore_binaria_pre_order_imprime(ArvoreBinaria *arvore);

/**
 * Percorre e imprime a arvore binaria em pos-ordem (post-order traversal)
 * Visita: filho esquerdo -> filho direito -> no atual
 *
 * Parametros:
 * ArvoreBinaria* arvore: ponteiro para a arvore binaria
 *
 * Retorna Status: STATUS_OK se bem-sucedido; STATUS_ERR_NULL se ponteiro nulo
 */
Status arvore_binaria_pos_order_imprime(ArvoreBinaria *arvore);

#endif
