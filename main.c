/**
 * main.c
 * Autor: Miguel Mochizuki Silva
 * Descricao:
 * Exemplos de uso da biblioteca de estruturas de dados
 * de nossa autoria
 */
#include <stdio.h>
#include "ponto.h"

#define STATUS_OK 0 /* Status de sucesso */
#define STATUS_ERR 1 /* Status de erro */

#define EPSILON 1E-6
#define EQUAL(x, y) ((((x) - (y)) < EPSILON) || ((y) - (x)) < EPSILON)

/* ==============================
 * Funcoes de teste para as estruturas de dados
 * ============================== */

/**
 * Testa o TAD Ponto
 *
 * Retorna int: 0 para sucesso; senao 1
 */
int testar_ponto(void) {
	/* Testa criacao de pontos */
	Ponto* p1 = ponto_cria(3, 4); /* Ponto (3, 4) */
	Ponto* p2 = ponto_cria(0, 0); /* Ponto (0, 0) */

	if (p1 == NULL) return STATUS_ERR;
	if (p2 == NULL) return STATUS_ERR;

	/* Libera memoria apos teste */
	ponto_libera(p1);
	ponto_libera(p2);

	/* Testa acesso a coordenadas de um ponto */
	Ponto* p3 = ponto_cria(3, 4); /* Ponto (3, 4) */

	float x, y; /* Variaveis para armazenar coordenadas de p */

	ponto_acessa(p3, &x, &y);

	if (x != 3 || y != 4) return STATUS_ERR;

	/* Libera memoria apos teste */
	ponto_libera(p3);

	/* Testa atribuicao de novas coordenadas */
	Ponto* p4 = ponto_cria(3, 4); /* Ponto (3, 4) */

	float new_x = 5, new_y = 6; /* Variaveis com novas coordenadas de p */

	ponto_atribui(p4, new_x, new_y);

	float x2, y2; /* Variaveis para armazenar coordenadas de p apos atribuicao */

	ponto_acessa(p4, &x2, &y2);

	if (x2 != new_x || y2 != new_y) return STATUS_ERR;

	/* Libera memoria apos testes */
	ponto_libera(p4);

	/* Testa calculo de distancia entre dois pontos */
	Ponto* p5 = ponto_cria(3, 4);
	Ponto* p6 = ponto_cria(0, 0);

	float distance = ponto_distancia(p5, p6); /* Variavel para armazenar distancia entre p5 e p6 */

	if (!EQUAL(distance, 5)) return STATUS_ERR;

	/* == FIM DOS TESTES */
	return STATUS_OK;
}

/* ==============================
 * MAIN
 * ============================== */

int main(void) {
	if (testar_ponto() == STATUS_ERR) {
		printf("Teste do TAD Ponto falhou\n");
		return STATUS_ERR;
	} else {
		printf("Teste do TAD Ponto passou\n");
	}

	return STATUS_OK;
}
