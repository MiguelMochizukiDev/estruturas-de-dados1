/**
 * circulo.c
 * Autor: Miguel Mochizuki Silva
 * Descricao:
 * Implementa interface do TAD Circulo, conforme include/circulo.h
 */
#include <stdio.h>
#include <stdlib.h>
#include "circulo.h"

#define PI 3.1415926535 /* Pi ate a decima casa decimal */

/* ==============================
 * Implementacoes
 * ============================== */

/**
 * Estrutura para circulo
 *
 * Atributos:
 * Ponto* centro: ponteiro para o centro do circulo
 * double raio: raio do circulo
 */
struct circulo_t {
	Ponto* centro;
	double raio;
};

Circulo* circulo_cria(double x, double y, double r) {
	Circulo* c = (Circulo*)malloc(sizeof(Circulo));
	if (c == NULL) return NULL;

	c->centro = ponto_cria(x, y);
	if (c->centro == NULL) {
		circulo_libera(c);
		return NULL;
	}

	c->raio = r;

	return c;
}

int circulo_libera(Circulo* c) {
	if (c == NULL) return -1;

	ponto_libera(c->centro);
	free(c);
	return 0;
}

int circulo_acessa(Circulo* c, double* x, double* y, double* r) {
	if (c == NULL || x == NULL || y == NULL || r == NULL) return -1;

	ponto_acessa(c->centro, x, y);
	*r = c->raio;
	return 0;
}


int circulo_atribui(Circulo* c, double x, double y, double r) {
	if (c == NULL) return -1;

	ponto_atribui(c->centro, x, y);
	c->raio = r;
	return 0;
}

int circulo_area(Circulo* c, double* area) {
	if (c == NULL || area == NULL) return -1;

	*area = PI * c->raio * c->raio;
	return 0;
}

int circulo_pertence(Circulo* c, Ponto* p) {
	if (c == NULL || p == NULL) return -1;

	double distancia;
	ponto_distancia(c->centro, p, &distancia);
	return distancia <= c->raio;
}
