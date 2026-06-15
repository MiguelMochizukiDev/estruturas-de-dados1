/**
 * main.c
 * Autor: Miguel Mochizuki Silva
 * Descricao:
 * Testes automatizados da biblioteca de estruturas de dados (ED)
 */
#include <stdio.h>
#include <stdlib.h>
#include "ed.h"

/* ==============================
 * Defines
 * ============================== */

#define EPSILON 1E-3
#define EQUAL(x, y) (((x) - (y)) < EPSILON) && (((x) - (y)) > -EPSILON)

/* ==============================
 * Funcoes auxiliares
 * ============================== */

static void print_menu(void);
static void testa_circulo(void);
static void testa_lista_linkada(void);
static void testa_matriz(void);
static void testa_pilha(void);
static void testa_fila(void);
static void testa_ponto(void);
static void testa_lista_vetores(void);

/* ==============================
 * MAIN
 * ============================== */

int main(void) {
	print_menu();
}

/* ==============================
 * Implementacoes
 * ============================== */

static void print_menu(void) {
	while (1) {
		printf("=== Testes de Estruturas de Dados ===\n");
		printf("1. Circulo\n");
		printf("2. Lista linkada\n");
		printf("3. Matriz\n");
		printf("4. Pilha\n");
		printf("5. Ponto\n");
		printf("6. Lista de vetores\n");
		printf("0. Sair\n");
		printf("Escolha uma opcao: ");

		int opcao;
		scanf("%d", &opcao);

		switch (opcao) {
			case 1:
				testa_circulo();
				break;
			case 2:
				testa_lista_linkada();
				break;
			case 3:
				testa_matriz();
				break;
			case 4:
				testa_pilha();
				break;
			case 5:
				testa_fila();
				break;
			case 6:
				testa_ponto();
				break;
			case 7:
				testa_lista_vetores();
				break;
			case 0:
				printf("Encerrando o programa...\n");
				break;
			default:
				printf("Opcao invalida. Tente novamente.\n");
		}
	}
}

static void testa_circulo(void) {
	printf("Testando Circulo...\n");
}

static void testa_lista_linkada(void) {
	printf("Testando Lista Linkada...\n");
}

static void testa_matriz(void) {
	printf("Testando Matriz...\n");
}

static void testa_pilha(void) {
	printf("Testando Pilha...\n");
}

static void testa_fila(void) {
	printf("Testando Fila...\n");
}

static void testa_ponto(void) {
	printf("Testando Ponto...\n");
}

static void testa_lista_vetores(void) {
	printf("Testando Lista de Vetores...\n");
}
