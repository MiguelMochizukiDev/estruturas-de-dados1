/**
 * exercicio_bfs_dfs.c
 * Autor: Miguel Mochizuki Silva
 * Descrição: implementa TAD grafo e os algoritmos BFS e DFS
 */
#include <stdio.h>
#include <stdlib.h>

/* ==============================
 * Tipos
 * ============================== */

typedef struct no_t {
	int valor;
	struct no_t* proximo;
} No;

typedef struct lista_t {
	No* primeiro;
} Lista;

typedef struct vertice_t {
	int valor;
	Lista adjacentes;
} Vertice;

typedef struct grafo_t {
	int num_elementos;
	Vertice* vertices;
} Grafo;

/* ==============================
 * Protótipos de funções
 * ============================== */

Grafo* grafo_cria(int n);
void grafo_adicionar_aresta(Grafo* g, int origem, int destino);
void grafo_liberar(Grafo* g);

void BFS(Grafo* g, int origem);

static void DFS_recursivo(Grafo* g, int vertice, int* visitado);
void DFS(Grafo* g, int origem);

/* ==============================
 * MAIN
 * ============================== */

int main(void) {
	Grafo* g = grafo_cria(8);

	grafo_adicionar_aresta(g, 0, 1);
	grafo_adicionar_aresta(g, 0, 2);
	grafo_adicionar_aresta(g, 0, 3);
	grafo_adicionar_aresta(g, 1, 2);
	grafo_adicionar_aresta(g, 1, 4);
	grafo_adicionar_aresta(g, 2, 3);
	grafo_adicionar_aresta(g, 2, 5);
	grafo_adicionar_aresta(g, 3, 6);
	grafo_adicionar_aresta(g, 4, 5);
	grafo_adicionar_aresta(g, 4, 7);
	grafo_adicionar_aresta(g, 5, 6);
	grafo_adicionar_aresta(g, 5, 7);
	grafo_adicionar_aresta(g, 6, 7);

	BFS(g, 0);
	DFS(g, 0);

	grafo_liberar(g);

	return 0;
}

/* ==============================
 * Implementações
 * ============================== */


/**
 * Inicializa um grafo de n vértices
 *
 * Parametros:
 * int n: o numero de vertices
 *
 * Retorna Grafo*: um ponteiro para o grafo criado
 */
Grafo* grafo_cria(int n) {
	Grafo* g = (Grafo*)malloc(sizeof(Grafo));
	if (!g) return NULL;


	g->num_elementos = n;
	g->vertices = (Vertice*)malloc(n * sizeof(Vertice));
	if (!g->vertices) {
		free(g);
		return NULL;
	}

	for (int i = 0; i < n; i++) {
		g->vertices[i].valor = i;
		g->vertices[i].adjacentes.primeiro = NULL;
	}

	return g;
}

/**
 * Adiciona aresta dirigida entre dois vertices
 *
 * Parametros:
 * Grafo* g: ponteiro para o grafo
 * int origem: indice do vertice de origem
 * int destino: indice do vertice de destino
 */
void grafo_adicionar_aresta(Grafo* g, int origem, int destino) {
	if (!g || origem < 0 || origem >= g->num_elementos ||
			destino < 0 || destino >= g->num_elementos) {
		return;
	}

	No* novo = (No*)malloc(sizeof(No));
	if (!novo) return;

	novo->valor = destino;
	novo->proximo = g->vertices[origem].adjacentes.primeiro;
	g->vertices[origem].adjacentes.primeiro = novo;
}

/**
 * Libera a memoria associada ao grafo
 *
 * Parametros:
 * Grafo* g: Ponteiro para o grafo
 */
void grafo_liberar(Grafo* g) {
	if (!g) return;

	for (int i = 0; i < g->num_elementos; i++) {
		No* atual = g->vertices[i].adjacentes.primeiro;
		while (atual) {
			No* temp = atual;
			atual = temp->proximo;
			free(temp);
		}
	}

	free(g->vertices);
	free(g);
}

/**
 * BFS
 *
 * Parametros:
 * Grafo* g: ponteiro para o grafo
 * int origem: indice do grafo de origem
 */
void BFS(Grafo* g, int origem) {
	if (!g || origem < 0 || origem >= g->num_elementos) {
		printf("Vertice invalido!\n");
		return;
	}

	int* visitado = (int*)calloc(g->num_elementos, sizeof(int)); // Visitamos o vertice?
	int* fila = (int*)malloc(g->num_elementos * sizeof(int)); // Fila dos vertices a serem processados

	if (!visitado || !fila) {
		printf("Erro de alocacao!\n");
		free(fila);
		free(visitado);
		return;
	}

	int frente = 0;
	int tras = 0;
	visitado[origem] = 1;
	fila[tras++] = origem;

	printf("BFS (origem %d): ", origem);

	while(frente < tras) { // Fila nao vazia
		int atual = fila[frente++];
		printf("%d ", atual);

		No* vizinho = g->vertices[atual].adjacentes.primeiro;
		while (vizinho != NULL) {
			int v = vizinho->valor;
			if (!visitado[v]) {
				visitado[v] = 1;
				fila[tras++] = v;
			}
			vizinho = vizinho->proximo;
		}
	}
	printf("\n");

	free(fila);
	free(visitado);
}

/**
 * DFS (parte recursiva)
 *
 * Parametros:
 * Grafo* g: Ponteiro para o grafo
 * int vertice: o vertice atual, a ser imediatamente visitado
 * int* visitado: ponteiro de contexto para os vertices ja visitados
 */
static void DFS_recursivo(Grafo* g, int vertice, int* visitado) {
	if (!g || vertice < 0 || vertice >= g->num_elementos) {
		return;
	}

	visitado[vertice] = 1;
	printf("%d ", vertice);

	No* vizinho = g->vertices[vertice].adjacentes.primeiro;
	while (vizinho != NULL) {
		int v = vizinho->valor;
		if (!visitado[v]) {
			DFS_recursivo(g, v, visitado);
		}
		vizinho = vizinho->proximo;
	}
}

/**
 * DFS
 *
 * Parametros:
 * Grafo* g: Ponteiro para o grafo
 * int origem: indice para o vertice de origem
 */
void DFS(Grafo* g, int origem) {
	if (!g || origem < 0 || origem >= g->num_elementos) {
		printf("Vertice invalido!\n");
		return;
	}

	int* visitado = (int*)calloc(g->num_elementos, sizeof(int));
	if (!visitado) {
		printf("Erro de alocação!\n");
		return;
	}

	printf("DFS (origem %d): ", origem);
	DFS_recursivo(g, origem, visitado);
	printf("\n");

	free(visitado);
}
