/**
 * matriz.c
 * Autor: Miguel Mochizuki Silva
 * Descricao:
 * Implementa interface do TAD LinkedList, conforme include/linked.h
 */
#include <stdlib.h>
#include "linked.h"

/* ==============================
 * Implementacoes
 * ============================== */

/**
 * Estrutura para no da lista duplamente encadeada circular
 *
 * Atributos:
 * int value: valor do elemento
 * node_t* next: ponteiro para o proximo elemento da lista
 * node_t* prev: ponteiro para o elemento anterior da lista
 */
struct node_t {
	int value;
	struct node_t* next;
	struct node_t* prev;
};

/**
 * Estrutura para lista duplamente encadeada circular
 *
 * Atributos:
 * node_t* head: ponteiro para o primeiro elemento da lista
 * int size: numero de elementos na lista
 */
struct linked_list_t {
	struct node_t* head;
	int size;
};

LinkedList* linked_list_cria(void) {
	LinkedList* list = (LinkedList*)malloc(sizeof(LinkedList));
	if (list == NULL) return NULL;

	list->head = NULL;
	list->size = 0;

	return list;
}

Status linked_list_libera(LinkedList* list) {
	if (list == NULL) return STATUS_ERR_NULL;

	if (list->size > 0) {
		struct node_t* current = list->head;
		struct node_t* next_node;

		do {
			next_node = current->next;
			free(current);
			current = next_node;
		} while (current != list->head);
	}

	free(list);
	return STATUS_OK;
}

Status linked_list_tamanho(LinkedList* list, int* size) {
	if (list == NULL || size == NULL) return STATUS_ERR_NULL;

	*size = list->size;
	return STATUS_OK;
}

Status linked_list_vazia(LinkedList* list, int* is_empty) {
	if (list == NULL || is_empty == NULL) return STATUS_ERR_NULL;

	*is_empty = (list->size == 0) ? 1 : 0;
	return STATUS_OK;
}

Status linked_list_acessa(LinkedList* list, int index, int* value) {
	if (list == NULL || value == NULL) return STATUS_ERR_NULL;
	if (index < 0 || index >= list->size) return STATUS_ERR_INDEX;

	struct node_t* current = list->head;

	/* Otimizacao: decide se percorre do inicio ou do fim */
	if (index <= list->size / 2) {
		for (int i = 0; i < index; i++) {
			current = current->next;
		}
	} else {
		for (int i = list->size - 1; i > index; i--) {
			current = current->prev;
		}
	}

	*value = current->value;
	return STATUS_OK;
}

Status linked_list_atribui(LinkedList* list, int index, int value) {
	if (list == NULL) return STATUS_ERR_NULL;
	if (index < 0 || index >= list->size) return STATUS_ERR_INDEX;

	struct node_t* current = list->head;

	/* Otimizacao: decide se percorre do inicio ou do fim */
	if (index <= list->size / 2) {
		for (int i = 0; i < index; i++) {
			current = current->next;
		}
	} else {
		for (int i = list->size - 1; i > index; i--) {
			current = current->prev;
		}
	}

	current->value = value;
	return STATUS_OK;
}

Status linked_list_insere_inicio(LinkedList* list, int value) {
	if (list == NULL) return STATUS_ERR_NULL;

	struct node_t* new_node = (struct node_t*)malloc(sizeof(struct node_t));
	if (new_node == NULL) return STATUS_ERR_MEMORIA;

	new_node->value = value;

	if (list->size == 0) {
		/* Lista vazia: novo no aponta para si mesmo */
		new_node->next = new_node;
		new_node->prev = new_node;
		list->head = new_node;
	} else {
		struct node_t* last = list->head->prev;

		new_node->next = list->head;
		new_node->prev = last;
		list->head->prev = new_node;
		last->next = new_node;
		list->head = new_node;
	}

	list->size++;
	return STATUS_OK;
}

Status linked_list_insere_fim(LinkedList* list, int value) {
	if (list == NULL) return STATUS_ERR_NULL;

	struct node_t* new_node = (struct node_t*)malloc(sizeof(struct node_t));
	if (new_node == NULL) return STATUS_ERR_MEMORIA;

	new_node->value = value;

	if (list->size == 0) {
		/* Lista vazia: novo no aponta para si mesmo */
		new_node->next = new_node;
		new_node->prev = new_node;
		list->head = new_node;
	} else {
		struct node_t* last = list->head->prev;

		new_node->next = list->head;
		new_node->prev = last;
		list->head->prev = new_node;
		last->next = new_node;
	}

	list->size++;
	return STATUS_OK;
}

Status linked_list_insere(LinkedList* list, int index, int value) {
	if (list == NULL) return STATUS_ERR_NULL;
	if (index < 0 || index > list->size) return STATUS_ERR_INDEX;

	if (index == 0) {
		return linked_list_insere_inicio(list, value);
	} else if (index == list->size) {
		return linked_list_insere_fim(list, value);
	} else {
		struct node_t* new_node = (struct node_t*)malloc(sizeof(struct node_t));
		if (new_node == NULL) return STATUS_ERR_MEMORIA;

		new_node->value = value;

		struct node_t* current = list->head;

		/* Navega ate a posicao desejada */
		if (index <= list->size / 2) {
			for (int i = 0; i < index; i++) {
				current = current->next;
			}
		} else {
			for (int i = list->size - 1; i >= index; i--) {
				current = current->prev;
			}
		}

		struct node_t* prev_node = current->prev;

		new_node->next = current;
		new_node->prev = prev_node;
		prev_node->next = new_node;
		current->prev = new_node;

		list->size++;
		return STATUS_OK;
	}
}

Status linked_list_remove_inicio(LinkedList* list, int* value) {
	if (list == NULL) return STATUS_ERR_NULL;
	if (list->size == 0) return STATUS_ERR_INDEX;

	struct node_t* temp = list->head;

	if (value != NULL) {
		*value = temp->value;
	}

	if (list->size == 1) {
		/* Unico elemento da lista */
		list->head = NULL;
	} else {
		struct node_t* last = list->head->prev;

		list->head = temp->next;
		list->head->prev = last;
		last->next = list->head;
	}

	free(temp);
	list->size--;
	return STATUS_OK;
}

Status linked_list_remove_fim(LinkedList* list, int* value) {
	if (list == NULL) return STATUS_ERR_NULL;
	if (list->size == 0) return STATUS_ERR_INDEX;

	if (list->size == 1) {
		if (value != NULL) {
			*value = list->head->value;
		}
		free(list->head);
		list->head = NULL;
	} else {
		struct node_t* last = list->head->prev;
		struct node_t* new_last = last->prev;

		if (value != NULL) {
			*value = last->value;
		}

		new_last->next = list->head;
		list->head->prev = new_last;
		free(last);
	}

	list->size--;
	return STATUS_OK;
}

Status linked_list_remove(LinkedList* list, int index) {
	if (list == NULL) return STATUS_ERR_NULL;
	if (index < 0 || index >= list->size) return STATUS_ERR_INDEX;
	if (list->size == 0) return STATUS_ERR_INDEX;

	if (index == 0) {
		return linked_list_remove_inicio(list, NULL);
	} else if (index == list->size - 1) {
		return linked_list_remove_fim(list, NULL);
	} else {
		struct node_t* current = list->head;

		/* Navega ate a posicao desejada */
		if (index <= list->size / 2) {
			for (int i = 0; i < index; i++) {
				current = current->next;
			}
		} else {
			for (int i = list->size - 1; i > index; i--) {
				current = current->prev;
			}
		}

		struct node_t* prev_node = current->prev;
		struct node_t* next_node = current->next;

		prev_node->next = next_node;
		next_node->prev = prev_node;

		free(current);
		list->size--;
	}

	return STATUS_OK;
}
