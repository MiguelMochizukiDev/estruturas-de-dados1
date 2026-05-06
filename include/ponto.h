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
 * Retorna Ponto*: ponto com coordenadas (x, y); NULL se memoria insuficiente
 */
Ponto* ponto_cria(double x, double y);

/**
 * Libera a memoria de um ponto previamente criado
 *
 * Parametros:
 * Ponto* p: ponteiro para um ponto
 *
 * Retorna int: 0 se ponto liberado com sucesso; -1 se ponteiro nulo
 */
int ponto_libera(Ponto *p);

/**
 * Retorna os valores das coordenadas de um ponto
 *
 * Parametros:
 * Ponto* p: ponteiro para um ponto
 * double* x: armazena abcissa do ponto
 * double* y: armazena ordenada do ponto
 *
 * Retorna int: 0 se coordenadas acessadas com sucesso; -1 se ponteiro nulo
 */
int ponto_acessa(Ponto* p, double* x, double* y);

/**
 * Atribui novos valores as coordenadas de um ponto
 *
 * Parametros:
 * Ponto* p: ponteiro para um ponto
 * double x: nova abcissa do ponto
 * double y: nova ordenada do ponto
 *
 * Retorna int: 0 se coordenadas atribuidas com sucesso; -1 se ponteiro nulo
 */
int ponto_atribui(Ponto* p, double x, double y);

/**
 * Retorna a distancia entre dois pontos
 *
 * Parametros:
 * Ponto* p1: ponteiro para um ponto
 * Ponto* p2: ponteiro para um ponto
 * double* distancia: armazena a distancia entre os pontos
 *
 * Retorna int: 0 se distancia calculada com sucesso; -1 se ponteiro nulo
 */
int ponto_distancia(Ponto* p1, Ponto* p2, double* distancia);

#endif
