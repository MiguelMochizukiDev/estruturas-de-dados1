/**
 * ponto.h
 * Autor: Miguel Mochizuki Silva
 * Descricao:
 * Interface do TAD Ponto, implementado em src/ponto.c
 */
#ifndef PONTO_H
#define PONTO_H

/* ==============================
 * Includes
 * ============================== */

#include "status.h"

/* ==============================
 * Tipos
 * ============================== */

typedef struct ponto_t Ponto;

/* ==============================
 * Funcoes
 * ============================== */

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
 * Retorna Status: STATUS_OK se liberado com sucesso; STATUS_ERR_NULL se ponteiro nulo
 */
Status ponto_libera(Ponto *p);

/**
 * Retorna os valores das coordenadas de um ponto
 *
 * Parametros:
 * Ponto* p: ponteiro para um ponto
 * double* x: armazena abcissa do ponto
 * double* y: armazena ordenada do ponto
 *
 * Retorna Status: STATUS_OK se bem-sucedido; STATUS_ERR_NULL se p, x ou y nulo
 */
Status ponto_acessa(Ponto* p, double* x, double* y);

/**
 * Atribui novos valores as coordenadas de um ponto
 *
 * Parametros:
 * Ponto* p: ponteiro para um ponto
 * double x: nova abcissa do ponto
 * double y: nova ordenada do ponto
 *
 * Retorna Status: STATUS_OK se bem-sucedido; STATUS_ERR_NULL se ponteiro nulo
 */
Status ponto_atribui(Ponto* p, double x, double y);

/**
 * Retorna a distancia entre dois pontos
 *
 * Parametros:
 * Ponto* p1: ponteiro para um ponto
 * Ponto* p2: ponteiro para um ponto
 * double* distancia: armazena a distancia entre os pontos
 *
 * Retorna Status: STATUS_OK se bem-sucedido; STATUS_ERR_NULL se algum ponteiro nulo
 */
Status ponto_distancia(Ponto* p1, Ponto* p2, double* distancia);

#endif
