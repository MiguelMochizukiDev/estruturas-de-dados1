## 29/04/2026

## Introdução

### Como escrever bom código em C?

A linguagem de programação C é uma linguagem de baixo nível que, ao mesmo tempo, permite a manipulação de diversos tipos de dados e variáveis por meio de funções de nossa autoria, além do controle de fluxo com estruturas condicionais e de repetição como `if`, `for` e `while`.

Ao mesmo tempo, C é uma linguagem que oferece uma proximidade com o hardware que possivelmente nenhuma outra linguagem de alto nível consegue igualar: um erro pode levar à manipulação de endereços críticos do sistema, com consequências potencialmente graves.

Nesse ínterim, um código bem escrito não é mero capricho. Ao contrário, a organização clara e robusta do código permite aproveitar as vantagens dessa linguagem sem sofrer as consequências de uma má gestão de seus recursos. Apresenta-se a nós, em suma, a seguinte questão: **como escrever bom código em C?**

Algumas reflexões a esse respeito:

- C é uma linguagem **imperativa** que permite reuso de código por meio de funções. Escrever funções monolíticas tende a torná-las mais difíceis de corrigir em caso de bugs e, mais importante, mais difíceis de generalizar e reutilizar. Escrever funções pequenas e modulares é uma boa prática.
- Os dados são usados por funções, que por sua vez são chamadas pela função `main`, em torno da qual o programa se organiza. A função `main` deve ser legível, ao mesmo tempo em que coordena as chamadas das funções e os dados que utiliza.
- Comentários não são opcionais, independentemente de o código parecer “autoexplicativo” (uma ideia, em geral, enganosa). O comentário é para o desenvolvedor que voltará ao código meses depois e, principalmente, para quem o lerá no futuro sem contexto.
- **NÃO USE VARIÁVEIS GLOBAIS.**

Dessa forma, uma maneira bastante elegante de organizar código em C é esta:

```c
/**
 * arquivo.c
 * Autor: Miguel Mochizuki Silva
 * Descricao:
 * ...
 */
#include <stdio.h>
#include <stdlib.h> // Exemplos de diretivas de pre-processamento

#define EPSILON 1E-7
#define EQUAL(a, b) (((((a) - (b)) < (EPSILON)) && (((a) - (b)) < (EPSILON))))

/* ==============================
 * Estruturas
 * ============================== */

/**
 * Exemplo de estrutura
 *
 * Atributos:
 * int a: inteiro
 * float b: float
 */
typedef struct struct1 {
    int a;
    float b;
} Struct1;

/* ==============================
 * Funcoes
 * ============================== */

int funcao1(Struct1, int, float); // Exemplo de prototipo de funcao

/* ==============================
 * MAIN
 * ============================== */

/**
 * Funcao principal
 *
 * Retorna int: 0 para sucesso; senao 1, 2 etc.
 */
int main(void) {
    int a; // Explica
    float b; // Explica
    Struct1 s1; // Explica

    if (scanf("%d %f", &a, &b) != 2) {
        return 1;
    }

    s1 = (Struct1){3, 2.4};

    int d = funcao1(s1, a, b);

    printf("%d\n", d);

    if (d != 0) {
        return d;
    }

    return 0;
}

/* ==============================
 * Implementacoes
 * ============================== */

/**
 * Funcao funcao1
 *
 * Parametros:
 * Struct1 s1: explica
 * int a: explica
 * float b: explica
 *
 * Retorna int: explica
 */
int funcao1(Struct1 s1, int a, float b) {
    // Implementacao da funcao
}
```

Um código assim pode ser facilmente dividido entre cabeçalho (por exemplo `funcoes.h`) e implementação (`funcoes.c`), deixando o sistema mais modular.

Agora, qualquer código pode usar nossas funções por meio da diretiva:

```c
#include "funcoes.h"
```

## Nota sobre funções

Quanto às funções, um dado importante é como seus argumentos são passados e processados.

Ao compilar o código, os parâmetros formais da função indicam os tipos de dados e a ordem segundo a qual devem ser copiados para um *stack frame* onde a função executa.

Isso implica duas coisas:

* C admite recursão: cada chamada recursiva de uma função cria um novo *stack frame*, que é desempilhado ao retornar ao caso base.
* A passagem de parâmetros em C é, em princípio, sempre **por valor**: não é possível modificar diretamente uma variável externa a partir de dentro de uma função.

Por outro lado, o acesso direto à memória por meio de ponteiros permite simular passagem por **referência**, isto é, permitir a modificação de dados externos à função.

Um exemplo disso é a função `scanf` da `stdio.h`:

```c
int scanf(const char* format, ...);
```

Os argumentos variádicos (`...`) devem ser ponteiros para as variáveis cujos valores serão preenchidos a partir da entrada padrão.

É importante observar que nem toda função que recebe ponteiros como parâmetro está realizando passagem por referência. Por exemplo:

```c
int compara_valores(int* p1, int* p2) {
    p1++;
    return p1 - p2;
}
```

Aqui, `p1` e `p2` são ponteiros passados **por valor**, e não por referência. O que é passado é o valor do ponteiro, não a variável original.

Em geral:

- Quando chamamos `funcao(&y, ...)`, onde `y` não é ponteiro, estamos simulando passagem por referência.
- Quando chamamos `funcao(p, ...)`, onde `p` já é ponteiro, estamos passando o ponteiro por valor.
