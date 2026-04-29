/**
 * exercicio2.1.c
 * Autor: Miguel Mochizuki Silva
 * Descricao:
 * Implemente uma funcao que calcule as raizes de uma equacao do segundo grau,
 * do tipo ax^2 + bx + c = 0. Essa funcao deve satisfazer ao prototipo:
 * 	int raizes(float a, float b, float c, float *x1, float *x2);
 * Essa funcao deve ter como valor de retorno o numero de raizes reais e distintas
 * da equacao. Se existirem raizes reais, seus valores devem ser armazenados nas variaveis
 * apontadas por x1 e x2.
 */
#include <stdio.h>
#include <math.h>

#define STATUS_OK 0 /* Status code for OK in main */
#define STATUS_ERROR 1 /* Status code for error in main */

#define EPSILON 1e-5 /* Constante para comparar numeros de ponto flutuante, considerando uma margem de erro pequena */
#define EQUAL(a, b) ( ((a) - (b)) < EPSILON && ((b) - (a)) < EPSILON ) /* Macro para comparar numeros de ponto flutuante, considerando uma margem de erro pequena */

/* ==============================
 * Funcoes
 * ============================== */

int raizes(float a, float b, float c, float *x1, float *x2);

/* ==============================
 * Main
 * ============================== */

/**
 * Testa codigo em alguns casos de uso
 */
int main(void) {
	/* Variaveis para armazenar os coeficientes e as raizes */
	float a, b, c;

	/* Variaveis para armazenar as raizes */
	float x1, x2;

	a = 1; b = -3; c = 2; /* Raizes: 1 e 2 */
	if (raizes(a, b, c, &x1, &x2) != 2 || !EQUAL(x1, 2.0) || !EQUAL(x2, 1.0)) return STATUS_ERROR;

	a = 1; b = -2; c = 1; /* Raiz unica: 1 */
	if (raizes(a, b, c, &x1, &x2) != 1 || !EQUAL(x1, 1.0) || !EQUAL(x2, 1.0)) return STATUS_ERROR;

	a = 1; b = 0; c = 1; /* Sem raizes reais */
	if (raizes(a, b, c, &x1, &x2) != 0) return STATUS_ERROR;

	a = 0; b = 2; c = 1; /* Nao e equacao do segundo grau */
	if (raizes(a, b, c, &x1, &x2) != -1) return STATUS_ERROR;

	return STATUS_OK;
}

/* ==============================
 * Implementacoes
 * ============================== */

/**
 * Calcula as raizes de uma equacao do segundo grau, do tipo ax^2 + bx + c = 0.
 *
 * Parametros:
 * float a, b, c: coeficientes da equacao do segundo grau
 * float *x1, *x2: ponteiros para armazenar as raizes reais, caso existam
 *
 * Retorna int:
 * Numero de raizes reais e distintas da equacao
 */
int raizes(float a, float b, float c, float *x1, float *x2) {
	if (EQUAL(a, 0.0)) return -1; /* Acrescimo nosso: informa nao ser equacao do segundo grau */

	float delta = b * b - 4 * a * c;

	if (delta < 0) return 0;

	if (EQUAL(delta, 0)) {
		*x1 = -b / (2 * a);
		*x2 = *x1;
		return 1;
	}

	*x1 = (-b + sqrt(delta)) / (2 * a);
	*x2 = (-b - sqrt(delta)) / (2 * a);
	return 2;
}
