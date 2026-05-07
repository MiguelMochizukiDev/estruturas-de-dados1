/**
 * status.h
 * Autor: Miguel Mochizuki Silva
 * Descricao:
 * Codigos padronizados de retorno da API
 */
#ifndef STATUS_H
#define STATUS_H

/* ==============================
 * Tipos
 * ============================== */

typedef enum status_t {
    /* SUCESSO */
    STATUS_OK = 0,

    /* FALHAS GERAIS */
    STATUS_ERR_MEMORIA,		/* Memoria insuficiente */
    STATUS_ERR_PARAMETRO,	/* Parametro invalido */
    STATUS_ERR_NULL,		/* Ponteiro nulo */
    STATUS_ERR_ESTADO,		/* Estado invalido */
    STATUS_ERR_VALOR,		/* Valor invalido */
    STATUS_ERR_INDEX,		/* Indice invalido */
} Status;

#endif
