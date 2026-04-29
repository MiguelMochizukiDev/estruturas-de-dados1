/**
 * exercicio2.2.c
 * Autor: Miguel Mochizuki Silva
 * Descricao:
 * Implemente uma funcao que calcule a area da superficie e o volume de uma esfera
 * de raio r. Essa funcao deve satisfazer ao prototipo:
 * 	void calc_esfera(float r, float *area, float *volume);
 * A area da superficie e o volume sao dados, respectivamente, por 4r^2 e 4r^3/3.
 */
#include <stdio.h>

#define STATUS_OK 0 /* Status code for OK in main */
#define STATUS_ERROR 1 /* Status code for error in main */

#define EPSILON 1e-5 /* Constante para comparar numeros de ponto flutuante, considerando uma margem de erro pequena */
#define EQUAL(a, b) ( ((a) - (b)) < EPSILON && ((b) - (a)) < EPSILON ) /* Macro para comparar numeros de ponto flutuante, considerando uma margem de erro pequena */

/* ==============================
 * Funcoes
 * ============================== */

void calc_esfera(float, float*, float*);

/* ==============================
 * Main
 * ============================== */

/**
 * Testa codigo em alguns casos de uso
 */
int main(void) {
	/* Variavel para armazenar raio da circunferencia */
	int r;

	/* Variavel para armazenar area e volume da circunferencia */
	float area, volume;

	r = 1; /* area = 4.0, volume = 4.0/3.0 */
	calc_esfera(r, &area, &volume);
	if (!EQUAL(area, 4.0) || !EQUAL(volume, 4.0 / 3.0)) return STATUS_ERROR;

	r = 2; /* area = 16.0, volume = 32.0/3.0 */
	calc_esfera(r, &area, &volume);
	if (!EQUAL(area, 16.0) || !EQUAL(volume, 32.0 / 3.0)) return STATUS_ERROR;

	r = 0; /* area = 0.0, volume = 0.0 */
	calc_esfera(r, &area, &volume);
	if (!EQUAL(area, 0.0) || !EQUAL(volume, 0.0)) return STATUS_ERROR;

	return STATUS_OK;
}

/* ==============================
 * Implementacoes
 * ============================== */

/**
 * Calcula a area da superficie e o volume de uma esfera de raio r.
 *
 * Parametros:
 * float r: o raio da esfera
 * float *area: ponteiro para armazenar a area da superficie da esfera
 * float *volume: ponteiro para armazenar o volume da esfera
 *
 * Retorna void:
 * A area da superficie e o volume da esfera sao armazenados nas variaveis apontadas
 */
void calc_esfera(float r, float *area, float *volume) {
	*area = 4 * r * r; /* Area da superficie: 4r^2 */
	*volume = (4.0 / 3.0) * r * r * r; /* Volume: 4r^3/3 */
}
