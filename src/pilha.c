/**
 * pilha.c
 * Autor: Miguel Mochizuki Silva
 * Descricao:
 * Implementacao do TAD Matriz, conforme src/matriz.c
 */
#include <stdlib.h>
#include "linked.h"
#include "pilha.h"

/* ==============================
 * Implementacoes
 * ============================== */

/**
 * Estrutura interna da pilha, composta por uma lista encadeada de elementos
 *
 * Atributos:
 * LinkedList* elementos: ponteiro para a lista encadeada que armazena os elementos da pilha
 */
struct pilha_t {
	LinkedList* elementos;
};

Pilha* pilha_cria(void) {
	Pilha* p = malloc(sizeof(Pilha));
	if (p == NULL) {
		return NULL;
	}

	p->elementos = linked_list_cria();
	if (p->elementos == NULL) {
		free(p);
		return NULL;
	}

	return p;
}

Status pilha_libera(Pilha* pilha) {
	if (pilha == NULL) {
		return STATUS_ERR_NULL;
	}

	Status s = linked_list_libera(pilha->elementos);
	free(pilha);
	return s;
}

Status pilha_push(Pilha* pilha, int valor) {
	if (pilha == NULL) {
		return STATUS_ERR_NULL;
	}

	return linked_list_insere_inicio(pilha->elementos, valor);
}

Status pilha_pop(Pilha* pilha, int* valor) {
	if (pilha == NULL || valor == NULL) {
		return STATUS_ERR_NULL;
	}

	return linked_list_remove_inicio(pilha->elementos, valor);
}

Status pilha_top(Pilha* pilha, int* valor) {
	if (pilha == NULL || valor == NULL) {
		return STATUS_ERR_NULL;
	}

	int val;
	int status = linked_list_acessa(pilha->elementos, 0, &val);

	if (status = STATUS_OK) {
		*valor = val;
	}

	return status;
}
