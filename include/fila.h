/**
 * fila.h
 * Autor: Miguel Mochizuki Silva
 * Descricao:
 * Interface do TAD Fila, implementado em src/Fila.c
 */
#ifndef FILA_H
#define FILA_H

/* ==============================
 * Includes
 * ============================== */

#include "status.h"

/* ==============================
 * Tipos
 * ============================== */

typedef struct fila_t Fila;

/* ==============================
 * Funcoes
 * ============================== */

/**
 * Aloca e retorna uma fila vazia
 *
 * Retorna Fila*: fila vazia; NULL se memoria insuficiente
 */
Fila* fila_cria(void);

/**
 * Libera a memoria de uma fila previamente criada
 *
 * Parametros:
 * Fila* fila: ponteiro para uma fila
 *
 * Retorna Status: STATUS_OK se bem-sucedido; STATUS_ERR_NULL se ponteiro nulo
 */
Status fila_libera(Fila* fila);

/**
 * Verifica se a fila esta vazia
 *
 * Parametros:
 * Fila* fila: ponteiro para uma fila
 * int* resultado: ponteiro para armazenar o resultado (1 se vazia, 0 caso contrario)
 *
 * Retorna Status: STATUS_OK se bem-sucedido; STATUS_ERR_NULL se ponteiro nulo
 */
Status fila_vazia(Fila* fila, int* is_empty);

/**
 * Enfileira um elemento na fila
 *
 * Parametros:
 * Fila* fila: ponteiro para uma fila
 * int valor: valor a ser enfileirado
 *
 * Retorna Status: STATUS_OK se bem-sucedido; STATUS_ERR_NULL se ponteiro nulo; STATUS_ERR_MEMORIA se memoria insuficiente
 */
Status fila_enfileira(Fila* fila, int valor);

/**
 * Desenfileira um elemento da fila
 *
 * Parametros:
 * Fila* fila: ponteiro para uma fila
 * int* valor: ponteiro para armazenar o valor desenfileirado
 *
 * Retorna Status: STATUS_OK se bem-sucedido; STATUS_ERR_NULL se ponteiro nulo; STATUS_ERR_FULL se fila vazia
 */
Status fila_desenfileira(Fila* fila, int* valor);

#endif
