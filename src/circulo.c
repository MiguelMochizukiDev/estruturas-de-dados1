/**
 * circulo.c
 * Autor: Miguel Mochizuki Silva
 * Descricao:
 * Implementa interface do TAD Circulo, conforme include/circulo.h
 */
#include <stdlib.h>
#include "circulo.h"

/* ==============================
 * Defines
 * ============================== */

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

Status circulo_libera(Circulo* c) {
	if (c == NULL) return STATUS_ERR_NULL;

	ponto_libera(c->centro);
	free(c);
	return STATUS_OK;
}

Status circulo_acessa(Circulo* c, double* x, double* y, double* r) {
	if (c == NULL || x == NULL || y == NULL || r == NULL) return STATUS_ERR_NULL;

	ponto_acessa(c->centro, x, y);
	*r = c->raio;
	return STATUS_OK;
}


Status circulo_atribui(Circulo* c, double x, double y, double r) {
	if (c == NULL) return STATUS_ERR_NULL;
	if (r < 0) return STATUS_ERR_VALOR;

	ponto_atribui(c->centro, x, y);
	c->raio = r;
	return STATUS_OK;
}

Status circulo_area(Circulo* c, double* area) {
	if (c == NULL || area == NULL) return STATUS_ERR_NULL;

	*area = PI * c->raio * c->raio;
	return STATUS_OK;
}

Status circulo_pertence(Circulo* c, Ponto* p, int* pertence) {
	if (c == NULL || p == NULL || pertence == NULL) return STATUS_ERR_NULL;

	double distancia;
	ponto_distancia(c->centro, p, &distancia);
	*pertence = (distancia <= c->raio) ? 1 : 0;
	return STATUS_OK;
}
