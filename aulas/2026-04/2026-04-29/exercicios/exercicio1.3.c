/**
 * exercicio1.3.c
 * Autor: Miguel Mochizuki Silva
 * Descricao:
 * Implemente uma funcao que retorne o n-esimo termo da sequencia de Fibonacci.
 * A sequencia de Fibonacci e dada por: 1 1 2 3 5 8 13 21 ..., isto e, os dois
 * primeiros termos sao 1 e cada termo seguinte e a soma dos dois termos anteriores.
 * Essa funcao deve seguir ao prototipo
 * 	int fibonacci(int n);
 */
#include <stdio.h>

#define STATUS_OK 0 /* Status code for OK in main */
#define STATUS_ERROR 1 /* Status code for error in main */

/* ==============================
 * Funcoes
 * ============================== */

int fibonacci(int n);

/* ==============================
 * Main
 * ============================== */

/**
 * Testa codigo em alguns casos de uso
 */
int main(void) {
	/* Numero a ser testado */
	int n;

	n = 1; /* Fibonacci(1) = 1 */
	if (fibonacci(n) != 1) return STATUS_ERROR;

	n = 2; /* Fibonacci(2) = 1 */
	if (fibonacci(n) != 1) return STATUS_ERROR;

	n = 3; /* Fibonacci(3) = 2 */
	if (fibonacci(n) != 2) return STATUS_ERROR;

	n = 10; /* Fibonacci(10) = 55 */
	if (fibonacci(n) != 55) return STATUS_ERROR;

	n = 40; /* Fibonacci(40) = 102334155 */
	if (fibonacci(n) != 102334155) return STATUS_ERROR;

	return STATUS_OK;
}

/* ==============================
 * Implementacoes
 * ============================== */

/**
 * Retorna o n-esimo termo da sequencia de Fibonacci.
 *
 * Parametros:
 * int n: O indice do termo a ser retornado (1-based).
 *
 * Retorna int:
 * O n-esimo termo da sequencia de Fibonacci.
 */
int fibonacci(int n) {
	/* F(n - 1), F(n - 2), F(n) respectivamente */
	int fib_n_minus_1, fib_n_minus_2, fib_n;

	if (n <= 0) return 0;
	if (n == 1 || n == 2) return 1;

	fib_n_minus_2 = 1;
	fib_n_minus_1 = 1;

	for (int i = 3; i <= n; i++) {
		fib_n = fib_n_minus_1 + fib_n_minus_2;
		fib_n_minus_2 = fib_n_minus_1;
		fib_n_minus_1 = fib_n;
	}
	return fib_n;
}
