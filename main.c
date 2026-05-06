/**
 * main.c
 * Autor: Miguel Mochizuki Silva
 * Descricao:
 * Exemplos de uso da biblioteca de estruturas de dados
 * de nossa autoria
 */
#include <stdio.h>
#include "ponto.h"
#include "circulo.h"
#include "matriz.h"

#define STATUS_OK 0 /* Status de sucesso */
#define STATUS_ERR 1 /* Status de erro */

#define EPSILON 1E-3
#define EQUAL(x, y) (((x) - (y)) < EPSILON) && (((x) - (y)) > -EPSILON)

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
	if (ponto_libera(p1)) return STATUS_ERR;
	if (ponto_libera(p2)) return STATUS_ERR;

	/* Testa acesso a coordenadas de um ponto */
	Ponto* p3 = ponto_cria(3, 4); /* Ponto (3, 4) */

	double x, y; /* Variaveis para armazenar coordenadas de p */

	if (ponto_acessa(p3, &x, &y)) return STATUS_ERR;
	if (x != 3 || y != 4) return STATUS_ERR;

	/* Libera memoria apos teste */
	ponto_libera(p3);

	/* Testa atribuicao de novas coordenadas */
	Ponto* p4 = ponto_cria(3, 4); /* Ponto (3, 4) */

	double new_x = 5, new_y = 6; /* Variaveis com novas coordenadas de p */

	if (ponto_atribui(p4, new_x, new_y)) return STATUS_ERR;

	double x2, y2; /* Variaveis para armazenar coordenadas de p apos atribuicao */

	if (ponto_acessa(p4, &x2, &y2)) return STATUS_ERR;

	if (x2 != new_x || y2 != new_y) return STATUS_ERR;

	/* Libera memoria apos testes */
	ponto_libera(p4);

	/* Testa calculo de distancia entre dois pontos */
	Ponto* p5 = ponto_cria(3, 4);
	Ponto* p6 = ponto_cria(0, 0);

	double distance;
	if (ponto_distancia(p5, p6, &distance)) return STATUS_ERR;

	if (!EQUAL(distance, 5)) return STATUS_ERR;

	/* == FIM DOS TESTES */
	return STATUS_OK;
}

/**
 * Testa o TAD Circulo
 *
 * Retorna int: 0 para sucesso; senao 1
 */
int testar_circulo(void) {
	/* Testa criacao de circulos */
	Circulo* c1 = circulo_cria(0, 0, 5); /* Circulo com centro em (0, 0) e raio 5 */
	Circulo* c2 = circulo_cria(1, 1, 2); /* Circulo com centro em (1, 1) e raio 2 */

	if (c1 == NULL) return STATUS_ERR;
	if (c2 == NULL) return STATUS_ERR;

	/* Libera memoria apos teste */
	if (circulo_libera(c1)) return STATUS_ERR;
	if (circulo_libera(c2)) return STATUS_ERR;

	/* Testa acesso a atributos de um circulo */
	Circulo* c3 = circulo_cria(0, 0, 5); /* Circulo com centro em (0, 0) e raio 5 */

	double x, y, r; /* Variaveis para armazenar atributos de c */

	if (circulo_acessa(c3, &x, &y, &r)) return STATUS_ERR;

	if (x != 0 || y != 0 || r != 5) return STATUS_ERR;

	/* Libera memoria apos teste */
	circulo_libera(c3);

	/* Testa atribuicao de novos atributos */
	Circulo* c4 = circulo_cria(0, 0, 5); /* Circulo com centro em (0, 0) e raio 5 */

	double new_x = 1, new_y = 1, new_r = 2; /* Variaveis com novos atributos de c */

	if (circulo_atribui(c4, new_x, new_y, new_r)) return STATUS_ERR;

	double x2, y2, r2; /* Variaveis para armazenar atributos de c apos atribuicao */

	if (circulo_acessa(c4, &x2, &y2, &r2)) return STATUS_ERR;

	if (x2 != new_x || y2 != new_y || r2 != new_r) return STATUS_ERR;

	/* Libera memoria apos teste */
	circulo_libera(c4);

	/* Testa calculo de area de um circulo */
	Circulo* c5 = circulo_cria(0, 0, 5); /* Circulo com centro em (0, 0) e raio 5 */

	double area;
	if (circulo_area(c5, &area)) return STATUS_ERR;

	if (!EQUAL(area, 78.5398163375)) return STATUS_ERR;

	/* Libera memoria apos teste */
	circulo_libera(c5);

	/* Testa se um ponto pertence a um circulo */
	Circulo* c6 = circulo_cria(0, 0, 5); /* Circulo com centro em (0, 0) e raio 5 */
	Ponto* p1 = ponto_cria(3, 4); /* Ponto (3, 4) */


	if (!circulo_pertence(c6, p1)) return STATUS_ERR;

	/* Libera memoria apos teste */
	circulo_libera(c6);
	ponto_libera(p1);

	/* == FIM DOS TESTES */
	return STATUS_OK;
}

/**
 * Testa o TAD Matriz
 *
 * Retorna int: 0 para sucesso; senao 1
 */
int testar_matriz(void) {
	/* Testa criacao de matrizes */
	Matriz* m1 = matriz_cria(2, 3); /* Matriz de dimensao 2x3 */
	Matriz* m2 = matriz_cria(4, 5); /* Matriz de dimensao 4x5 */

	if (m1 == NULL) return STATUS_ERR;
	if (m2 == NULL) return STATUS_ERR;

	/* Libera memoria apos teste */
	matriz_libera(m1);
	matriz_libera(m2);

	/* Testa acesso a elementos de uma matriz */
	Matriz* m3 = matriz_cria(2, 3); /* Matriz de dimensao 2x3 */

	double element = matriz_acessa(m3, 0, 0); /* Variavel para armazenar elemento da linha 0 e coluna 0 */

	/* Conforme implementacao */
	if (element != 0) return STATUS_ERR;

	/* Libera memoria apos teste */
	matriz_libera(m3);

	/* Testa atribuicao de novo valor a um elemento da matriz */
	Matriz* m4 = matriz_cria(2, 3); /* Matriz de dimensao 2x3 */

	matriz_atribui(m4, 0, 0, 5); /* Atribui o valor 5 ao elemento da linha 0 e coluna 0 */

	float element2 = matriz_acessa(m4, 0, 0); /* Variavel para armazenar elemento da linha 0 e coluna 0 apos atribuicao */

	if (element2 != 5) return STATUS_ERR;

	/* Libera memoria apos teste */
	matriz_libera(m4);

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

	if (testar_circulo() == STATUS_ERR) {
		printf("Teste do TAD Circulo falhou\n");
		return STATUS_ERR;
	} else {
		printf("Teste do TAD Circulo passou\n");
	}

	if (testar_matriz() == STATUS_ERR) {
		printf("Teste do TAD Matriz falhou\n");
		return STATUS_ERR;
	} else {
		printf("Teste do TAD Matriz passou\n");
	}

	return STATUS_OK;
}
