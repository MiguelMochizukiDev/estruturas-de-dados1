/**
 * exercicio_hanoi.c
 * Autor: Miguel Mochizuki Silva
 * Descrição:
 * Implementar algoritmo de resolução da torre de Hanoi
 * por meio de pilhas dinâmicas com lista duplamente encadeada circular
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* ==============================
 * Estruturas de dados
 * ============================== */

struct no_t {
	char data;
	struct no_t* prox;
	struct no_t* ant;
};
typedef struct no_t No;

struct pilha_t {
	char* nome;
	No* topo;
};
typedef struct pilha_t Pilha;

struct hanoi_contexto_t {
	Pilha* origem;
	Pilha* destino;
	Pilha* auxiliar;
};
typedef struct hanoi_contexto_t HanoiContexto;

/* ==============================
 * Protótipos de funções
 * ============================== */

Pilha* pilha_criar(const char* nome);
void pilha_imprimir(Pilha* p);
int pilha_esta_vazia(Pilha* p);
int pilha_empilhar(Pilha* p, char data);
int pilha_desempilhar(Pilha* p, char* data);
void pilha_liberar(Pilha* p);
void hanoi(int n, Pilha* origem, Pilha* destino, Pilha* auxiliar, HanoiContexto* ctx);
void imprimir_estado(HanoiContexto* ctx, const char* mensagem);

/* ==============================
 * MAIN
 * ============================== */

int main(void) {
	Pilha* origem = pilha_criar("Origem");
	Pilha* destino = pilha_criar("Destino");
	Pilha* auxiliar = pilha_criar("Auxiliar");

	pilha_empilhar(origem, '3');
	pilha_empilhar(origem, '2');
	pilha_empilhar(origem, '1');

	HanoiContexto ctx = {origem, destino, auxiliar};

	imprimir_estado(&ctx, "Estado inicial:");

	hanoi(3, origem, destino, auxiliar, &ctx);

	pilha_liberar(origem);
	pilha_liberar(destino);
	pilha_liberar(auxiliar);

	return 0;
}

/* ==============================
 * Implementações
 * ============================== */

/**
 * Tenta alocar espaço para uma pilha, inicializando-a vazia
 *
 * Parâmetros:
 * const char* nome: nome da pilha
 *
 * Retorna Pilha*: ponteiro para o endereço de memória alocado para a pilha,
 * ou NULL se houve falha na alocação
 */
Pilha* pilha_criar(const char* nome) {
	Pilha* p = (Pilha*)malloc(sizeof(Pilha));
	if (p == NULL) {
		return NULL;
	}
	size_t len = strlen(nome) + 1;
	p->nome = (char*)malloc(len);
	if (p->nome == NULL) {
		free(p);
		return NULL;
	}
	memcpy(p->nome, nome, len);
	p->topo = NULL;
	return p;
}

/**
 * Imprime os elementos da pilha da base para o topo
 *
 * Parâmetros:
 * Pilha* p: ponteiro para a pilha a ser impressa
 *
 * Retorna void
 */
void pilha_imprimir(Pilha* p) {
	if (!p) return;

	printf("\t");

	if (pilha_esta_vazia(p)) {
		printf(" Pilha vazia\n");
		return;
	}
	No* atual = p->topo->ant;
	while (atual != p->topo) {
		printf(" %c ", atual->data);
		atual = atual->ant;
	}
	printf(" %c ", p->topo->data);
	printf("\n");
}

/**
 * Retorna se a pilha é ou não vazia
 *
 * Parâmetros:
 * Pilha* p: ponteiro para a pilha
 *
 * Retorna int: -1 se o ponteiro é NULL, 0 se contém elementos, 1 se vazia
 */
int pilha_esta_vazia(Pilha* p) {
	if (!p) return -1;
	return (!p->topo) ? 1 : 0;
}

/**
 * Empilha um dado (insere no topo)
 *
 * Parâmetro:
 * Pilha* p: ponteiro para a pilha
 * char data: o dado a ser empilhado
 *
 * Retorna int: -1 se o ponteiro é NULL, 0 se sucesso, 1 se falha na alocação
 */
int pilha_empilhar(Pilha* p, char data) {
	if (!p) return -1;
	No* n = (No*)malloc(sizeof(No));
	if (!n) return 1;
	n->data = data;
	if (pilha_esta_vazia(p) == 1) {
		n->prox = n;
		n->ant = n;
	} else {
		n->prox = p->topo;
		n->ant = p->topo->ant;
		p->topo->ant->prox = n;
		p->topo->ant = n;
	}
	p->topo = n;
	return 0;
}

/**
 * Desempilha um dado (remove do topo)
 *
 * Parâmetro:
 * Pilha* p: ponteiro para a pilha
 * char* data: ponteiro para o local onde o dado desempilhado será armazenado
 *
 * Retorna int: -1 se o ponteiro é NULL, 0 se sucesso, 1 se pilha vazia
 */
int pilha_desempilhar(Pilha* p, char* data) {
	if (!p) return -1;
	if (pilha_esta_vazia(p) == 1) return 1;
	No* sai = p->topo;
	*data = sai->data;
	if (sai->prox == sai) {
		p->topo = NULL;
	} else {
		sai->ant->prox = sai->prox;
		sai->prox->ant = sai->ant;
		p->topo = sai->prox;
	}
	free(sai);
	return 0;
}

/**
 * Obtém o topo da pilha sem o desempilhar
 *
 * Parametros:
 * Pilha* p: ponteiro para a pilha
 * char* data: ponteiro para o local onde o dado do topo será armazenado
 *
 * Retorna int: -1 se o ponteiro é NULL, 0 se sucesso, 1 se pilha vazia
 */
int pilha_topo(Pilha* p, char* data) {
	if (!p) return -1;
	if (pilha_esta_vazia(p) == 1) return 1;
	*data = p->topo->data;
	return 0;
}

/**
 * Libera toda a memória alocada para a pilha
 *
 * Parâmetros:
 * Pilha* p: ponteiro para a pilha
 *
 * Retorna void
 */
void pilha_liberar(Pilha* p) {
	if (!p) return;
	char temp;
	while (pilha_esta_vazia(p) != 1) {
		pilha_desempilhar(p, &temp);
	}
	free(p->nome);
	free(p);
}

/**
 * Imprime o estado atual das três pilhas de forma organizada
 *
 * Parâmetros:
 * HanoiContexto* ctx: contexto contendo referências às três pilhas
 * const char* mensagem: mensagem opcional a ser exibida antes do estado
 *
 * Retorna void
 */
void imprimir_estado(HanoiContexto* ctx, const char* mensagem) {
	if (mensagem) {
		printf("%s\n", mensagem);
	}
	printf("%s:  ", ctx->origem->nome);
	pilha_imprimir(ctx->origem);
	printf("%s: ", ctx->destino->nome);
	pilha_imprimir(ctx->destino);
	printf("%s:", ctx->auxiliar->nome);
	pilha_imprimir(ctx->auxiliar);
	printf("\n");
}

/**
 * Implementa recursivamente a solução do problema da torre de Hanoi,
 * imprimindo os estados das pilhas ao longo do processo. Solução recursiva.
 *
 * Parâmetros:
 * int n: tamanho das pilhas
 * Pilha* origem: pilha de origem
 * Pilha* destino: pilha de destino
 * Pilha* auxiliar: pilha auxiliar
 * HanoiContexto* ctx: contexto contendo referências permanentes às pilhas originais
 *
 * Retorna void
 */
void hanoi(int n, Pilha* origem, Pilha* destino, Pilha* auxiliar, HanoiContexto* ctx) {
	if (n == 1) {
		char data;
		pilha_desempilhar(origem, &data);
		pilha_empilhar(destino, data);
		char mensagem[100];
		snprintf(mensagem, sizeof(mensagem),
			"Movendo disco %c de %s para %s",
			data, origem->nome, destino->nome);
		imprimir_estado(ctx, mensagem);
		return;
	}

	hanoi(n - 1, origem, auxiliar, destino, ctx);

	char data;
	pilha_desempilhar(origem, &data);
	pilha_empilhar(destino, data);
	char mensagem[100];
	snprintf(mensagem, sizeof(mensagem),
		"Movendo disco %c de %s para %s",
		data, origem->nome, destino->nome);
	imprimir_estado(ctx, mensagem);

	hanoi(n - 1, auxiliar, destino, origem, ctx);
}
