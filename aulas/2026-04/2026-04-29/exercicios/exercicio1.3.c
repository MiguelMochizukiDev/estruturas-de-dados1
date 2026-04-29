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

#define MAX_N 46

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
	if (n <= 0) return 0;
	if (n == 1 || n == 2) return 1;

	int fib_n_minus_2 = 1, fib_n_minus_1 = 1;
	int fib_n = 0;
	for (int i = 3; i <= n; i++) {
		fib_n = fib_n_minus_1 + fib_n_minus_2;
		fib_n_minus_2 = fib_n_minus_1;
		fib_n_minus_1 = fib_n;
	}
	return fib_n;
}

int main(void) {
	int n;
	int fib_n;

	/* Alguns casos de teste */
	n = 1; /* Fibonacci(1) = 1 */
	fib_n = fibonacci(n);
	printf("CASO 1: %s\n", (fib_n == 1) ? "CERTO" : "ERRO");

	n = 2; /* Fibonacci(2) = 1 */
	fib_n = fibonacci(n);
	printf("CASO 2: %s\n", (fib_n == 1) ? "CERTO" : "ERRO");

	n = 3; /* Fibonacci(3) = 2 */
	fib_n = fibonacci(n);
	printf("CASO 3: %s\n", (fib_n == 2) ? "CERTO" : "ERRO");

	n = 10; /* Fibonacci(10) = 55 */
	fib_n = fibonacci(n);
	printf("CASO 4: %s\n", (fib_n == 55) ? "CERTO" : "ERRO");

	n = MAX_N; /* Fibonacci(MAX_N) = 1836311903 */
	fib_n = fibonacci(n);
	printf("CASO 5: %s\n", (fib_n == 1836311903) ? "CERTO" : "ERRO");
	return 0;
}
