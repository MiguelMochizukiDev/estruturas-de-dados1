/**
 * vectorlist.c
 * Autor: Miguel Mochizuki Silva
 * Descricao:
 * Implementacao do TAD VectorList, definido em include/vectorlist.h
 */
#include <stdlib.h>
#include "vectorlist.h"

/* ==============================
 * Implementacoes
 * ============================== */

/**
 * Estrutura para lista de vetores
 *
 * Atributos:
 * int* v: ponteiro para vetor alocado dinamicamente
 * int ctr: controle para quantidade atual de elementos
 * int capacity: capacidade maxima da lista
 */
struct vectorlist_t {
	int* v;
	int ctr;
	int capacity;
};

VectorList* vectorlist_cria(int capacity) {
	VectorList* list = (VectorList*)malloc(sizeof(VectorList));
	if (list == NULL) return NULL;

	list->v = (int*)malloc(sizeof(int) * capacity);
	if (list->v == NULL) {
		vectorlist_libera(list);
		return NULL;
	}

	list->ctr = -1;
	list->capacity = capacity;

	return list;
}

Status vectorlist_libera(VectorList* list) {
	if (list == NULL) {
		return STATUS_ERR_NULL;
	}

	free(list->v);
	free(list);
	return STATUS_OK;
}

Status vectorlist_size(VectorList* list, int* tamanho) {
	if (list == NULL || tamanho == NULL) {
		return STATUS_ERR_NULL;
	}

	*tamanho = list->ctr + 1;
	return STATUS_OK;
}

Status vectorlist_is_empty(VectorList* list, int* is_empty) {
	if (list == NULL || is_empty == NULL) {
		return STATUS_ERR_NULL;
	}

	int tamanho;
	if (vectorlist_size(list, &tamanho) != STATUS_OK) {
		return STATUS_ERR_NULL;
	}

	*is_empty = (tamanho == 0) ? 1 : 0;
	return STATUS_OK;
}

Status vectorlist_is_full(VectorList* list, int* is_full) {
	if (list == NULL || is_full == NULL) {
		return STATUS_ERR_NULL;
	}

	int tamanho;
	if (vectorlist_size(list, &tamanho) != STATUS_OK) {
		return STATUS_ERR_NULL;
	}

	*is_full = (tamanho >= list->capacity) ? 1 : 0;
	return STATUS_OK;
}

Status vectorlist_acessa(VectorList* list, int index, int* value) {
	if (list == NULL || value == NULL) {
		return STATUS_ERR_NULL;
	}

	int tamanho;
	if (vectorlist_size(list, &tamanho) != STATUS_OK) {
		return STATUS_ERR_NULL;
	} else if (index < 0 || index >= tamanho) {
		return STATUS_ERR_INDEX;
	}

	*value = list->v[index];
	return STATUS_OK;
}

Status vectorlist_insere_fim(VectorList* list, int value) {
	if (list == NULL) {
		return STATUS_ERR_NULL;
	}

	int is_full;
	if (vectorlist_is_full(list, &is_full) != STATUS_OK) {
		return STATUS_ERR_NULL;
	} else if (is_full) {
		return STATUS_ERR_FULL;
	}

	list->ctr++;
	list->v[list->ctr] = value;
	return STATUS_OK;
}
