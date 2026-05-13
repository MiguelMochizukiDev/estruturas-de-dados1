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
 * Estrutura para lista de vetores circular
 *
 * Atributos:
 * int* v: ponteiro para vetor alocado dinamicamente
 * int ctri: indice do primeiro elemento (inicio)
 * int ctrf: indice do ultimo elemento (fim)
 * int capacity: capacidade maxima da lista
 */
struct vectorlist_t {
	int* v;
	int ctri;
	int ctrf;
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

	/* Lista vazia: ctri == -1 e ctrf == -1 */
	list->ctri = -1;
	list->ctrf = -1;
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

	/* Lista vazia */
	if (list->ctri == -1 && list->ctrf == -1) {
		*tamanho = 0;
	}
	/* Lista nao vazia */
	else if (list->ctri <= list->ctrf) {
		*tamanho = list->ctrf - list->ctri + 1;
	}
	/* Caso circular: ctri > ctrf */
	else {
		*tamanho = (list->capacity - list->ctri) + (list->ctrf + 1);
	}

	return STATUS_OK;
}

Status vectorlist_is_empty(VectorList* list, int* is_empty) {
	if (list == NULL || is_empty == NULL) {
		return STATUS_ERR_NULL;
	}

	/* Lista vazia quando ctri == -1 e ctrf == -1 */
	*is_empty = (list->ctri == -1 && list->ctrf == -1) ? 1 : 0;
	return STATUS_OK;
}

Status vectorlist_is_full(VectorList* list, int* is_full) {
	if (list == NULL || is_full == NULL) {
		return STATUS_ERR_NULL;
	}

	/* Lista cheia quando (ctrf + 1) % capacity == ctri */
	if (list->ctri != -1 && list->ctrf != -1) {
		*is_full = ((list->ctrf + 1) % list->capacity == list->ctri) ? 1 : 0;
	} else {
		*is_full = 0;
	}

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

	/* Calcula o indice real no array circular */
	int real_index;
	if (list->ctri <= list->ctrf) {
		/* Caso linear */
		real_index = list->ctri + index;
	} else {
		/* Caso circular */
		int elementos_ate_fim = list->capacity - list->ctri;
		if (index < elementos_ate_fim) {
			real_index = list->ctri + index;
		} else {
			real_index = index - elementos_ate_fim;
		}
	}

	*value = list->v[real_index];
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

	/* Lista vazia */
	if (list->ctri == -1 && list->ctrf == -1) {
		list->ctri = 0;
		list->ctrf = 0;
		list->v[0] = value;
	}
	/* Lista nao vazia */
	else {
		/* Avanca ctrf circularmente */
		list->v[(list->ctrf + 1) % list->capacity] = value;
		list->ctrf = (list->ctrf + 1) % list->capacity;
	}

	return STATUS_OK;
}

Status vectorlist_insere_inicio(VectorList* list, int value) {
	if (list == NULL) {
		return STATUS_ERR_NULL;
	}

	int is_full;
	if (vectorlist_is_full(list, &is_full) != STATUS_OK) {
		return STATUS_ERR_NULL;
	} else if (is_full) {
		return STATUS_ERR_FULL;
	}

	/* Lista vazia */
	if (list->ctri == -1 && list->ctrf == -1) {
		list->ctri = 0;
		list->ctrf = 0;
		list->v[0] = value;
	}
	/* Lista nao vazia */
	else {
		/* Move ctri circularmente para tras */
		list->v[(list->ctri - 1 + list->capacity) % list->capacity] = value;
		list->ctri = (list->ctri - 1 + list->capacity) % list->capacity;
	}

	return STATUS_OK;
}
