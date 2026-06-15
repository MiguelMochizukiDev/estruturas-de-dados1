/**
 * fila.c
 * Autor: Miguel Mochizuki Silva
 * Descricao:
 * Implementacao do TAD Fila, conforme include/fila.h
 */
#include <stdlib.h>
#include "linked.h"
#include "fila.h"

/* ==============================
 * Implementacoes
 * ============================== */

/**
 * Estrutura interna da fila, composta por uma lista encadeada de elementos
 *
 * Atributos:
 * LinkedList* elementos: ponteiro para a lista encadeada que armazena os elementos da fila
 * LinkedList* fila: ponteiro para a lista encadeada que armazena os elementos da fila
 */
struct fila_t {
	LinkedList* elementos;
};

Fila* fila_cria(void) {
	Fila* f = malloc(sizeof(Fila));
	if (f == NULL) {
		return NULL;
	}

	f->elementos = linked_list_cria();
	if (f->elementos == NULL) {
		free(f);
		return NULL;
	}

	return f;
}

Status fila_libera(Fila* fila) {
	if (fila == NULL) {
		return STATUS_ERR_NULL;
	}

	Status s = linked_list_libera(fila->elementos);
	free(fila);
	return s;
}

Status fila_vazia(Fila* fila, int* is_empty) {
	if (fila == NULL || is_empty == NULL) {
		return STATUS_ERR_NULL;
	}

	return linked_list_vazia(fila->elementos, is_empty);
}

Status fila_enfileira(Fila* fila, int valor) {
	if (fila == NULL) {
		return STATUS_ERR_NULL;
	}

	return linked_list_insere_fim(fila->elementos, valor);
}

Status fila_desenfileira(Fila* fila, int* valor) {
	if (fila == NULL || valor == NULL) {
		return STATUS_ERR_NULL;
	}

	return linked_list_remove_inicio(fila->elementos, valor);
}
