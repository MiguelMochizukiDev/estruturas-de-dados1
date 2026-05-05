/**
 * exercicio_arquivo02.c
 * Autor: Miguel Mochizuki Silva
 * Descricao:
 * - Ler "primeiro nome" e "idade" de n pessoas; Guardar em arquivo texto.
 * - Mostrar nome de maiores de 18 anos.
 * - Ordenar os nomes e salvar em novo arquivo
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAXLEN 100 /* Comprimento maximo de strings */

/* ==============================
 * Estruturas
 * ============================== */

/**
 * Estrutura para armazenar informacoes de uma pessoa
 *
 * Atributos:
 * char primeiro_nome[MAXLEN]: string para armazenar o primeiro nome
 * int idade: idade da pessoa
 */
typedef struct pessoa_t {
	char primeiro_nome[MAXLEN];
	int idade;
} Pessoa;

/* ==============================
 * Funcoes
 * ============================== */

static void escreve_csv_string(FILE*, const char*);
static int partition(Pessoa*, int, int);
static void quick_sort_helper(Pessoa*, int, int);
static void swap(Pessoa*, Pessoa*);

int armazena(FILE*, const Pessoa*, int);
void clear_io_buffer(void);
void imprime_maiores(const Pessoa*, int);
Pessoa* parse_pessoas(int);
void quick_sort(Pessoa*, int);
void trim(char*);

/* ==============================
 * MAIN
 * ============================== */

/**
 * Menu interativo
 *
 * Retorna int: EXIT_SUCCESS (0) se sucesso; senao EXIT_FAILURE (1)
 */
int main(void) {
	int n; /* Numero de pessoas */
	const char filename[] = "array_pessoas.csv";
	const char sorted_filename[] = "array_pessoas_sorted.csv";

	printf("Digite o numero de pessoas: ");
	if (scanf("%d", &n) != 1 || n <= 0) {
		fprintf(stderr, "Entrada invalida para numero de pessoas.\n");
		return EXIT_FAILURE;
	}
	clear_io_buffer();

	Pessoa* pessoas = parse_pessoas(n);
	if (pessoas == NULL) {
		fprintf(stderr, "Erro ao alocar memoria para pessoas.\n");
		return EXIT_FAILURE;
	}

	imprime_maiores(pessoas, n);

	FILE* fp = fopen(filename, "w");
	if (fp == NULL) {
		fprintf(stderr, "Erro ao criar arquivo %s.\n", filename);
		free(pessoas);
		return EXIT_FAILURE;
	}

	if (!armazena(fp, pessoas, n)) {
		fprintf(stderr, "Erro ao armazenar pessoas no arquivo.\n");
		fclose(fp);
		free(pessoas);
		return EXIT_FAILURE;
	}

	if (fclose(fp) != 0) {
		fprintf(stderr, "Erro ao fechar arquivo %s.\n", filename);
		free(pessoas);
		return EXIT_FAILURE;
	}

	/* Ordena pessoas por nome */
	quick_sort(pessoas, n);

	FILE* fp_sorted = fopen(sorted_filename, "w");
	if (fp_sorted == NULL) {
		fprintf(stderr, "Erro ao criar arquivo %s.\n", sorted_filename);
		free(pessoas);
		return EXIT_FAILURE;
	}

	if (!armazena(fp_sorted, pessoas, n)) {
		fprintf(stderr, "Erro ao armazenar pessoas no arquivo ordenado.\n");
		fclose(fp_sorted);
		free(pessoas);
		return EXIT_FAILURE;
	}

	fclose(fp_sorted);

	free(pessoas);
	return EXIT_SUCCESS;
}

/* ==============================
 * Implementacoes
 * ============================== */

/**
 * Escreve uma string em formato CSV, escapando aspas
 *
 * Parametros:
 * FILE* fp: ponteiro para arquivo aberto para escrita
 * const char* str: string a ser escrita
 */
static void escreve_csv_string(FILE* fp, const char* str) {
	fputc('"', fp);

	for (const char* p = str; *p; p++) {
	if (*p == '"') {
		fputc('"', fp); /* escape */
	}
	fputc(*p, fp);
	}

	fputc('"', fp);
}

/**
 * Particiona um array de Pessoa para o algoritmo de quicksort,
 * usando o primeiro nome e a idade como chaves de ordenacao
 *
 * Parametros:
 * Pessoa* arr: array a ser particionado
 * int low: indice inicial do subarray
 * int high: indice final do subarray
 *
 * Retorna int: indice do pivô apos particionamento
 */
static int partition(Pessoa* arr, int low, int high) {
	Pessoa pivot = arr[high];

	int i = low - 1; /* indice do ultimo elemento menor que o pivo */
	int j = low; /* indice do elemento atual */
	while (j < high) {
		if (strcmp(arr[j].primeiro_nome, pivot.primeiro_nome) < 0 ||
			(strcmp(arr[j].primeiro_nome, pivot.primeiro_nome) == 0 && arr[j].idade < pivot.idade)) {
			i++;
			swap(&arr[i], &arr[j]);
		}
		j++;
	}

	swap(&arr[i + 1], &arr[high]); /* coloca o pivo na posicao correta, entre os elementos menores e maiores */
	return i + 1;
}

/**
 * Funcao auxiliar recursiva para o algoritmo de quicksort
 *
 * Parametros:
 * Pessoa* arr: array a ser ordenado
 * int low: indice inicial do subarray a ordenar
 * int high: indice final do subarray a ordenar
 */
static void quick_sort_helper(Pessoa* arr, int low, int high) {
	if (low < high) {
		int pi = partition(arr, low, high);

		quick_sort_helper(arr, low, pi - 1);
		quick_sort_helper(arr, pi + 1, high);
	}
}

/**
 * Troca dois elementos de um array de Pessoa
 *
 * Parametros:
 * Pessoa* a: ponteiro para primeiro elemento
 * Pessoa* b: ponteiro para segundo elemento
 */
static void swap(Pessoa* a, Pessoa* b) {
	Pessoa temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * Armazena pessoas em arquivo CSV
 *
 * Parametros:
 * FILE* fp: ponteiro para arquivo aberto para escrita
 * const Pessoa* pessoas: array de pessoas a armazenar
 * int n: numero de pessoas no array
 *
 * Retorna int: 1 se sucesso; senao 0
 */
int armazena(FILE* fp, const Pessoa* pessoas, int n) {
	if (fp == NULL || pessoas == NULL || n <= 0) return 0;

	for (int i = 0; i < n; i++) {
		escreve_csv_string(fp, pessoas[i].primeiro_nome);

		if (fprintf(fp, ",%d\n", pessoas[i].idade) < 0) {
			return 0;
		}
	}

	return 1;
}

/**
 * Limpa o buffer de entrada para evitar problemas com fgets apos scanf
 */
void clear_io_buffer(void) {
	int c;
	while ((c = getchar()) != '\n' && c != EOF);
}

/**
 * Imprime os nomes das pessoas maiores de 18 anos
 *
 * Parametros:
 * const Pessoa* pessoas: array de pessoas
 * int n: numero de pessoas no array
 */
void imprime_maiores(const Pessoa* pessoas, int n) {
	if (pessoas == NULL || n <= 0) return;

	printf("Pessoas maiores de 18 anos:\n");
	for (int i = 0; i < n; i++) {
		if (pessoas[i].idade > 18) {
			printf("- %s\n", pessoas[i].primeiro_nome);
		}
	}
}

/**
 * Le n pessoas do usuario e retorna um array alocado dinamicamente
 *
 * Parametros:
 * int n: numero de pessoas a ler
 *
 * Retorna Pessoa*: ponteiro para array de pessoas; NULL se erro
 */
Pessoa* parse_pessoas(int n) {
	if (n <= 0) return NULL;

	Pessoa* pessoas = malloc((size_t)n * sizeof(Pessoa));
	if (pessoas == NULL) return NULL;

	for (int i = 0; i < n; i++) {
		printf("Digite o primeiro nome: ");

		if (!fgets(pessoas[i].primeiro_nome, sizeof(pessoas[i].primeiro_nome), stdin)) {
			fprintf(stderr, "Erro ao ler nome.\n");
			free(pessoas);
			return NULL;
		}

		trim(pessoas[i].primeiro_nome);

		printf("Digite a idade: ");
		if (scanf("%d", &pessoas[i].idade) != 1 ||
			pessoas[i].idade < 0 || pessoas[i].idade > 150) {
			fprintf(stderr, "Entrada invalida para idade.\n");
			free(pessoas);
			return NULL;
		}

		clear_io_buffer();
	}

	return pessoas;
}

/**
 * Ordena um array de Pessoa usando o algoritmo de quicksort, ordenando por nome e idade
 *
 * Parametros:
 * Pessoa* arr: array a ser ordenado
 * int n: numero de elementos no array
 */
void quick_sort(Pessoa* arr, int n) {
	if (arr == NULL || n <= 1) return;

	/* Implementacao recursiva do quicksort */
	quick_sort_helper(arr, 0, n - 1);
}

/**
 * Remove espacos em branco do inicio e fim de uma string
 *
 * Parametros:
 * char* str: string a ser trimada; modificada in-place
 */
void trim(char* str) {
	if (str == NULL) return;

	char* start = str;

	while (*start && isspace((unsigned char)*start)) {
		start++;
	}

	if (*start == '\0') {
		*str = '\0';
		return;
	}

	char* end = start + strlen(start) - 1;

	while (end > start && isspace((unsigned char)*end)) {
		end--;
	}

	*(end + 1) = '\0';

	if (start != str) {
		memmove(str, start, strlen(start) + 1);
	}
}
