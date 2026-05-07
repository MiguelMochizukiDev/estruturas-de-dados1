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

static int testar_ponto(void);
static int testar_ponto_criacao(void);
static int testar_ponto_acesso(void);
static int testar_ponto_atribuicao(void);
static int testar_ponto_distancia(void);

static int testar_circulo(void);
static int testar_circulo_criacao(void);
static int testar_circulo_acesso(void);
static int testar_circulo_atribuicao(void);
static int testar_circulo_area(void);
static int testar_circulo_pertence(void);

static int testar_matriz(void);
static int testar_matriz_criacao(void);
static int testar_matriz_dimensoes(void);
static int testar_matriz_inicializacao(void);
static int testar_matriz_atribuicao(void);
static int testar_matriz_indices_invalidos(void);

/* ==============================
 * MAIN
 * ============================== */

int main(void) {
	int falhas = 0;

	printf("=== Testes da Biblioteca ED ===\n\n");

	printf("TAD Ponto:\n");
	if (testar_ponto() != EXIT_SUCCESS) {
		printf("  -> FALHOU\n\n");
		falhas++;
	} else {
		printf("  -> PASSOU\n\n");
	}

	printf("TAD Circulo:\n");
	if (testar_circulo() != EXIT_SUCCESS) {
		printf("  -> FALHOU\n\n");
		falhas++;
	} else {
		printf("  -> PASSOU\n\n");
	}

	printf("TAD Matriz:\n");
	if (testar_matriz() != EXIT_SUCCESS) {
		printf("  -> FALHOU\n\n");
		falhas++;
	} else {
		printf("  -> PASSOU\n\n");
	}

	printf("=== Resultado: %d/%d suites passaram ===\n",
		3 - falhas, 3);

	return (falhas == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}

/* ==============================
 * Testes do TAD Ponto
 * ============================== */

static int testar_ponto(void) {
	if (testar_ponto_criacao() != EXIT_SUCCESS) return EXIT_FAILURE;
	if (testar_ponto_acesso() != EXIT_SUCCESS) return EXIT_FAILURE;
	if (testar_ponto_atribuicao() != EXIT_SUCCESS) return EXIT_FAILURE;
	if (testar_ponto_distancia() != EXIT_SUCCESS) return EXIT_FAILURE;
	return EXIT_SUCCESS;
}

static int testar_ponto_criacao(void) {
	Ponto *p1 = ponto_cria(3, 4);
	Ponto *p2 = ponto_cria(0, 0);

	if (p1 == NULL) {
		ponto_libera(p2);
		printf("  [FALHA] ponto_cria(3,4) retornou NULL\n");
		return EXIT_FAILURE;
	}
	if (p2 == NULL) {
		ponto_libera(p1);
		printf("  [FALHA] ponto_cria(0,0) retornou NULL\n");
		return EXIT_FAILURE;
	}

	ponto_libera(p1);
	ponto_libera(p2);
	printf("  [OK] Criacao de pontos\n");
	return EXIT_SUCCESS;
}

static int testar_ponto_acesso(void) {
	Ponto *p = ponto_cria(3, 4);
	double x, y;

	if (p == NULL) {
		printf("  [FALHA] ponto_cria(3,4) retornou NULL\n");
		return EXIT_FAILURE;
	}

	if (ponto_acessa(p, &x, &y) != STATUS_OK) {
		ponto_libera(p);
		printf("  [FALHA] ponto_acessa falhou\n");
		return EXIT_FAILURE;
	}

	if (x != 3.0 || y != 4.0) {
		ponto_libera(p);
		printf("  [FALHA] Coordenadas incorretas no acesso\n");
		return EXIT_FAILURE;
	}

	ponto_libera(p);
	printf("  [OK] Acesso a coordenadas\n");
	return EXIT_SUCCESS;
}

static int testar_ponto_atribuicao(void) {
	Ponto *p = ponto_cria(3, 4);
	double x, y;

	if (p == NULL) {
		printf("  [FALHA] ponto_cria(3,4) retornou NULL\n");
		return EXIT_FAILURE;
	}

	if (ponto_atribui(p, 5.0, 6.0) != STATUS_OK) {
		ponto_libera(p);
		printf("  [FALHA] ponto_atribui falhou\n");
		return EXIT_FAILURE;
	}

	if (ponto_acessa(p, &x, &y) != STATUS_OK) {
		ponto_libera(p);
		printf("  [FALHA] ponto_acessa apos atribuicao falhou\n");
		return EXIT_FAILURE;
	}

	if (x != 5.0 || y != 6.0) {
		ponto_libera(p);
		printf("  [FALHA] Coordenadas incorretas apos atribuicao\n");
		return EXIT_FAILURE;
	}

	ponto_libera(p);
	printf("  [OK] Atribuicao de coordenadas\n");
	return EXIT_SUCCESS;
}

static int testar_ponto_distancia(void) {
	Ponto *p1 = ponto_cria(3, 4);
	Ponto *p2 = ponto_cria(0, 0);
	double distancia;

	if (p1 == NULL || p2 == NULL) {
		ponto_libera(p1);
		ponto_libera(p2);
		printf("  [FALHA] ponto_cria retornou NULL\n");
		return EXIT_FAILURE;
	}

	if (ponto_distancia(p1, p2, &distancia) != STATUS_OK) {
		ponto_libera(p1);
		ponto_libera(p2);
		printf("  [FALHA] ponto_distancia falhou\n");
		return EXIT_FAILURE;
	}

	if (!EQUAL(distancia, 5.0)) {
		ponto_libera(p1);
		ponto_libera(p2);
		printf("  [FALHA] Distancia incorreta (esperado: 5.0)\n");
		return EXIT_FAILURE;
	}

	ponto_libera(p1);
	ponto_libera(p2);
	printf("  [OK] Calculo de distancia\n");
	return EXIT_SUCCESS;
}

/* ==============================
 * Testes do TAD Circulo
 * ============================== */

static int testar_circulo(void) {
	if (testar_circulo_criacao() != EXIT_SUCCESS) return EXIT_FAILURE;
	if (testar_circulo_acesso() != EXIT_SUCCESS) return EXIT_FAILURE;
	if (testar_circulo_atribuicao() != EXIT_SUCCESS) return EXIT_FAILURE;
	if (testar_circulo_area() != EXIT_SUCCESS) return EXIT_FAILURE;
	if (testar_circulo_pertence() != EXIT_SUCCESS) return EXIT_FAILURE;
	return EXIT_SUCCESS;
}

static int testar_circulo_criacao(void) {
	Circulo *c = circulo_cria(0, 0, 5);

	if (c == NULL) {
		printf("  [FALHA] circulo_cria(0,0,5) retornou NULL\n");
		return EXIT_FAILURE;
	}

	circulo_libera(c);
	printf("  [OK] Criacao de circulo\n");
	return EXIT_SUCCESS;
}

static int testar_circulo_acesso(void) {
	Circulo *c = circulo_cria(0, 0, 5);
	double x, y, r;

	if (c == NULL) {
		printf("  [FALHA] circulo_cria(0,0,5) retornou NULL\n");
		return EXIT_FAILURE;
	}

	if (circulo_acessa(c, &x, &y, &r) != STATUS_OK) {
		circulo_libera(c);
		printf("  [FALHA] circulo_acessa falhou\n");
		return EXIT_FAILURE;
	}

	if (x != 0.0 || y != 0.0 || r != 5.0) {
		circulo_libera(c);
		printf("  [FALHA] Atributos incorretos no acesso\n");
		return EXIT_FAILURE;
	}

	circulo_libera(c);
	printf("  [OK] Acesso a atributos\n");
	return EXIT_SUCCESS;
}

static int testar_circulo_atribuicao(void) {
	Circulo *c = circulo_cria(0, 0, 5);
	double x, y, r;
	Status st;

	if (c == NULL) {
		printf("  [FALHA] circulo_cria(0,0,5) retornou NULL\n");
		return EXIT_FAILURE;
	}

	/* Atribuicao valida */
	if (circulo_atribui(c, 1, 1, 2) != STATUS_OK) {
		circulo_libera(c);
		printf("  [FALHA] circulo_atribui falhou\n");
		return EXIT_FAILURE;
	}

	if (circulo_acessa(c, &x, &y, &r) != STATUS_OK) {
		circulo_libera(c);
		printf("  [FALHA] circulo_acessa apos atribuicao falhou\n");
		return EXIT_FAILURE;
	}

	if (x != 1.0 || y != 1.0 || r != 2.0) {
		circulo_libera(c);
		printf("  [FALHA] Atributos incorretos apos atribuicao\n");
		return EXIT_FAILURE;
	}

	/* Testa raio negativo (deve falhar) */
	st = circulo_atribui(c, 0, 0, -1);
	if (st != STATUS_ERR_VALOR) {
		circulo_libera(c);
		printf("  [FALHA] Raio negativo deveria retornar STATUS_ERR_VALOR\n");
		return EXIT_FAILURE;
	}

	circulo_libera(c);
	printf("  [OK] Atribuicao de atributos\n");
	return EXIT_SUCCESS;
}

static int testar_circulo_area(void) {
	Circulo *c = circulo_cria(0, 0, 5);
	double area;

	if (c == NULL) {
		printf("  [FALHA] circulo_cria(0,0,5) retornou NULL\n");
		return EXIT_FAILURE;
	}

	if (circulo_area(c, &area) != STATUS_OK) {
		circulo_libera(c);
		printf("  [FALHA] circulo_area falhou\n");
		return EXIT_FAILURE;
	}

	if (!EQUAL(area, 78.5398163375)) {
		circulo_libera(c);
		printf("  [FALHA] Area incorreta\n");
		return EXIT_FAILURE;
	}

	circulo_libera(c);
	printf("  [OK] Calculo de area\n");
	return EXIT_SUCCESS;
}

static int testar_circulo_pertence(void) {
	Circulo *c = circulo_cria(0, 0, 5);
	Ponto *p = NULL;
	int pertence;

	if (c == NULL) {
		printf("  [FALHA] circulo_cria(0,0,5) retornou NULL\n");
		return EXIT_FAILURE;
	}

	/* Ponto dentro do circulo */
	p = ponto_cria(3, 4);
	if (p == NULL) {
		circulo_libera(c);
		printf("  [FALHA] ponto_cria(3,4) retornou NULL\n");
		return EXIT_FAILURE;
	}

	if (circulo_pertence(c, p, &pertence) != STATUS_OK) {
		circulo_libera(c);
		ponto_libera(p);
		printf("  [FALHA] circulo_pertence falhou\n");
		return EXIT_FAILURE;
	}

	if (pertence != 1) {
		circulo_libera(c);
		ponto_libera(p);
		printf("  [FALHA] Ponto (3,4) deveria pertencer ao circulo\n");
		return EXIT_FAILURE;
	}

	/* Ponto fora do circulo */
	ponto_atribui(p, 10, 10);
	if (circulo_pertence(c, p, &pertence) != STATUS_OK) {
		circulo_libera(c);
		ponto_libera(p);
		printf("  [FALHA] circulo_pertence(p externo) falhou\n");
		return EXIT_FAILURE;
	}

	if (pertence != 0) {
		circulo_libera(c);
		ponto_libera(p);
		printf("  [FALHA] Ponto (10,10) nao deveria pertencer ao circulo\n");
		return EXIT_FAILURE;
	}

	circulo_libera(c);
	ponto_libera(p);
	printf("  [OK] Pertinencia de pontos\n");
	return EXIT_SUCCESS;
}

/* ==============================
 * Testes do TAD Matriz
 * ============================== */

static int testar_matriz(void) {
	if (testar_matriz_criacao() != EXIT_SUCCESS) return EXIT_FAILURE;
	if (testar_matriz_dimensoes() != EXIT_SUCCESS) return EXIT_FAILURE;
	if (testar_matriz_inicializacao() != EXIT_SUCCESS) return EXIT_FAILURE;
	if (testar_matriz_atribuicao() != EXIT_SUCCESS) return EXIT_FAILURE;
	if (testar_matriz_indices_invalidos() != EXIT_SUCCESS) return EXIT_FAILURE;
	return EXIT_SUCCESS;
}

static int testar_matriz_criacao(void) {
	Matriz *m = matriz_cria(2, 3);

	if (m == NULL) {
		printf("  [FALHA] matriz_cria(2,3) retornou NULL\n");
		return EXIT_FAILURE;
	}

	matriz_libera(m);
	printf("  [OK] Criacao de matriz\n");
	return EXIT_SUCCESS;
}

static int testar_matriz_dimensoes(void) {
	Matriz *m = matriz_cria(2, 3);
	int linhas, colunas;

	if (m == NULL) {
		printf("  [FALHA] matriz_cria(2,3) retornou NULL\n");
		return EXIT_FAILURE;
	}

	if (matriz_linhas(m, &linhas) != STATUS_OK) {
		matriz_libera(m);
		printf("  [FALHA] matriz_linhas falhou\n");
		return EXIT_FAILURE;
	}

	if (matriz_colunas(m, &colunas) != STATUS_OK) {
		matriz_libera(m);
		printf("  [FALHA] matriz_colunas falhou\n");
		return EXIT_FAILURE;
	}

	if (linhas != 2 || colunas != 3) {
		matriz_libera(m);
		printf("  [FALHA] Dimensoes incorretas\n");
		return EXIT_FAILURE;
	}

	matriz_libera(m);
	printf("  [OK] Acesso a dimensoes\n");
	return EXIT_SUCCESS;
}

static int testar_matriz_inicializacao(void) {
	Matriz *m = matriz_cria(2, 3);
	double valor;

	if (m == NULL) {
		printf("  [FALHA] matriz_cria(2,3) retornou NULL\n");
		return EXIT_FAILURE;
	}

	if (matriz_acessa(m, 0, 0, &valor) != STATUS_OK) {
		matriz_libera(m);
		printf("  [FALHA] matriz_acessa falhou\n");
		return EXIT_FAILURE;
	}

	if (!EQUAL(valor, 0.0)) {
		matriz_libera(m);
		printf("  [FALHA] Matriz deveria ser inicializada com zeros\n");
		return EXIT_FAILURE;
	}

	matriz_libera(m);
	printf("  [OK] Inicializacao com zeros\n");
	return EXIT_SUCCESS;
}

static int testar_matriz_atribuicao(void) {
	Matriz *m = matriz_cria(2, 3);
	double valor;

	if (m == NULL) {
		printf("  [FALHA] matriz_cria(2,3) retornou NULL\n");
		return EXIT_FAILURE;
	}

	if (matriz_atribui(m, 0, 0, 5.0) != STATUS_OK) {
		matriz_libera(m);
		printf("  [FALHA] matriz_atribui falhou\n");
		return EXIT_FAILURE;
	}

	if (matriz_acessa(m, 0, 0, &valor) != STATUS_OK) {
		matriz_libera(m);
		printf("  [FALHA] matriz_acessa apos atribuicao falhou\n");
		return EXIT_FAILURE;
	}

	if (!EQUAL(valor, 5.0)) {
		matriz_libera(m);
		printf("  [FALHA] Valor atribuido nao corresponde\n");
		return EXIT_FAILURE;
	}

	matriz_libera(m);
	printf("  [OK] Atribuicao e acesso a elemento\n");
	return EXIT_SUCCESS;
}

static int testar_matriz_indices_invalidos(void) {
	Matriz *m = matriz_cria(2, 3);
	double valor;
	Status st;

	if (m == NULL) {
		printf("  [FALHA] matriz_cria(2,3) retornou NULL\n");
		return EXIT_FAILURE;
	}

	st = matriz_acessa(m, 10, 10, &valor);
	if (st != STATUS_ERR_INDEX) {
		matriz_libera(m);
		printf("  [FALHA] Indice invalido deveria retornar STATUS_ERR_INDEX\n");
		return EXIT_FAILURE;
	}

	matriz_libera(m);
	printf("  [OK] Validacao de indices invalidos\n");
	return EXIT_SUCCESS;
}
