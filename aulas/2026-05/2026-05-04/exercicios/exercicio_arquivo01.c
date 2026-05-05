/**
 * exercicio_arquivo01.c
 * Autor: Miguel Mochizuki Silva
 * Descricao:
 * Abrir, imprimir na saida padrao e fechar arquivo
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* ==============================
 * MAIN
 * ============================ */

/**
 * Codigo principal
 *
 * Parametros:
 * int argc: numero de argumentos
 * char** argv: nomes dos arquivos
 *
 * Retorna int: EXIT_SUCCESS (0) se sucesso; senao EXIT_FAILURE(1)
 */
int main(int argc, char** argv) {
	if (argc == 1) {
		fprintf(stderr, "Erro: sem argumentos.\n"
				"    Uso: %s filename_1 filename_2...\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	for (int i = 1; i < argc; i++) {
		if (strcmp(argv[i],"--help") == 0 || strcmp(argv[i],"-h") == 0) {
			const char help_msg[] =
				"Comando inspirado no cat UNIX que concatena arquivos"
				"e imprime na saida padrao.";

			fprintf(stdout, "%s\n", help_msg);
			fprintf(stdout, "    Uso: %s filename_1 filename_2...\n", argv[0]);
			return EXIT_SUCCESS;
		}
	}


	for (int i = 1; i < argc; i++) {
		FILE* fp = fopen(argv[i], "r");
		if (fp == NULL) {
			fprintf(stderr, "Erro ao abrir %s.\n", argv[i]);
			exit(EXIT_FAILURE);
		}

		int ch; /* Variavel para armazenar char */
		while ((ch = getc(fp)) != EOF) {
			putchar(ch);
		}

		fclose(fp);
	}

	return EXIT_SUCCESS;
}
