/**
 * exercicio_vetores03.c
 * Autor: Miguel Mochizuki Silva
 * Descricao:
 * Implemente uma funcao que receba como parametro um vetor de numeros
 * inteiros (vet) de tamanho n e inverta a ordem dos elementos
 * armazenados nesse vetor. Essa funcao deve obedecer
 * ao prototipo:
 * 	void inverte(int n, int* vet);
 * (Retirado de Celes, pag. 116, exercicio 3.3)
 */
#include <stdio.h>
#include <stdlib.h>

/* ==============================
 * Funcoes
 * ============================== */

void inverte(int n, int* vet);

/* ==============================
 * MAIN
 * ============================== */

/**
 * Funcao principal do programa. Testa a funcao
 * inverte() com um vetor de exemplo.
 *
 * Retorna int: EXIT_SUCCESS (0) se sucesso; senao EXIT_FAILURE (1).
 */
int main(void) {
	int n = 5; /* Tamanho do vetor */
	int vet[] = {1, 2, 3, 4, 5}; /* Vetor de exemplo */

	inverte(n, vet); /* Inverte o vetor */

	/* Verifica se o vetor foi invertido corretamente */
	for (int i = 0; i < n; i++) {
		if (vet[i] != (5 - i)) return EXIT_FAILURE;
	}

	return EXIT_SUCCESS; /* Teste passou */
}

/* ==============================
 * Implementacoes
 * ============================== */

/**
 * Inverte a ordem dos elementos de um vetor de inteiros.
 *
 * Parametros:
 * int n: Tamanho do vetor.
 * int* vet: Ponteiro para o vetor de inteiros a ser invertido.
 */
void inverte(int n, int* vet) {
	for (int i = 0; i < n / 2; i++) {
		int temp = vet[i];
		vet[i] = vet[n - 1 - i];
		vet[n - 1 - i] = temp;
	}
}


