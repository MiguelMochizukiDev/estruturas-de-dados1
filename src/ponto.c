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
	if (p == NULL) return NULL;

	p->x = x;
	p->y = y;

	return p;
}

int ponto_libera(Ponto* p) {
	if (p == NULL) {
		return -1;
	}
	free(p);
	return 0;
}

int ponto_acessa(Ponto* p, double* x, double* y) {
	if (p == NULL || x == NULL || y == NULL) {
		return -1;
	}
	*x = p->x;
	*y = p->y;
	return 0;
}

int ponto_atribui(Ponto* p, double x, double y) {
	if (p == NULL) {
		return -1;
	}
	p->x = x;
	p->y = y;
	return 0;
}

int ponto_distancia(Ponto* p1, Ponto* p2, double* distancia) {
	if (p1 == NULL || p2 == NULL || distancia == NULL) {
		return -1;
	}
	
	double dx = p2->x - p1->x;
	double dy = p2->y - p1->y;
	*distancia = sqrt(dx*dx + dy*dy);
	return 0;
}

