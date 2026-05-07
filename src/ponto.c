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
#include "status.h"

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

Status ponto_libera(Ponto* p) {
	if (p == NULL) {
		return STATUS_ERR_NULL;
	}

	free(p);
	return STATUS_OK;
}

Status ponto_acessa(Ponto* p, double* x, double* y) {
	if (p == NULL || x == NULL || y == NULL) {
		return STATUS_ERR_NULL;
	}

	*x = p->x;
	*y = p->y;
	return STATUS_OK;
}

Status ponto_atribui(Ponto* p, double x, double y) {
	if (p == NULL) {
		return STATUS_ERR_NULL;
	}
	
	p->x = x;
	p->y = y;
	return STATUS_OK;
}

Status ponto_distancia(Ponto* p1, Ponto* p2, double* distancia) {
	if (p1 == NULL || p2 == NULL || distancia == NULL) {
		return STATUS_ERR_NULL;
	}

	double dx = p2->x - p1->x;
	double dy = p2->y - p1->y;
	*distancia = sqrt(dx*dx + dy*dy);
	return STATUS_OK;
}

