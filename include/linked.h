/**
 * linked.h
 * Autor: Miguel Mochizuki Silva
 * Descricao:
 * Interface do TAD LinkedList, implementado em src/linked.c
 */
#ifndef LINKED_H
#define LINKED_H

/* ==============================
 * Includes
 * ============================== */

#include "status.h"

/* ==============================
 * Tipos
 * ============================== */

typedef struct linked_list_t LinkedList;

/* ==============================
 * Funcoes
 * ============================== */

/**
 * Aloca e retorna uma lista ligada vazia
 *
 * Retorna LinkedList*: lista ligada vazia; NULL se memoria insuficiente
 */
LinkedList* linked_list_cria(void);

/**
 * Libera a memoria de uma lista ligada previamente criada
 *
 * Parametros:
 * LinkedList* list: ponteiro para uma lista ligada
 *
 * Retorna Status: STATUS_OK se bem-sucedido; STATUS_ERR_NULL se ponteiro nulo
 */
Status linked_list_libera(LinkedList *list);

/**
 * Retorna o numero de elementos na lista ligada
 *
 * Parametros:
 * LinkedList* list: ponteiro para uma lista ligada
 * int* size: armazena o numero de elementos na lista
 *
 * Retorna Status: STATUS_OK se bem-sucedido; STATUS_ERR_NULL se ponteiro nulo
 */
Status linked_list_tamanho(LinkedList* list, int* size);

/**
 * Verifica se a lista ligada esta vazia
 *
 * Parametros:
 * LinkedList* list: ponteiro para uma lista ligada
 * int* is_empty: armazena 1 se a lista estiver vazia, 0 caso contrario
 *
 * Retorna Status: STATUS_OK se bem-sucedido; STATUS_ERR_NULL se ponteiro nulo
 */
Status linked_list_vazia(LinkedList* list, int* is_empty);

/**
 * Acessa o elemento na posicao index da lista ligada
 *
 * Parametros:
 * LinkedList* list: ponteiro para uma lista ligada
 * int index: indice do elemento a ser acessado (0-based)
 * int* value: armazena o valor do elemento na posicao index
 *
 * Retorna Status: STATUS_OK se bem-sucedido; STATUS_ERR_NULL se ponteiro nulo; STATUS_ERR_INDEX se indice invalido
 */
Status linked_list_acessa(LinkedList* list, int index, int* value);

/**
 * Atribui um valor a posicao index da lista ligada
 *
 * Parametros:
 * LinkedList* list: ponteiro para uma lista ligada
 * int index: indice do elemento a ser modificado (0-based)
 * int value: novo valor a ser atribuido
 *
 * Retorna Status: STATUS_OK se bem-sucedido; STATUS_ERR_NULL se ponteiro nulo; STATUS_ERR_INDEX se indice invalido
 */
Status linked_list_atribui(LinkedList* list, int index, int value);

/**
 * Insere um elemento com valor value no inicio da lista ligada
 *
 * Parametros:
 * LinkedList* list: ponteiro para uma lista ligada
 * int value: valor do novo elemento a ser inserido
 *
 * Retorna Status: STATUS_OK se bem-sucedido; STATUS_ERR_NULL se ponteiro nulo
 */
Status linked_list_insere_inicio(LinkedList* list, int value);

/**
 * Insere um elemento com valor value no final da lista ligada
 *
 * Parametros:
 * LinkedList* list: ponteiro para uma lista ligada
 * int value: valor do novo elemento a ser inserido
 *
 * Retorna Status: STATUS_OK se bem-sucedido; STATUS_ERR_NULL se ponteiro nulo
 */
Status linked_list_insere_fim(LinkedList* list, int value);

/**
 * Insere um elemento com valor value na posicao index da lista ligada
 *
 * Parametros:
 * LinkedList* list: ponteiro para uma lista ligada
 * int index: indice onde o novo elemento sera inserido (0-based)
 * int value: valor do novo elemento a ser inserido
 *
 * Retorna Status: STATUS_OK se bem-sucedido; STATUS_ERR_NULL se ponteiro nulo; STATUS_ERR_INDEX se indice invalido
 */
Status linked_list_insere(LinkedList* list, int index, int value);

/**
 * Remove o elemento no inicio da lista ligada
 *
 * Parametros:
 * LinkedList* list: ponteiro para uma lista ligada
 * int* value: armazena o valor do elemento removido
 *
 * Retorna Status: STATUS_OK se bem-sucedido; STATUS_ERR_NULL se ponteiro nulo; STATUS_ERR_INDEX se lista vazia
 */
Status linked_list_remove_inicio(LinkedList* list, int* value);

/**
 * Remove o elemento no final da lista ligada
 *
 * Parametros:
 * LinkedList* list: ponteiro para uma lista ligada
 * int* value: armazena o valor do elemento removido
 *
 * Retorna Status: STATUS_OK se bem-sucedido; STATUS_ERR_NULL se ponteiro nulo; STATUS_ERR_INDEX se lista vazia
 */
Status linked_list_remove_fim(LinkedList* list, int* value);

/**
 * Remove o elemento na posicao index da lista ligada
 *
 * Parametros:
 * LinkedList* list: ponteiro para uma lista ligada
 * int index: indice do elemento a ser removido (0-based)
 *
 * Retorna Status: STATUS_OK se bem-sucedido; STATUS_ERR_NULL se ponteiro nulo; STATUS_ERR_INDEX se indice invalido
 */
Status linked_list_remove(LinkedList* list, int index);

#endif
