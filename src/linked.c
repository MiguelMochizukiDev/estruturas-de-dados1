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
 * Estrutura para no da lista ligada
 *
 * Atributos:
 * int value: valor do elemento
 * node_t* next: ponteiro para o proximo elemento da lista
 */
struct node_t {
	int value;
	struct node_t* next;
};

/**
 * Estrutura para lista ligada
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

	struct node_t* current = list->head;
	while (current != NULL) {
		struct node_t* temp = current;
		current = current->next;
		free(temp);
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
	for (int i = 0; i < index; i++) {
		current = current->next;
	}
	*value = current->value;
	return STATUS_OK;
}

Status linked_list_atribui(LinkedList* list, int index, int value) {
	if (list == NULL) return STATUS_ERR_NULL;
	if (index < 0 || index >= list->size) return STATUS_ERR_INDEX;

	struct node_t* current = list->head;
	for (int i = 0; i < index; i++) {
		current = current->next;
	}
	current->value = value;
	return STATUS_OK;
}

Status linked_list_insere_inicio(LinkedList* list, int value) {
	if (list == NULL) return STATUS_ERR_NULL;

	struct node_t* new_node = (struct node_t*)malloc(sizeof(struct node_t));
	if (new_node == NULL) return STATUS_ERR_MEMORIA;

	new_node->value = value;
	new_node->next = list->head;
	list->head = new_node;
	list->size++;

	return STATUS_OK;
}

Status linked_list_insere_fim(LinkedList* list, int value) {
	if (list == NULL) return STATUS_ERR_NULL;

	struct node_t* new_node = (struct node_t*)malloc(sizeof(struct node_t));
	if (new_node == NULL) return STATUS_ERR_MEMORIA;

	new_node->value = value;
	new_node->next = NULL;

	if (list->head == NULL) {
		list->head = new_node;
	} else {
		struct node_t* current = list->head;
		while (current->next != NULL) {
			current = current->next;
		}
		current->next = new_node;
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
		for (int i = 0; i < index - 1; i++) {
			current = current->next;
		}
		new_node->next = current->next;
		current->next = new_node;
		list->size++;

		return STATUS_OK;
	}
}

Status linked_list_remove_inicio(LinkedList* list, int* value) {
	if (list == NULL || value == NULL) return STATUS_ERR_NULL;
	if (list->size == 0) return STATUS_ERR_INDEX;

	struct node_t* temp = list->head;
	*value = temp->value;
	list->head = temp->next;
	free(temp);
	list->size--;

	return STATUS_OK;
}

Status linked_list_remove_fim(LinkedList* list, int* value) {
	if (list == NULL || value == NULL) return STATUS_ERR_NULL;
	if (list->size == 0) return STATUS_ERR_INDEX;

	if (list->size == 1) {
		*value = list->head->value;
		free(list->head);
		list->head = NULL;
	} else {
		struct node_t* current = list->head;
		while (current->next->next != NULL) {
			current = current->next;
		}
		*value = current->next->value;
		free(current->next);
		current->next = NULL;
	}
	list->size--;

	return STATUS_OK;
}

Status linked_list_remove(LinkedList* list, int index) {
	if (list == NULL || index < 0 || index >= list->size) return STATUS_ERR_NULL;
	if (list->size == 0) return STATUS_ERR_INDEX;

	if (index == 0) {
		return linked_list_remove_inicio(list, NULL);
	} else if (index == list->size - 1) {
		return linked_list_remove_fim(list, NULL);
	} else {
		struct node_t* current = list->head;
		for (int i = 0; i < index - 1; i++) {
			current = current->next;
		}
		struct node_t* temp = current->next;
		current->next = temp->next;
		free(temp);
		list->size--;
	}

	return STATUS_OK;
}
