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
 * double x: abcissa do ponto
 * double y: ordenada do ponto
 */
struct ponto_t {
	double x;
	double y;
};

Ponto* ponto_cria(double x, double y) {
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

void ponto_acessa(Ponto* p, double* x, double* y) {
	*x = p->x;
	*y = p->y;
}

void ponto_atribui(Ponto* p, double x, double y) {
	p->x = x;
	p->y = y;
}

double ponto_distancia(Ponto* p1, Ponto* p2) {
	double dx = p2->x - p1->x;
	double dy = p2->y - p1->y;
	return sqrt(dx*dx + dy*dy);
}

