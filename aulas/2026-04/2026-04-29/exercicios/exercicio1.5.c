/**
 * exercicio1.5.c
 * Autor: Miguel Mochizuki Silva
 * Descricao:
 * Implemente uma funcao que retorne uma aproximacao do valor de pi,
 * de acordo com a formula de Leibniz:
 * 	pi = 4 * (1 - 1/3 + 1/5 - 1/7 + 1/9 - ...)
 * Essa funcao deve seguir ao seguinte prototipo, em que n indica o numero
 * de termos que deve ser usado	para avaliar o valor de pi:
 * 	double pi(int n);
 */
#include <stdio.h>

#define STATUS_OK 0 /* Status code for OK in main */
#define STATUS_ERROR 1 /* Status code for error in main */

#define EPSILON 1e-9
#define EQUAL(a, b) ( ((a) - (b)) < EPSILON && ((b) - (a)) < EPSILON ) /* Macro para comparar numeros de ponto flutuante, considerando uma margem de erro pequena */

/* ==============================
 * Funcoes
 * ============================== */

double pi(int n);

/* ==============================
 * Main
 * ============================== */

/**
 * Testa codigo em alguns casos de uso
 */
int main(void) {
	/* Numero a ser testado */
	int n;

	n = 1; /* pi(1) = 4.0 */
	if (!EQUAL(pi(n), 4.0)) return STATUS_ERROR;

	n = 2; /* pi(2) = 2.666666666666667 */
	if (!EQUAL(pi(n), 2.666666666666667)) return STATUS_ERROR;

	n = 3; /* pi(3) = 3.466666666666667 */
	if (!EQUAL(pi(n), 3.466666666666667)) return STATUS_ERROR;

	n = 1000000; /* pi(1000000) ≈ 3.141591653589793 */
	if (!EQUAL(pi(n), 3.141591653589793)) return STATUS_ERROR;

	return STATUS_OK;
}

/* ==============================
 * Implementacoes
 * ============================== */

/**
 * Retorna uma aproximacao do valor de pi usando a formula de Leibniz.
 *
 * Parametros:
 * int n: O numero de termos a serem usados para calcular a aproximacao de pi.
 *
 * Retorna double:
 * A aproximacao do valor de pi calculada usando n termos da formula de Leibniz
 */
double pi(int n) {
	double pi_approx = 0;
	for (int i = 0; i < n; i++) {
		int term_sign = (i % 2 == 0) ? 1 : -1; /* Alterna entre positivo e negativo */
		int term_denominator = 2 * i + 1; /* O denominador é 1, 3, 5, ... */
		pi_approx += term_sign * (4.0 / term_denominator); /* Adiciona o termo à aproximação de pi */
	}
	return pi_approx;
}
