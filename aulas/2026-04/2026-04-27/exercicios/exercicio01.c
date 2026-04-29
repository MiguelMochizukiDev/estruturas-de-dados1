/**
 * exercicio01.c
 * Autor: Miguel Mochizuki Silva
 * Descricao: com uma unica variavel, imprimir tabela ASCII
 */
#include <stdio.h>
#include <ctype.h>

int main(void) {
	for (unsigned char i = 0; i < 255; i++) { /* ASCII SAO 256 CARACTERES, NAO 127 */
		if (isprint(i)) {
			printf("%d\t%c\t", i, i); /* Print only if printable */
		} else {
			printf("%d\tNP\t", i);
		}

		if (i % 8 == 7) {
			printf("\n");
		}
	}
	printf("255\tNP\t\n"); /* Limite de char e 255, por isso interrompemos em 254 e terminamos aqui */
	printf("\nNP: Not Printable\n");
	return 0;
}
