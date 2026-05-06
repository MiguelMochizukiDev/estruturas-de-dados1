/**
 * ponto.h
 * Autor: Miguel Mochizuki Silva
 * Descricao:
 * Interface do TAD Ponto, implementado em src/ponto.c
 */
#ifndef PONTO_H
#define PONTO_H

/* Tipo exportado */
typedef struct ponto_t Ponto;

/* Funcoes exportadas */

/**
 * Aloca e retorna um ponto no plano cartesiano, com coordenadas (x, y)
 *
 * Parametros:
 * double x: abcissa do ponto
 * double y: ordenada do ponto
 *
 * Retorna Ponto*: ponto com coordenadas (x, y)
 */
Ponto* ponto_cria(double x, double y);

/**
 * Libera a memoria de um ponto previamente criado
 *
 * Parametros:
 * Ponto* p: ponteiro para um ponto
 */
void ponto_libera(Ponto *p);

/**
 * Retorna os valores das coordenadas de um ponto
 *
 * Parametros:
 * Ponto* p: ponteiro para um ponto
 * double* x: armazena abcissa do ponto
 * double* y: armazena ordenada do ponto
 */
void ponto_acessa(Ponto* p, double* x, double* y);

/**
 * Atribui novos valores as coordenadas de um ponto
 *
 * Parametros:
 * Ponto* p: ponteiro para um ponto
 * double x: nova abcissa do ponto
 * double y: nova ordenada do ponto
 */
void ponto_atribui(Ponto* p, double x, double y);

/**
 * Retorna a distancia entre dois pontos
 *
 * Parametros:
 * Ponto* p1: ponteiro para um ponto
 * Ponto* p2: ponteiro para um ponto
 *
 * Retorna double: a distancia entre os pontos
 */
double ponto_distancia(Ponto* p1, Ponto* p2);

#endif
