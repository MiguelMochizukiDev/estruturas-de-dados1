/**
 * exercicio01.c
 * Autor: Miguel Mochizuki Silva
 * Descricao: com uma unica variavel, imprimir tabela ASCII
 */
#include <stdio.h>
#include <ctype.h>

int main(void) {
	for (int i = 0; i <= 127; i++) {
		if (isprint((unsigned char)i)) {
			printf("%d\t%c\t", i, (unsigned char)i); /* Print only if printable */
		} else {
			printf("%d\tNP\t", i);
		}

		if (i % 8 == 7) {
			printf("\n");
		}
	}
	printf("\nNP: Not Printable\n");
	return 0;
}
