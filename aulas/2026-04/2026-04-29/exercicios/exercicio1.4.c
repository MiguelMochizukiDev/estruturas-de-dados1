/**
 * exercicio1.4.c
 * Autor: Miguel Mochizuki Silva
 * Descricao:
 * Implemente uma funcao que retorne a soma dos n primeiros numeros naturais impares.
 * Essa funcao deve obedecer ao prototipo:
 * 	int soma_impares(int n);
 */
#include <stdio.h>

/**
 * Retorna a soma dos n primeiros numeros naturais impares.
 *
 * Parametros:
 * int n: O numero de termos a serem somados (1-based).
 *
 * Retorna int:
 * A soma dos n primeiros numeros naturais impares.
 */
int soma_impares(int n) {
	return n * n;
}

int main(void) {
	int n;
	int soma;

	/* Alguns casos de teste */
	n = 1; /* Soma dos 1 primeiros impares = 1 */
	soma = soma_impares(n);
	printf("CASO 1: %s\n", (soma == 1) ? "CERTO" : "ERRO");

	n = 2; /* Soma dos 2 primeiros impares = 1 + 3 = 4 */
	soma = soma_impares(n);
	printf("CASO 2: %s\n", (soma == 4) ? "CERTO" : "ERRO");

	n = 3; /* Soma dos 3 primeiros impares = 1 + 3 + 5 = 9 */
	soma = soma_impares(n);
	printf("CASO 3: %s\n", (soma == 9) ? "CERTO" : "ERRO");

	n = 5; /* Soma dos 5 primeiros impares = 1 + 3 + 5 + 7 + 9 = 25 */
	soma = soma_impares(n);
	printf("CASO 4: %s\n", (soma == 25) ? "CERTO" : "ERRO");

	n = 50; /* Soma dos 50 primeiros impares = 1 + 3 + ... + 99 = 2500 */
	soma = soma_impares(n);
	printf("CASO 5: %s\n", (soma == 2500) ? "CERTO" : "ERRO");

	return 0;
}
