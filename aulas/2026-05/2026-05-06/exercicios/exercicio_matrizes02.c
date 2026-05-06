/**
 * exercicio_matrizes02.c
 * Autor: Miguel Mochizuki Silva
 * Descricao:
 * Implemente um TAD, minimizando o espaco de
 * memoria utilizado, para representar uma matriz
 * triangular inferior. Nesse tipo de matriz,
 * todos os elementos acima da diagonal tem valor
 * zero.
 * (Retirado de Celes, pag. 116, exercicio 4.2)
 */
#include <stdio.h>
#include <stdlib.h>

/* ==============================
 * Estruturas
 * ============================== */

typedef struct matriz_triangular_inferior_t {
	int n; /* Numero de linhas e colunas da matriz (matriz quadrada) */
	int* elementos; /* Vetor linear para armazenar os elementos da matriz triangular inferior */
} MatrizTI;

/* ==============================
 * Funcoes
 * ============================== */

static inline int matriz_ti_indice(int i, int j);

int matriz_ti_acessa(MatrizTI* mat_ti, int i, int j);
void matriz_ti_atribui(MatrizTI* mat_ti, int i, int j, int valor);
MatrizTI* matriz_ti_cria(int n);
void matriz_ti_libera(MatrizTI* mat_ti);

/* ==============================
 * MAIN
 * ============================== */

/**
 * Funcao principal. Testa as funcoes do TAD MatrizTI.
 *
 * Retorna int: EXIT_SUCCESS (0) se sucesso; senao EXIT_FAILURE (1).
 */
int main(void) {
	int n = 3; /* Numero de linhas e colunas da matriz triangular inferior */
	MatrizTI* mat_ti; /* Ponteiro para a matriz triangular inferior */

	mat_ti = matriz_ti_cria(n);
	if (!mat_ti) return EXIT_FAILURE;

	matriz_ti_atribui(mat_ti, 0, 0, 1);
	matriz_ti_atribui(mat_ti, 1, 0, 2);
	matriz_ti_atribui(mat_ti, 1, 1, 3);
	matriz_ti_atribui(mat_ti, 2, 0, 4);
	matriz_ti_atribui(mat_ti, 2, 1, 5);
	matriz_ti_atribui(mat_ti, 2, 2, 6);

	/* Abaixo da diagonal */
	if (matriz_ti_acessa(mat_ti, 0, 0) != 1) return EXIT_FAILURE;
	if (matriz_ti_acessa(mat_ti, 1, 0) != 2) return EXIT_FAILURE;
	if (matriz_ti_acessa(mat_ti, 1, 1) != 3) return EXIT_FAILURE;
	if (matriz_ti_acessa(mat_ti, 2, 0) != 4) return EXIT_FAILURE;
	if (matriz_ti_acessa(mat_ti, 2, 1) != 5) return EXIT_FAILURE;
	if (matriz_ti_acessa(mat_ti, 2, 2) != 6) return EXIT_FAILURE;

	/* Acima da diagonal (devem ser zero) */
	if (matriz_ti_acessa(mat_ti, 0, 1) != 0) return EXIT_FAILURE;
	if (matriz_ti_acessa(mat_ti, 0, 2) != 0) return EXIT_FAILURE;
	if (matriz_ti_acessa(mat_ti, 1, 2) != 0) return EXIT_FAILURE;

	matriz_ti_libera(mat_ti);

	return EXIT_SUCCESS;
}

/* ==============================
 * Implementacoes
 * ============================== */

/**
 * Calcula o indice no vetor linear para acessar o elemento da matriz triangular inferior
 * na posicao (i, j), considerando que i >= j.
 *
 * Organizamos para que os elementos sejam armazenados em ordem de linha,
 * ou seja, primeiro os 1 elemento da linha 0, depois os 2 elementos da linha 1,
 * ..., e os i elementos da i-esima linha. Assim, o indice para acessar o elemento (i, j) e dado por:
 *
 * indice = (1 + 2 + ... + i) + j = (i * (i + 1)) / 2 + j
 *
 * Parametros:
 * int i: Indice da linha (0-based).
 * int j: Indice da coluna (0-based).
 *
 * Retorna int: O indice no vetor linear correspondente ao elemento (i, j) da matriz triangular inferior.
 */
static inline int matriz_ti_indice(int i, int j) {
	return (i * (i + 1)) / 2 + j;
}

/**
 * Acessa o elemento da matriz triangular inferior na posicao (i, j).
 *
 * Parametros:
 * MatrizTI* mat_ti: Ponteiro para a matriz triangular inferior.
 * int i: Indice da linha (0-based).
 * int j: Indice da coluna (0-based).
 *
 * Retorna int: O valor do elemento na posicao (i, j) da matriz triangular inferior; 0 se i < j ou indices invalidos.
 */
int matriz_ti_acessa(MatrizTI* mat_ti, int i, int j) {
	if (i < 0 || i >= mat_ti->n || j < 0 || j >= mat_ti->n) {
		fprintf(stderr, "Indices invalidos para acesso a MatrizTI.\n");
		return 0; /* Retorna 0 para indices invalidos */
	}
	if (i < j) {
		return 0; /* Elementos acima da diagonal sao zero */
	}
	return mat_ti->elementos[matriz_ti_indice(i, j)];
}

/**
 * Atribui um valor ao elemento da matriz triangular inferior na posicao (i, j).
 *
 * Parametros:
 * MatrizTI* mat_ti: Ponteiro para a matriz triangular inferior.
 * int i: Indice da linha (0-based).
 * int j: Indice da coluna (0-based).
 * int valor: O valor a ser atribuido ao elemento na posicao (i, j).
 */
void matriz_ti_atribui(MatrizTI* mat_ti, int i, int j, int valor) {
	if (i < 0 || i >= mat_ti->n || j < 0 || j >= mat_ti->n) {
		fprintf(stderr, "Indices invalidos para atribuicao em MatrizTI.\n");
		return;
	}
	if (i < j) {
		if (valor != 0) {
			fprintf(stderr, "Tentativa de atribuir valor nao zero a elemento acima da diagonal em MatrizTI.\n");
		}
		return;
	}
	mat_ti->elementos[matriz_ti_indice(i, j)] = valor;
}

/**
 * Cria uma matriz triangular inferior de tamanho n x n.
 *
 * Parametros:
 * int n: Numero de linhas e colunas da matriz triangular inferior (matriz quadrada).
 *
 * Retorna MatrizTI*: Ponteiro para a matriz triangular inferior criada; NULL se falha na alocacao.
 */
MatrizTI* matriz_ti_cria(int n) {
	MatrizTI* mat_ti = malloc(sizeof(MatrizTI));
	if (!mat_ti) {
		fprintf(stderr, "Erro ao alocar estrutura MatrizTI.\n");
		return NULL;
	}

	mat_ti->n = n;

	mat_ti->elementos = malloc((n * (n + 1)) / 2 * sizeof(int));
	if (!mat_ti->elementos) {
		fprintf(stderr, "Erro ao alocar vetor de elementos para MatrizTI.\n");
		free(mat_ti);
		return NULL;
	}

	return mat_ti;
}

/**
 * Libera a memoria alocada para a matriz triangular inferior.
 *
 * Parametros:
 * MatrizTI* mat_ti: Ponteiro para a matriz triangular inferior a ser liberada.
 */
void matriz_ti_libera(MatrizTI* mat_ti) {
	if (mat_ti) {
		if (mat_ti->elementos) {
			free(mat_ti->elementos);
		}
		free(mat_ti);
	}
}
