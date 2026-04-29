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

int main(void) {
	int n;
	int is_primo;

	/* Alguns casos de teste */
	n = 0; /* Nao primo */
	is_primo = primo(n);
	printf("CASO 1: %s\n", (is_primo == 0) ? "CERTO" : "ERRO");

	n = -5; /* Primo: o sinal negativo nao influencia na primalidade */
	is_primo = primo(n);
	printf("CASO 2: %s\n", (is_primo == 1) ? "CERTO" : "ERRO");

	n = 1; /* Nao primo: por definicao, o numero 1 nao e primo */
	is_primo = primo(n);
	printf("CASO 3: %s\n", (is_primo == 0) ? "CERTO" : "ERRO");

	n = 2; /* Primo: o menor numero primo */
	is_primo = primo(n);
	printf("CASO 4: %s\n", (is_primo == 1) ? "CERTO" : "ERRO");

	n = 3; /* Primo */
	is_primo = primo(n);
	printf("CASO 5: %s\n", (is_primo == 1) ? "CERTO" : "ERRO");

	n = 4; /* Nao primo: divisivel por 2 */
	is_primo = primo(n);
	printf("CASO 6: %s\n", (is_primo == 0) ? "CERTO" : "ERRO");

	n = 5; /* Primo */
	is_primo = primo(n);
	printf("CASO 7: %s\n", (is_primo == 1) ? "CERTO" : "ERRO");

	n = 6; /* Nao primo: divisivel por 2 e por 3 */
	is_primo = primo(n);
	printf("CASO 8: %s\n", (is_primo == 0) ? "CERTO" : "ERRO");

	n = 7; /* Primo */
	is_primo = primo(n);
	printf("CASO 9: %s\n", (is_primo == 1) ? "CERTO" : "ERRO");

	n = 8; /* Nao primo: divisivel por 2 */
	is_primo = primo(n);
	printf("CASO 10: %s\n", (is_primo == 0) ? "CERTO" : "ERRO");

	n = 9; /* Nao primo: divisivel por 3 */
	is_primo = primo(n);
	printf("CASO 11: %s\n", (is_primo == 0) ? "CERTO" : "ERRO");

	n = 10; /* Nao primo: divisivel por 2 e por 5 */
	is_primo = primo(n);
	printf("CASO 12: %s\n", (is_primo == 0) ? "CERTO" : "ERRO");

	return 0;
}
