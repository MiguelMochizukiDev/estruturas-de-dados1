/**
 * vectorlist.h
 * Autor: Miguel Mochizuki Silva
 * Descricao:
 * Interface do TAD VectorList, implementado em src/vectorlist.c
 */
#ifndef VECTORLIST_H
#define VECTORLIST_H

/* ==============================
 * Includes
 * ============================== */

#include "status.h"

/* ==============================
 * Tipos
 * ============================== */

typedef struct vectorlist_t VectorList;

/* ==============================
 * Funcoes
 * ============================== */

/**
 * Aloca e retorna uma lista de vetores, com capacidade especificada
 *
 * Parametros:
 * int capacity: capacidade inicial da lista
 *
 * Retorna VectorList*: lista de vetores alocada; NULL se memoria insuficiente
 */
VectorList* vectorlist_cria(int capacity);

/**
 * Libera a memoria de uma lista de vetores previamente criada
 *
 * Parametros:
 * VectorList* list: ponteiro para uma lista de vetores
 *
 * Retorna Status: STATUS_OK se bem-sucedido; STATUS_ERR_NULL se ponteiro nulo
 */
Status vectorlist_libera(VectorList* list);

/**
 * Retorna o numero de vetores atualmente armazenados na lista
 *
 * Parametros:
 * VectorList* list: ponteiro para uma lista de vetores
 * int* tamanho:
 *
 * Retorna Status: STATUS_OK se bem-sucedido; STATUS_ERR_NULL se ponteiro nulo
 */
Status vectorlist_size(VectorList* list, int* tamanho);

/**
 * Retorna se a lista de vetores esta vazia
 *
 * Parametros:
 * VectorList* list: ponteiro para uma lista de vetores
 * int* is_empty: armazena 1 se a lista esta vazia; 0 se nao esta vazia
 *
 * Retorna Status: STATUS_OK se bem-sucedido; STATUS_ERR_NULL se ponteiro nulo
 */
Status vectorlist_is_empty(VectorList* list, int* is_empty);

/**
 * Retorna se a lista de vetores esta cheia
 *
 * Parametros:
 * VectorList* list: ponteiro para uma lista de vetores
 *
 * Retorna Status: STATUS_OK se bem-sucedido; STATUS_ERR_NULL se ponteiro nulo
 */
Status vectorlist_is_full(VectorList* list, int* is_full);

/**
 * Acessa elemento de lista de vetores
 *
 * Parametros:
 * VectorList* list: ponteiro para uma lista de vetores
 * int index: indice
 * int* value: variavel para armazenar valor
 *
 * Retorna Status: STATUS_OK se bem-sucedido; STATUS_ERR_NULL se ponteiro nulo; STATUS_ERR_INDEX se indice invalido
 */
Status vectorlist_acessa(VectorList* list, int index, int* value);

/**
 * Insere elemento ao fim da lista de vetores
 *
 * Parametros:
 * VectorList* list: ponteiro para uma lista de vetores
 * int value: valor a ser inserido
 *
 * Retorna Status: STATUS_OK se bem-sucedido; STATUS_ERR_NULL se ponteiro nulo; STATUS_ERR_FULL se lista cheia
 */
Status vectorlist_insere_fim(VectorList* list, int value);

/**
 * Insere elemento ao inicio da lista de vetores
 *
 * Parametros:
 * VectorList* list: ponteiro para uma lista de vetores
 * int value: valor a ser inserido
 *
 * Retorna Status: STATUS_OK se bem-sucedido; STATUS_ERR_NULL se ponteiro nulo; STATUS_ERR_FULL se lista cheia
 */
Status vectorlist_insere_inicio(VectorList* list, int value);

#endif
