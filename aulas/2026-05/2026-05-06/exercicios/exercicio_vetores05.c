/**
 * exercicio_vetores05.c
 * Autor: Miguel Mochizuki Silva
 * Descricao:
 * Implemente uma funcao que calcule a derivada
 * de um polinomio. Cada polinomio e representado como
 * exemplificado no exercicio anterior. A funcao deve obedecer
 * ao prototipo:
 *	void deriva(double* poli, int grau, double* out);
 * onde out e o vetor, de dimensao grau - 1, no qual a funcao
 * deve guardar os coeficientes do polinomio resultante da derivada
 * (Retirado de Celes, pag. 116, exercicio 3.5)
 */
#include <stdio.h>
#include <stdlib.h>

#define EPSILON 1e-9 /* Tolerancia para comparacoes de pontos flutuantes */
#define EQUAL(a, b) ((((a) - (b) < EPSILON) && ((b) - (a) < EPSILON))) /* Comparacao de pontos flutuantes */

/* ==============================
 * Funcoes
 * ============================== */

void deriva(double* poli, int grau, double* out);

/* ==============================
 * MAIN
 * ============================== */

/**
 * Funcao principal do programa. Testa a funcao deriva() com um polinomio de grau 3.
 *
 * Retorna int: EXIT_SUCCESS (0) se sucesso; senao EXIT_FAILURE (1).
 */
int main(void) {
	double poli[] = {5, 4, 3, 2}; /* Coeficientes do polinomio 2x^3 + 3x^2 + 4x + 5 */
	double out[3]; /* Vetor para armazenar os coeficientes da derivada */
	double expected[] = {4, 6, 6}; /* Coeficientes esperados da derivada: 6x^2 + 6x + 4 */
	int grau = sizeof(poli) / sizeof(poli[0]) - 1; /* Grau do polinomio */

	deriva(poli, grau, out); /* Calcula a derivada do polinomio */

	/* Verifica se os coeficientes da derivada estao corretos */
	for (int i = 0; i <= grau - 1; i++) {
		if (!EQUAL(out[i], expected[i])) return EXIT_FAILURE;
	}

	return EXIT_SUCCESS; /* Retorna sucesso */
}

/* ==============================
 * Implementacoes
 * ============================== */

/**
 * Calcula a derivada de um polinomio representado por um vetor de coeficientes.
 *
 * Parametros:
 * double* poli: Vetor de coeficientes do polinomio, onde poli[i] e o coeficiente de x^i.
 * int grau: Grau do polinomio (numero de coeficientes - 1).
 * double* out: Vetor de saida onde serao armazenados os coeficientes da derivada, de dimensao grau - 1.
 */
void deriva(double* poli, int grau, double* out) {
	for (int i = 1; i <= grau; i++) {
		out[i - 1] = poli[i] * i;
	}
}
