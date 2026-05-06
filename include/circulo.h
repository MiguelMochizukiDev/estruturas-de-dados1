/**
 * circulo.h
 * Autor: Miguel Mochizuki Silva
 * Descricao:
 * Interface do TAD Circulo, implementado em src/circulo.c
 */
#ifndef CIRCULO_H
#define CIRCULO_H

/* Dependencia de modulos */
#include "ponto.h"

/* Tipo exportado */
typedef struct circulo_t Circulo;

/* Funcoes exportadas */

/**
 * Aloca e retorna um circulo no plano cartesiano, com centro em (x, y) e raio r
 *
 * Parametros:
 * double x: abcissa do centro do circulo
 * double y: ordenada do centro do circulo
 * double r: raio do circulo
 *
 * Retorna Circulo*: circulo com centro em (x, y) e raio r; NULL se memoria insuficiente
 */
Circulo* circulo_cria(double x, double y, double r);

/**
 * Libera a memoria de um circulo previamente criado
 *
 * Parametros:
 * Circulo* c: ponteiro para um circulo
 *
 * Retorna int: 0 se circulo liberado com sucesso; -1 se ponteiro nulo
 */
int circulo_libera(Circulo *c);

/**
 * Retorna os valores do centro e do raio de um circulo
 *
 * Parametros:
 * Circulo* c: ponteiro para um circulo
 * double* x: armazena abcissa do centro do circulo
 * double* y: armazena ordenada do centro do circulo
 * double* r: armazena o raio do circulo
 *
 * Retorna int: 0 se atributos acessados com sucesso; -1 se ponteiro nulo
 */
int circulo_acessa(Circulo* c, double* x, double* y, double* r);

/**
 * Atribui novos valores as coordenadas do centro e ao raio de um circulo
 *
 * Parametros:
 * Circulo* c: ponteiro para um circulo
 * double x: nova abcissa do centro do circulo
 * double y: nova ordenada do centro do circulo
 * double r: novo raio do circulo
 *
 * Retorna int: 0 se atributos atribuidos com sucesso; -1 se ponteiro nulo
 */
int circulo_atribui(Circulo* c, double x, double y, double r);

/**
 * Retorna a area de um circulo
 *
 * Parametros:
 * Circulo* c: ponteiro para um circulo
 * double* area: armazena a area do circulo
 *
 * Retorna int: 0 se area acessada com sucesso; -1 se ponteiro nulo
 */
int circulo_area(Circulo* c, double* area);

/**
 * Retorna se um ponto pertence a um circulo
 *
 * Parametros:
 * Circulo* c: ponteiro para um circulo
 * Ponto* p: ponteiro para um ponto
 *
 * Retorna int: 1 se o ponto pertence ao circulo, 0 se nao, -1 se ponteiro nulo
 */
int circulo_pertence(Circulo* c, Ponto* p);

#endif
