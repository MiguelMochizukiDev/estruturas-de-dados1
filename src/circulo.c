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
	if (c == NULL) {
		printf("Memoria insuficiente!\n");
		exit(1);
	}

	c->centro = ponto_cria(x, y);
	c->raio = r;

	return c;
}

void circulo_libera(Circulo* c) {
	ponto_libera(c->centro);
	free(c);
}

void circulo_acessa(Circulo* c, double* x, double* y, double* r) {
	ponto_acessa(c->centro, x, y);
	*r = c->raio;
}

void circulo_atribui(Circulo* c, double x, double y, double r) {
	ponto_atribui(c->centro, x, y);
	c->raio = r;
}

double circulo_area(Circulo* c) {
	return PI * c->raio * c->raio;
}

int circulo_pertence(Circulo* c, Ponto* p) {
	double distancia;
	ponto_distancia(c->centro, p, &distancia);
	return distancia <= c->raio;
}
