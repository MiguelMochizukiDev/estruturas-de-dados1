/**
 * exercicio1.2.c
 * Autor: Miguel Mochizuki Silva
 * Descricao:
 * Implemente uma funcao para testar se um numero e primo ou nao.
 * Essa funcao deve obedecer ao prototipo a seguir e ter como valor
 * de retorno 1 se n for primo e 0 caso contrario.
 * 	int primo(int n);
 */
#include <stdio.h>

#define STATUS_OK 0 /* Status code for OK in main */
#define STATUS_ERROR 1 /* Status code for error in main */

/* ==============================
 * Funcoes
 * ============================== */

int primo(int);

/* ==============================
 * Main
 * ============================== */

/**
 * Testa codigo em alguns casos de uso
 */
int main(void) {
	/* Numero a ser testado */
	int n;

	n = 0; /* Nao primo */
	if (primo(n)) return STATUS_ERROR;

	n = -5; /* Primo: o sinal negativo nao influencia na primalidade */
	if (!primo(n)) return STATUS_ERROR;

	n = 1; /* Nao primo: por definicao, o numero 1 nao e primo */
	if (primo(n)) return STATUS_ERROR;

	n = 2; /* Primo: o menor numero primo */
	if (!primo(n)) return STATUS_ERROR;

	n = 3; /* Primo */
	if (!primo(n)) return STATUS_ERROR;

	n = 4; /* Nao primo: divisivel por 2 */
	if (primo(n)) return STATUS_ERROR;

	n = 5; /* Primo */
	if (!primo(n)) return STATUS_ERROR;

	n = 6; /* Nao primo: divisivel por 2 e por 3 */
	if (primo(n)) return STATUS_ERROR;

	n = 7; /* Primo */
	if (!primo(n)) return STATUS_ERROR;

	n = 8; /* Nao primo: divisivel por 2 */
	if (primo(n)) return STATUS_ERROR;

	n = 9; /* Nao primo: divisivel por 3 */
	if (primo(n)) return STATUS_ERROR;

	n = 10; /* Nao primo: divisivel por 2 e por 5 */
	if (primo(n)) return STATUS_ERROR;

	return STATUS_OK;
}

/* ==============================
 * Implementacoes
 * ============================== */

/**
 * Decide se o numero n e primo ou nao.
 *
 * Parametros:
 * int n: numero a ser testado
 *
 * Retorna int:
 * 1, se n for primo
 * 0, caso contrario
 */
int primo(int n) {
	if (n == 0) return 0;
	if (n < 0) return primo(-n);

	if (n == 1) return 0;
	if (n == 2 || n == 3) return 1;
	if (n % 6 != 1 && n % 6 != 5) return 0; /* Se n nao for da forma 6k+1 ou 6k+5 então nao e primo */

	/* Testa apenas sobre primos plausiveis */
	for (int i = 5; i * i <= n; i += 6) {
		if (n % i == 0 || n % (i + 2) == 0) return 0; /* i = 6k+5, i + 2 = 6k+1 para algum k */
	}
	return 1;
}
