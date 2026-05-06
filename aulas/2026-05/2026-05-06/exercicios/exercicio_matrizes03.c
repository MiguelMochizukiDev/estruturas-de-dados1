/**
 * exercicio_matrizes03.c
 * Autor: Miguel Mochizuki Silva
 * Descricao:
 * Implemente um TAD, minimizando o espaco de
 * memoria utilizado, para representar uma matriz
 * triangular superior. Nesse tipo de matriz,
 * todos os elementos abaixo da diagonal tem valor
 * zero.
 * (Retirado de Celes, pag. 116, exercicio 4.3)
 */
#include <stdio.h>
#include <stdlib.h>

/* ==============================
 * Estruturas
 * ============================== */

typedef struct matriz_triangular_superior_t {
	int n; /* Numero de linhas e colunas da matriz (matriz quadrada) */
	int* elementos; /* Vetor linear para armazenar os elementos da matriz triangular superior */
} MatrizTS;

/* ==============================
 * Funcoes
 * ============================== */

static inline int matriz_ts_indice(int i, int j, int n);

int matriz_ts_acessa(MatrizTS* mat_ts, int i, int j);
void matriz_ts_atribui(MatrizTS* mat_ts, int i, int j, int valor);
MatrizTS* matriz_ts_cria(int n);
void matriz_ts_libera(MatrizTS* mat_ts);

/* ==============================
 * MAIN
 * ============================== */

/**
 * Funcao principal. Testa as funcoes do TAD MatrizTS.
 *
 * Retorna int: EXIT_SUCCESS (0) se sucesso; senao EXIT_FAILURE (1).
 */
int main(void) {
	int n = 3; /* Numero de linhas e colunas da matriz triangular superior */
	MatrizTS* mat_ts; /* Ponteiro para a matriz triangular superior */

	mat_ts = matriz_ts_cria(n);
	if (!mat_ts) return EXIT_FAILURE;

	matriz_ts_atribui(mat_ts, 0, 0, 0);
	matriz_ts_atribui(mat_ts, 0, 1, 1);
	matriz_ts_atribui(mat_ts, 0, 2, 2);
	matriz_ts_atribui(mat_ts, 1, 0, 0);
	matriz_ts_atribui(mat_ts, 1, 1, 3);
	matriz_ts_atribui(mat_ts, 1, 2, 4);
	matriz_ts_atribui(mat_ts, 2, 0, 0);
	matriz_ts_atribui(mat_ts, 2, 1, 0);
	matriz_ts_atribui(mat_ts, 2, 2, 5);


	/* Acima da diagonal */
	if (matriz_ts_acessa(mat_ts, 0, 0) != 0) return EXIT_FAILURE;
	if (matriz_ts_acessa(mat_ts, 0, 1) != 1) return EXIT_FAILURE;
	if (matriz_ts_acessa(mat_ts, 0, 2) != 2) return EXIT_FAILURE;
	if (matriz_ts_acessa(mat_ts, 1, 0) != 0) return EXIT_FAILURE;
	if (matriz_ts_acessa(mat_ts, 1, 1) != 3) return EXIT_FAILURE;
	if (matriz_ts_acessa(mat_ts, 1, 2) != 4) return EXIT_FAILURE;
	if (matriz_ts_acessa(mat_ts, 2, 0) != 0) return EXIT_FAILURE;
	if (matriz_ts_acessa(mat_ts, 2, 1) != 0) return EXIT_FAILURE;
	if (matriz_ts_acessa(mat_ts, 2, 2) != 5) return EXIT_FAILURE;

	/* Abaixo da diagonal (devem ser zero) */
	if (matriz_ts_acessa(mat_ts, 1, 0) != 0) return EXIT_FAILURE;
	if (matriz_ts_acessa(mat_ts, 2, 0) != 0) return EXIT_FAILURE;
	if (matriz_ts_acessa(mat_ts, 2, 1) != 0) return EXIT_FAILURE;

	matriz_ts_libera(mat_ts);

	return EXIT_SUCCESS;
}

/* ==============================
 * Implementacoes
 * ============================== */

/**
 * Calcula o indice no vetor linear para acessar o elemento da matriz triangular superior
 * na posicao (i, j), considerando que i >= j.
 *
 * Organizamos para que os elementos sejam armazenados em ordem de linha,
 * ou seja, primeiro os n elementos da linha 0, depois os n - 1 elementos da linha 1,
 * ..., e o n - i elemento da i-esima linha. Assim, o indice para acessar o elemento (i, j) e dado por:
 *
 * indice = (n + ...  + n - (i - 1)) + j = (n * i) - (i * (i - 1)) / 2 + (j - i) = (n * i) - (i * (i + 1)) / 2 + j
 *
 * Parametros:
 * int i: Indice da linha (0-based).
 * int j: Indice da coluna (0-based).
 * int n: Numero de linhas e colunas da matriz triangular superior (matriz quadrada).
 *
 * Retorna int: O indice no vetor linear correspondente ao elemento (i, j) da matriz triangular superior.
 */
static inline int matriz_ts_indice(int i, int j, int n) {
	return i * n - (i * (i + 1)) / 2 + j;
}

/**
 * Acessa o elemento da matriz triangular superior na posicao (i, j).
 *
 * Parametros:
 * MatrizTS* mat_ts: Ponteiro para a matriz triangular superior.
 * int i: Indice da linha (0-based).
 * int j: Indice da coluna (0-based).
 *
 * Retorna int: O valor do elemento na posicao (i, j) da matriz triangular superior; 0 se i < j ou indices invalidos.
 */
int matriz_ts_acessa(MatrizTS* mat_ts, int i, int j) {
	if (i < 0 || i >= mat_ts->n || j < 0 || j >= mat_ts->n) {
		fprintf(stderr, "Indices invalidos para acesso a MatrizTS.\n");
		return 0; /* Retorna 0 para indices invalidos */
	}
	if (i > j) {
		return 0; /* Elementos abaixo da diagonal sao zero */
	}
	return mat_ts->elementos[matriz_ts_indice(i, j, mat_ts->n)];
}

/**
 * Atribui um valor ao elemento da matriz triangular superior na posicao (i, j).
 *
 * Parametros:
 * MatrizTS* mat_ts: Ponteiro para a matriz triangular superior.
 * int i: Indice da linha (0-based).
 * int j: Indice da coluna (0-based).
 * int valor: O valor a ser atribuido ao elemento na posicao (i, j).
 */
void matriz_ts_atribui(MatrizTS* mat_ts, int i, int j, int valor) {
	if (i < 0 || i >= mat_ts->n || j < 0 || j >= mat_ts->n) {
		fprintf(stderr, "Indices invalidos para atribuicao em MatrizTS.\n");
		return;
	}
	if (i > j) {
		if (valor != 0) {
			fprintf(stderr, "Tentativa de atribuir valor nao zero a elemento abaixo da diagonal em MatrizTS.\n");
		}
		return;
	}
	mat_ts->elementos[matriz_ts_indice(i, j, mat_ts->n)] = valor;
}

/**
 * Cria uma matriz triangular superior de tamanho n x n.
 *
 * Parametros:
 * int n: Numero de linhas e colunas da matriz triangular superior (matriz quadrada).
 *
 * Retorna MatrizTS*: Ponteiro para a matriz triangular superior criada; NULL se falha na alocacao.
 */
MatrizTS* matriz_ts_cria(int n) {
	MatrizTS* mat_ts = malloc(sizeof(MatrizTS));
	if (!mat_ts) {
		fprintf(stderr, "Erro ao alocar estrutura MatrizTS.\n");
		return NULL;
	}

	mat_ts->n = n;

	mat_ts->elementos = malloc((n * (n + 1)) / 2 * sizeof(int));
	if (!mat_ts->elementos) {
		fprintf(stderr, "Erro ao alocar vetor de elementos para MatrizTS.\n");
		free(mat_ts);
		return NULL;
	}

	return mat_ts;
}

/**
 * Libera a memoria alocada para a matriz triangular superior.
 *
 * Parametros:
 * MatrizTS* mat_ts: Ponteiro para a matriz triangular superior a ser liberada.
 */
void matriz_ts_libera(MatrizTS* mat_ts) {
	if (mat_ts) {
		if (mat_ts->elementos) {
			free(mat_ts->elementos);
		}
		free(mat_ts);
	}
}
