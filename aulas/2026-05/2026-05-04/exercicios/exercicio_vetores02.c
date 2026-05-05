/**
 * exercicio_vetores02.c
 * Autor: Miguel Mochizuki Silva
 * Descricao:
 * Implemente uma funcao que receba como parametro um vetor de numeros
 * inteiros (vet) de tamanho n e retorne quantos numeros pares
 * estao armazenados nesse vetor. Essa funcao deve obedecer
 * ao prototipo:
 * 	int pares(int n, int* vet);
 * (Retirado de Celes, pag. 116, exercicio 3.2)
 */
#include <stdio.h>
#include <stdlib.h>

/* ==============================
 * Funcoes
 * ============================== */

int pares(int n, int* vet);

/* ==============================
 * MAIN
 * ============================== */

/**
 * Funcao principal do programa. Testa a funcao
 * pares() com um vetor de exemplo.
 *
 * Retorna int: EXIT_SUCCESS (0) se sucesso; senao EXIT_FAILURE (1).
 */
int main(void) {
	int n = 5; /* Tamanho do vetor */
	int vet[] = {1, 2, 3, 4, 5}; /* Vetor de exemplo */

	if (pares(n, vet) != 2) return EXIT_FAILURE; /* Teste falhou */

	return EXIT_SUCCESS; /* Teste passou */
}

/* ==============================
 * Implementacoes
 * ============================== */

/**
 * Funcao que conta quantos numeros pares estao armazenados
 * em um vetor de numeros inteiros.
 *
 * Parametros:
 * int n: Tamanho do vetor.
 * int* vet: Ponteiro para o vetor de numeros inteiros.
 *
 * Retorna int: Quantidade de numeros pares no vetor.
 */
int pares(int n, int* vet) {
	int count = 0;

	for (int i = 0; i < n; i++) {
		if ((vet[i] & 1) == 0) {
			count++;
		}
	}

	return count;
}
