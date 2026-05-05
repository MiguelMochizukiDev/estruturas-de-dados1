# 27/04/2026

## Introdução

### O que é computar?

> Computar é processar dados de entrada em dados de saída, em tempo finito.

Mas...

- Dados **quais**?
- Dados **onde**?

Ex.: um humano, ao enxergar uma caneta vermelha, ou o céu azul, computa dados sensoriais pela visão em seu cérebro, e conclui tratar-se daquela caneta e deste céu. Mas ele não obtém isso do dado de entrada por si só: ele processa essa informação em uma **memória**, que retém esses dados e os associa a outros.

Portanto,

> Computar é processar dados de entrada em dados de saída, em tempo finito, **em memória**.

### Como computamos?

O cerne da computação, e portanto do computar, está na **memória**, ou mais precisamente, em como **organizamos** e **acessamos** dados na memória a fim de os processar. Nesse sentido, convém estudar as formas pelas quais isso se faz possível. A estas, chamamos de **estruturas de dados**.

> **Estruturas de dados** são formas de acessar e de organizar memória.

Nosso objetivo com este estudo é garantir que o processamento de dados seja **eficiente**, isto é:

- Rápido: que o tempo para o processamento não seja um gargalo para a computação
- Seguro: que o processamento não desvie do comportamento projetado pelo programador
- Econômico: que o menor número de etapas e de recursos computacionais, hardware e software, seja requerido para a tarefa

## Dados

## Sobre o que computamos?

Computamos sobre **dados**, representados por bits, ou seja, codificados em zeros e uns que podem ser interpretados pelo computador.

Em um código, os dados que nomeamos e alocamos em algum espaço da memória recebem o nome de **variáveis**. Uma variável, em seu turno, tem um **identificador**, uma espécie de "apelido" usado pelo compilador; e um **tipo de dado**, que informa quanto espaço essa variável ocupa na memória e quais operações podem ser feitas sobre ela.

Em geral, pode-se dar qualquer identificador a uma variável desde que:

- O primeiro caractere seja uma letra ou underscore
- Os demais caracteres são letras, underscores ou dígitos

Na linguagem C, que adotamos para esta disciplina, temos vários **tipos primitivos de dados**. Atenção: os tamanhos (em bits) não são fixos no padrão ANSI C, que é até hoje o considerado universal e aceito por qualquer compilador da linguagem; a tabela abaixo mostra valores mínimos garantidos e tamanhos típicos em sistemas 32 bits. Para programas estritamente portáveis, utilize `sizeof(tipo)` e os cabeçalhos `<limits.h>` e `<float.h>`.

| tipo primitivo | tamanho mínimo (ANSI C) | intervalo mínimo garantido | tamanho típico (32 bits) |
| --- | --- | --- | --- |
| `char` | 1 byte | -127 a 127 (ou 0 a 255, se unsigned) | 8 bits |
| `signed char` | 1 byte | -127 a 127 | 8 bits |
| `unsigned char` | 1 byte | 0 a 255 | 8 bits |
| `short` | 2 bytes | -32767 a 32767 | 16 bits |
| `unsigned short` | 2 bytes | 0 a 65535 | 16 bits |
| `int` | 2 bytes | -32767 a 32767 | 32 bits |
| `unsigned int` | 2 bytes | 0 a 65535 | 32 bits |
| `long` | 4 bytes | -2147483647 a 2147483647 | 32 bits (em sistemas LP64, pode ser 64) |
| `unsigned long` | 4 bytes | 0 a 4294967295 | 32 bits |
| `float` | - | +-1.18e-38 (precisão de ~6 dígitos) | 32 bits |
| `double` | - | +-2.23e-308 (precisão de ~10 dígitos) | 64 bits |
| `long double` | - | maior ou igual a double | 80 ou 128 bits |
| `void` | - | tipo vazio (ausência de valor) | - |
| `tipo*` (ponteiro) | - | endereço de memória; depende da arquitetura | 4 bytes (32 bits) |

**Observações importantes sobre a tabela:**

- `char` pode ser com sinal ou sem sinal por definição do compilador. Use `char` apenas para caracteres.
- Os modificadores `short`, `long` e `unsigned` não são tipos autônomos - eles modificam `int` e `char`.
- `signed` é implícito para `int`, `short`, `long`. Para `char`, deve ser escrito se necessário.
- `long double` existe no ANSI C, mas não é totalmente portável.
- Não há tipo `long float`.
- `void` não pode ser instanciado em variáveis.

### Modificadores de tipo inteiro

Para os tipos inteiros (`char`, `short`, `int`, `long`), usamos:

- `signed` - valor pode ser negativo
- `unsigned` - valor não negativo
- `short` - reduz o intervalo
- `long` - aumenta o intervalo

Exemplos:

- `unsigned char` -> 0 a 255
- `unsigned int` -> índices e tamanhos
- `int` -> quando negativos são necessários

### Ponteiros e o tipo `void*`

- Ponteiros guardam endereços de memória
- Aritmética de ponteiros avança `sizeof(tipo_base)`
- `void*` é ponteiro genérico, mas não permite aritmética no ANSI C
- Para aritmética, converta para `char*`

Exemplo:
```c
void *p = ...;
char *q = (char *)p;
```

### Modificadores de tipo de acesso (ANSI C)

- `const` - somente leitura
- `volatile` - impede otimizações

### Onde as variáveis são declaradas

As variáveis têm **escopo**, isto é, só podem ser referenciadas em regiões específicas, e **duração**, ou seja, podem ser usadas até serem liberadas da memória. Nesse sentido, variáveis podem ser:

- Locais (ou automáticas): só existem e podem ser usadas no bloco (entre as chaves) onde são declaradas
- Parâmetros formais: comportam-se como variáveis locais na definição de uma função qualquer
- Variáveis globais: são reconhecidas pelo programa inteiro e persistem até o fim do programa
- Variáveis estáticas: só são reconhecidas no seu escopo, qualquer que seja (bloco ou arquivo), mas persistem até o fim do programa.

### Construção de novos tipos

A partir dos tipos primitivos:

- Ponteiros (`tipo*`)
- Arrays (`tipo nome[tamanho]`)
- Estruturas (`struct`)
- Uniões (`union`)
- Enumerações (`enum`)

Esses mecanismos permitem implementar listas, pilhas, filas, árvores etc.
