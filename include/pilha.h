/**
 * pilha.h
 * Autor: Miguel Mochizuki Silva
 * Descricao:
 * Interface do TAD Pilha, implementado em src/pilha.c
 */
#ifndef PILHA_H
#define PILHA_H

/* ==============================
 * Includes
 * ============================== */

#include "status.h"

/* ==============================
 * Tipos
 * ============================== */

typedef struct pilha_t Pilha;

/* ==============================
 * Funcoes
 * ============================== */

/**
 * Aloca e retorna uma pilha vazia
 *
 * Retorna Pilha*: pilha vazia; NULL se memoria insuficiente
 */
Pilha* pilha_cria(void);

/**
 * Libera a memoria de uma pilha previamente criada
 *
 * Parametros:
 * Pilha* pilha: ponteiro para uma pilha
 *
 * Retorna Status: STATUS_OK se bem-sucedido; STATUS_ERR_NULL se ponteiro nulo
 */
Status pilha_libera(Pilha* pilha);

/**
 * Verifica se a pilha esta vazia
 *
 * Parametros:
 * Pilha* pilha: ponteiro para uma pilha
 * int* resultado: ponteiro para armazenar o resultado (1 se vazia, 0 caso contrario)
 *
 * Retorna Status: STATUS_OK se bem-sucedido; STATUS_ERR_NULL se ponteiro nulo
 */
Status pilha_esta_vazia(Pilha* pilha, int* resultado);

/**
 * Insere um elemento no topo da pilha
 *
 * Parametros:
 * Pilha* pilha: ponteiro para uma pilha
 * int valor: valor a ser inserido
 *
 * Retorna Status: STATUS_OK se bem-sucedido; STATUS_ERR_NULL se ponteiro nulo; STATUS_ERR_MEMORIA se memoria insuficiente
 */
Status pilha_push(Pilha* pilha, int valor);

/**
 * Remove o elemento do topo da pilha e armazena seu valor
 *
 * Parametros:
 * Pilha* pilha: ponteiro para uma pilha
 * int* valor: armazena o valor do elemento removido
 *
 * Retorna Status: STATUS_OK se bem-sucedido; STATUS_ERR_NULL se algum ponteiro nulo; STATUS_ERR_ESTADO se pilha vazia
 */
Status pilha_pop(Pilha* pilha, int* valor);

/**
 * Retorna o valor do elemento no topo da pilha sem removê-lo
 *
 * Parametros:
 * Pilha* pilha: ponteiro para uma pilha
 * int* valor: armazena o valor do elemento no topo
 *
 * Retorna Status: STATUS_OK se bem-sucedido; STATUS_ERR_NULL se algum ponteiro nulo; STATUS_ERR_ESTADO se pilha vazia
 */
Status pilha_top(Pilha* pilha, int* valor);

#endif
