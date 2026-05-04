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
 * float raio: raio do circulo
 */
struct circulo_t {
	Ponto* centro;
	float raio;
};

Circulo* circulo_cria(float x, float y, float r) {
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

void circulo_acessa(Circulo* c, float* x, float* y, float* r) {
	ponto_acessa(c->centro, x, y);
	*r = c->raio;
}

void circulo_atribui(Circulo* c, float x, float y, float r) {
	ponto_atribui(c->centro, x, y);
	c->raio = r;
}

float circulo_area(Circulo* c) {
	return PI * c->raio * c->raio;
}

int circulo_pertence(Circulo* c, Ponto* p) {
	return ponto_distancia(c->centro, p) <= c->raio;
}
