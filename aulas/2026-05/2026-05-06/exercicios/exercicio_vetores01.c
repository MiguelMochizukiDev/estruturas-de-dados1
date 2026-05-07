/**
 * exercicio_vetores01.c
 * Autor: Miguel Mochizuki Silva
 * Descricao:
 * Implemente uma funcao que receba como parametro um vetor de numeros
 * reais (vet) de tamanho n e retorne quantos numeros negativos
 * estao armazenados nesse vetor. Essa funcao deve obedecer
 * ao seguinte prototipo:
 * 	int negativos(int n, float* vet);
 * (Retirado de Celes, pag. 115, exercicio 3.1)
 */
#include <stdio.h>
#include <stdlib.h>

/* ==============================
 * Funcoes
 * ============================== */

int negativos(int n, float* vet);

/* ==============================
 * MAIN
 * ============================== */

/**
 * Funcao principal do programa. Testa a funcao
 * negativos() com um vetor de exemplo.
 *
 * Retorna int: EXIT_SUCCESS (0) se sucesso; senao EXIT_FAILURE (1).
 */
int main(void) {
	int n = 5; /* Tamanho do vetor */
	float vet[] = {-1.5, 2.0, -3.0, 4.5, -5.0}; /* Vetor de exemplo */

	if (negativos(n, vet) != 3) return EXIT_FAILURE; /* Teste falhou */

	return EXIT_SUCCESS; /* Teste passou */
}

/* ==============================
 * Implementacoes
 * ============================== */

/**
 * Funcao que conta quantos numeros negativos estao armazenados
 * em um vetor de numeros reais.
 *
 * Parametros:
 * int n: Tamanho do vetor.
 * float* vet: Ponteiro para o vetor de numeros reais.
 *
 * Retorna int: Quantidade de numeros negativos no vetor.
 */
int negativos(int n, float* vet) {
	int count = 0;
	for (int i = 0; i < n; i++) {
		if (vet[i] < 0) {
			count++;
		}
	}
	return count;
}
