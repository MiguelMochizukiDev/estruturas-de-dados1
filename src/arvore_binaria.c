/**
 * arvore_binaria.c
 * Autor: Miguel Mochizuki Silva
 * Descricao:
 * Implementa interface do TAD ArvoreBinaria, conforme include/arvore_binaria.h
 */
#include <stdlib.h>
#include <stdio.h>
#include "arvore_binaria.h"

/* ==============================
 * Implementacoes
 * ============================== */

typedef struct no_t {
    int elemento;
    int altura;
    struct no_t *esquerda;
    struct no_t *direita;
} No;

struct arvore_binaria_t {
    No *raiz;
};

static int altura_no(No *no) {
    return no ? no->altura : 0;
}

static int maior(int a, int b) {
    return a > b ? a : b;
}

static int fator_balanceamento(No *no) {
    return altura_no(no->esquerda) - altura_no(no->direita);
}

static No* criar_no(int elemento) {
    No *no = (No*)malloc(sizeof(No));
    if (!no) return NULL;

    no->elemento = elemento;
    no->altura = 1;
    no->esquerda = NULL;
    no->direita = NULL;

    return no;
}

static void atualizar_altura(No *no) {
    no->altura = 1 + maior(altura_no(no->esquerda), altura_no(no->direita));
}

static No* rotacao_direita(No *y) {
    No *x = y->esquerda;
    No *T2 = x->direita;

    x->direita = y;
    y->esquerda = T2;

    atualizar_altura(y);
    atualizar_altura(x);

    return x;
}

static No* rotacao_esquerda(No *x) {
    No *y = x->direita;
    No *T2 = y->esquerda;

    y->esquerda = x;
    x->direita = T2;

    atualizar_altura(x);
    atualizar_altura(y);

    return y;
}

static No* balancear_no(No *no) {
    if (!no) return NULL;

    atualizar_altura(no);

    int fb = fator_balanceamento(no);

    if (fb > 1) {
        if (fator_balanceamento(no->esquerda) < 0) {
            no->esquerda = rotacao_esquerda(no->esquerda);
        }
        return rotacao_direita(no);
    }

    if (fb < -1) {
        if (fator_balanceamento(no->direita) > 0) {
            no->direita = rotacao_direita(no->direita);
        }
        return rotacao_esquerda(no);
    }

    return no;
}

static No* inserir_no(No *raiz, int elemento) {
    if (!raiz) return criar_no(elemento);

    if (elemento < raiz->elemento) {
        raiz->esquerda = inserir_no(raiz->esquerda, elemento);
    } else if (elemento > raiz->elemento) {
        raiz->direita = inserir_no(raiz->direita, elemento);
    } else {
        return raiz;
    }

    return balancear_no(raiz);
}

static No* no_minimo(No *no) {
    No *atual = no;
    while (atual && atual->esquerda) {
        atual = atual->esquerda;
    }
    return atual;
}

static No* remover_no(No *raiz, int elemento, int *encontrado) {
    if (!raiz) return NULL;

    if (elemento < raiz->elemento) {
        raiz->esquerda = remover_no(raiz->esquerda, elemento, encontrado);
    } else if (elemento > raiz->elemento) {
        raiz->direita = remover_no(raiz->direita, elemento, encontrado);
    } else {
        *encontrado = 1;

        if (!raiz->esquerda && !raiz->direita) {
            free(raiz);
            return NULL;
        }

        if (!raiz->esquerda) {
            No *temp = raiz->direita;
            free(raiz);
            return temp;
        }

        if (!raiz->direita) {
            No *temp = raiz->esquerda;
            free(raiz);
            return temp;
        }

        No *sucessor = no_minimo(raiz->direita);
        raiz->elemento = sucessor->elemento;
        raiz->direita = remover_no(raiz->direita, sucessor->elemento, encontrado);
    }

    return balancear_no(raiz);
}

static int buscar_no(No *no, int elemento) {
    if (!no) return 0;

    if (elemento < no->elemento) {
        return buscar_no(no->esquerda, elemento);
    } else if (elemento > no->elemento) {
        return buscar_no(no->direita, elemento);
    }

    return 1;
}

ArvoreBinaria* arvore_binaria_cria(void) {
	ArvoreBinaria *arvore = (ArvoreBinaria*)malloc(sizeof(ArvoreBinaria));
	if (!arvore) return NULL;

	arvore->raiz = NULL;

	return arvore;
}

static void libera_no(No *no) {
	if (!no) return;

	libera_no(no->esquerda);
	libera_no(no->direita);
	free(no);
}

Status arvore_binaria_libera(ArvoreBinaria *arvore) {
	if (!arvore) return STATUS_ERR_NULL;

	libera_no(arvore->raiz);
	free(arvore);

	return STATUS_OK;
}

Status arvore_binaria_vazia(ArvoreBinaria *arvore, int *vazia) {
	if (!arvore || !vazia) return STATUS_ERR_NULL;

	*vazia = (arvore->raiz == NULL) ? 1 : 0;

	return STATUS_OK;
}

Status arvore_binaria_altura(ArvoreBinaria *arvore, int *altura) {
	if (!arvore || !altura) return STATUS_ERR_NULL;

	*altura = altura_no(arvore->raiz);

	return STATUS_OK;
}

static int tamanho_no(No *no) {
	if (!no) return 0;

	return 1 + tamanho_no(no->esquerda) + tamanho_no(no->direita);
}

Status arvore_binaria_tamanho(ArvoreBinaria *arvore, int *tamanho) {
	if (!arvore || !tamanho) return STATUS_ERR_NULL;

	*tamanho = tamanho_no(arvore->raiz);

	return STATUS_OK;
}

Status arvore_binaria_insere(ArvoreBinaria *arvore, int elemento) {
    if (!arvore) return STATUS_ERR_NULL;

    No *nova_raiz = inserir_no(arvore->raiz, elemento);
    if (!nova_raiz) return STATUS_ERR_MEMORIA;

    arvore->raiz = nova_raiz;
    return STATUS_OK;
}

Status arvore_binaria_remove(ArvoreBinaria *arvore, int elemento) {
    if (!arvore) return STATUS_ERR_NULL;

    int encontrado = 0;
    arvore->raiz = remover_no(arvore->raiz, elemento, &encontrado);

    if (!encontrado) return STATUS_ERR_VALOR;
    return STATUS_OK;
}

Status arvore_binaria_balanca(ArvoreBinaria *arvore) {
    if (!arvore) return STATUS_ERR_NULL;

    arvore->raiz = balancear_no(arvore->raiz);
    return STATUS_OK;
}

Status arvore_binaria_busca(ArvoreBinaria *arvore, int elemento, int *encontrado) {
    if (!arvore || !encontrado) return STATUS_ERR_NULL;

    *encontrado = buscar_no(arvore->raiz, elemento);
    return STATUS_OK;
}

static void imprime_in_order(No *no) {
    if (!no) return;

    imprime_in_order(no->esquerda);
    printf("%d ", no->elemento);
    imprime_in_order(no->direita);
}

Status arvore_binaria_in_order_imprime(ArvoreBinaria *arvore) {
    if (!arvore) return STATUS_ERR_NULL;

    imprime_in_order(arvore->raiz);
    printf("\n");
    return STATUS_OK;
}

static void imprime_pre_order(No *no) {
    if (!no) return;

    printf("%d ", no->elemento);
    imprime_pre_order(no->esquerda);
    imprime_pre_order(no->direita);
}

Status arvore_binaria_pre_order_imprime(ArvoreBinaria *arvore) {
    if (!arvore) return STATUS_ERR_NULL;

    imprime_pre_order(arvore->raiz);
    printf("\n");
    return STATUS_OK;
}

static void imprime_pos_order(No *no) {
    if (!no) return;

    imprime_pos_order(no->esquerda);
    imprime_pos_order(no->direita);
    printf("%d ", no->elemento);
}

Status arvore_binaria_pos_order_imprime(ArvoreBinaria *arvore) {
    if (!arvore) return STATUS_ERR_NULL;

    imprime_pos_order(arvore->raiz);
    printf("\n");
    return STATUS_OK;
}
