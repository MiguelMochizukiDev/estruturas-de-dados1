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
 * float x: abcissa do ponto
 * float y: ordenada do ponto
 *
 * Retorna Ponto*: ponto com coordenadas (x, y)
 */
Ponto* ponto_cria(float x, float y);

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
 * float* x: armazena abcissa do ponto
 * float* y: armazena ordenada do ponto
 */
void ponto_acessa(Ponto* p, float* x, float* y);

/**
 * Atribui novos valores as coordenadas de um ponto
 *
 * Parametros:
 * Ponto* p: ponteiro para um ponto
 * float x: nova abcissa do ponto
 * float y: nova ordenada do ponto
 */
void ponto_atribui(Ponto* p, float x, float y);

/**
 * Retorna a distancia entre dois pontos
 *
 * Parametros:
 * Ponto* p1: ponteiro para um ponto
 * Ponto* p2: ponteiro para um ponto
 *
 * Retorna float: a distancia entre os pontos
 */
float ponto_distancia(Ponto* p1, Ponto* p2);

#endif
