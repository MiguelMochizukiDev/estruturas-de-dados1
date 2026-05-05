/**
 * exercicio_vetores04.c
 * Autor: Miguel Mochizuki Silva
 * Descricao:
 * Implemente uma funcao que permita a avaliacao de polinomios.
 * Cada polinomio e definido como um vetor que contem os seus coeficientes.
 * Por exemplo, o polinomio de grau 2, 3x^2 + 2x + 12, tera um vetor de coeficientes
 * igual a v[] = {12, 2, 3}. A funcao devera obedecer ao seguinte prototipo:
 * 	double avalia(double* poli, int grau, double x);
 * Onde poli e o vetor com os coeficientes do polinomio,
 * grau e o grau do polinomio, e x e o valor para o qual o polinomio deve ser avaliado.
 * (Retirado de Celes, pag. 116, exercicio 3.4)
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define EPSILON 1e-9 /* Tolerancia para comparacoes de pontos flutuantes */
#define EQUAL(a, b) (((a) - (b) < EPSILON) && ((b) - (a) < EPSILON)) /* Comparacao de pontos flutuantes */

/* ==============================
 * Funcoes
 * ============================== */

double avalia(double* poli, int grau, double x);

/* ==============================
 * MAIN
 * ============================== */

/**
 * Funcao principal do programa. Testa a funcao avalia() com um polinomio de grau 2.
 *
 * Retorna int: EXIT_SUCCESS (0) se sucesso; senao EXIT_FAILURE (1).
 */
int main(void) {
	double poli[] = {12, 2, 3}; /* Coeficientes do polinomio 3x^2 + 2x + 12 */
	int grau = sizeof(poli) / sizeof(poli[0]) - 1; /* Grau do polinomio */
	double x = 1.0; /* Valor para o qual o polinomio deve ser avaliado */

	double resultado = avalia(poli, grau, x); /* Avalia o polinomio */

	if (!(EQUAL(resultado, 17.0))) return EXIT_FAILURE; /* Verifica se o resultado esta correto */

	return EXIT_SUCCESS; /* Retorna sucesso */
}

/* ==============================
 * Implementacoes
 * ============================== */

/**
 * Calcula a avaliacao de um polinomio representado por um vetor de coeficientes em um ponto x.
 *
 * Parametros:
 * double* poli: Vetor de coeficientes do polinomio, onde poli[i] e o coeficiente de x^i.
 * int grau: Grau do polinomio (numero de coeficientes - 1).
 * double x: Valor para o qual o polinomio deve ser avaliado.
 *
 * Retorna double: Resultado da avaliacao do polinomio em x.
 */
double avalia(double* poli, int grau, double x) {
	double resultado = 0.0; /* Variavel para armazenar o resultado da avaliacao */

	for (int i = 0; i <= grau; i++) {
		resultado += poli[i] * pow(x, i);
	}

	return resultado; /* Retorna o resultado da avaliacao */
}
