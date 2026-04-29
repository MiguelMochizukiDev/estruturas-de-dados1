/**
 * exercicio1.4.c
 * Autor: Miguel Mochizuki Silva
 * Descricao:
 * Implemente uma funcao que retorne a soma dos n primeiros numeros naturais impares.
 * Essa funcao deve obedecer ao prototipo:
 * 	int soma_impares(int n);
 */
#include <stdio.h>

#define STATUS_OK 0 /* Status code for OK in main */
#define STATUS_ERROR 1 /* Status code for error in main */

/* ==============================
 * Funcoes
 * ============================== */

int soma_impares(int);

/* ==============================
 * Main
 * ============================== */

/**
 * Testa codigo em alguns casos de uso
 */
int main(void) {
	/* Numero a ser testado */
	int n;

	n = 1; /* Soma dos 1 primeiros impares = 1 */
	if (soma_impares(n) != 1) return STATUS_ERROR;

	n = 2; /* Soma dos 2 primeiros impares = 1 + 3 = 4 */
	if (soma_impares(n) != 4) return STATUS_ERROR;

	n = 3; /* Soma dos 3 primeiros impares = 1 + 3 + 5 = 9 */
	if (soma_impares(n) != 9) return STATUS_ERROR;

	n = 5; /* Soma dos 5 primeiros impares = 1 + 3 + 5 + 7 + 9 = 25 */
	if (soma_impares(n) != 25) return STATUS_ERROR;

	n = 50; /* Soma dos 50 primeiros impares = 1 + 3 + ... + 99 = 2500 */
	if (soma_impares(n) != 2500) return STATUS_ERROR;

	return STATUS_OK;
}

/* ==============================
 * Implementacoes
 * ============================== */

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
