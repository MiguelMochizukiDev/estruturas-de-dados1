/**
 * exercicio1.1.c
 * Autor: Miguel Mochizuki Silva
 * Descricao:
 * Implemente uma funcao que indique se um ponto (x, y) esta localizado
 * dentro ou fora de um retangulo. O retangulo e definido por seus vertices
 * inferiores esquerdo (x0, y0) e superior direito (x1, y1). A funcao deve ter como
 * valor de retorno 1, se o ponto estiver dentro do retangulo, e 0 caso contrario,
 * obedecendo ao prototipo
 * 	int dentro_ret(int x0, int y0, int x1, int y1, int x, int y);
 */
#include <stdio.h>

#define STATUS_OK 0 /* Status code for OK in main */
#define STATUS_ERROR 1 /* Status code for error in main */

/* ==============================
 * Funcoes
 * ============================== */

int dentro_ret(int, int, int, int, int, int);

/* ==============================
 * Main
 * ============================== */

/**
 * Testa codigo em alguns casos de uso
 */
int main(void) {
	/* Coordenadas do vertice inferior esquerdo */
	int x0 = 0, y0 = 0;

	/* Coordenadas do vertice superior direito */
	int x1 = 5, y1 = 5;

	/* Coordenadas para o ponto de teste */
	int x, y;

	x = 3, y = 3; /* Dentro */
	if (!dentro_ret(x0, y0, x1, y1, x, y)) return STATUS_ERROR;

	x = 6, y = 3; /* Fora: x esta alem do limite superior na horizontal */
	if (dentro_ret(x0, y0, x1, y1, x, y)) return STATUS_ERROR;

	x = -6, y = 3; /* Fora: x esta abaixo do limite inferior na horizontal */
	if (dentro_ret(x0, y0, x1, y1, x, y)) return STATUS_ERROR;

	x = 3, y = 6; /* Fora: y esta alem do limite superior na vertical */
	if (dentro_ret(x0, y0, x1, y1, x, y)) return STATUS_ERROR;

	x = 3, y = -6; /* Fora: y esta abaixo do limite inferior na vertical */
	if (dentro_ret(x0, y0, x1, y1, x, y)) return STATUS_ERROR;

	x = 6, y = 6; /* Fora: ambos x e y estao alem do limite superior na horizontal */
	if (dentro_ret(x0, y0, x1, y1, x, y)) return STATUS_ERROR;

	return STATUS_OK;
}


/* ==============================
 * Implementacoes
 * ============================== */

/**
 * Decide se o ponto (x, y) esta localizado dentro ou fora de retangulo
 * com vertices inferior esquerdo (x0, y0) e superior direito (x1, y1).
 *
 * Parametros:
 * int x0, y0: coordenadas do vertice inferior esquerdo
 * int x1, y1: coordenadas do vertice superior direito
 * int x, y: coordenadas do ponto que se quer saber dentro ou fora do retangulo
 *
 * Retorna int:
 * 1, se (x, y) pertence ao retangulo
 * 0, caso contrario
 */
int dentro_ret(int x0, int y0, int x1, int y1, int x, int y) {
	if (x < x0 || x > x1) return 0; /* se a projecao horizontal nao esta entre x0 e x1, o ponto nao pertence ao retangulo */
	if (y < y0 || y > y1) return 0; /* se a projecao vertical nao esta entre y0 e y1, o ponto nao pertence ao retangulo */
	return 1;
}
