/**
 * ponto.c
 * Autor: Miguel Mochizuki Silva
 * Descricao:
 * Implementa interface do TAD Ponto, conforme include/ponto.h
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "ponto.h"

/* ==============================
 * Implementacoes
 * ============================== */

/**
 * Estrutura para ponto
 *
 * Atributos:
 * float x: abcissa do ponto
 * float y: ordenada do ponto
 */
struct ponto_t {
	float x;
	float y;
};

Ponto* ponto_cria(float x, float y) {
	Ponto* p = (Ponto*)malloc(sizeof(Ponto));
	if (p == NULL) {
		printf("Memoria insuficiente!\n");
		exit(1);
	}

	p->x = x;
	p->y = y;

	return p;
}

void ponto_libera(Ponto* p) {
	free(p);
}

void ponto_acessa(Ponto* p, float* x, float* y) {
	*x = p->x;
	*y = p->y;
}

void ponto_atribui(Ponto* p, float x, float y) {
	p->x = x;
	p->y = y;
}

float ponto_distancia(Ponto* p1, Ponto* p2) {
	float dx = p2->x - p1->x;
	float dy = p2->y - p2->y;
	return sqrt(dx*dx + dy*dy);
}

