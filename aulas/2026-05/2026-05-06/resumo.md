## 06/05/2026

### Dados sequenciais

Até agora, falamos de dados isolados — uma variável aqui, outra ali. Mas em computação, frequentemente enfrentamos o seguinte cenário:

**Precisamos processar múltiplos dados do mesmo tipo.**

Exemplos:
- Uma lista de notas de alunos
- Um conjunto de coordenadas de um objeto em movimento
- A sequência de caracteres que forma uma palavra

Para esses casos, estruturas que armazenam múltiplos elementos de forma organizada são imprescindíveis. A mais simples delas é a **sequência**, ou mais formalmente, dados dispostos em **ordem linear**.

Em C, a forma mais direta de representar sequências é por meio de **arrays** (vetores e matrizes).

## Vetores

### Definição

Um **vetor** é uma coleção de elementos de **mesmo tipo** dispostos em posições **consecutivas de memória**, acessíveis por um **índice**.

Formalmente:

> Um vetor é uma função que mapeia índices inteiros a valores de um tipo fixo.

Se declaramos `int v[10]`, criamos um mapeamento: v[0], v[1], ..., v[9] apontam para 10 posições consecutivas de memória, cada uma comportando um `int`.

Isso tem duas implicações cruciais:

1. **Acesso é O(1)**: acessar `v[i]` é instantâneo — o compilador calcula o endereço como `(endereço base) + i * sizeof(int)`.
2. **Espaço é contíguo**: todos os 10 inteiros ocupam 40 bytes seguidos na memória (em sistemas 32 bits).

A **contiguidade** é tanto uma vantagem quanto uma restrição.

### Vetores estáticos

Um vetor estático tem seu **tamanho fixo em tempo de compilação**:

```c
int v[10];          // 10 inteiros
char nomes[50];     // 50 caracteres
double matriz[5][3]; // Multidimensional (visto adiante)
```

**Vantagens:**
- Simples de usar
- Sem overhead de alocação dinâmica
- Rápido

**Desvantagens:**
- Tamanho não pode variar durante a execução
- Se você precisa de um vetor de 1000 elementos em uma iteração e 100 em outra, desperdíça memória
- O tamanho deve ser conhecido em tempo de compilação

Vetores estáticos alocam memória no **stack**, que é limitado. Arrays muito grandes podem causar *stack overflow*.

### Vetores dinâmicos

Um vetor dinâmico tem seu **tamanho definido em tempo de execução**:

```c
int n;
scanf("%d", &n);

int* v = (int*) malloc(n * sizeof(int));

if (v == NULL) {
    perror("Erro na alocação");
    return 1;
}

// Use o vetor como v[0], v[1], ..., v[n-1]

free(v);
v = NULL; // Boa prática: anular após liberar
```

**Vantagens:**
- Tamanho variável conforme necessário
- Alocação em **heap**, que é muito maior que o stack
- Flexibilidade

**Desvantagens:**
- Mais lento que vetores estáticos (overhead de alocação)
- Programador é responsável por liberar memória (`free()`)
- Possibilidade de **memory leaks** se esquecer de `free()`
- Possibilidade de **double free** (liberar duas vezes o mesmo ponteiro)

**Nota sobre realocação:** se você não sabe o tamanho final do vetor, pode usar `realloc()`:

```c
int* v = (int*) malloc(10 * sizeof(int));
// ... preenche e precisa de mais espaço ...
v = (int*) realloc(v, 20 * sizeof(int));
```

Contudo, `realloc()` é perigosa: se falhar, retorna `NULL` e você perde a referência ao vetor original. Salve em uma variável temporária:

```c
int* temp = (int*) realloc(v, 20 * sizeof(int));
if (temp == NULL) {
    perror("Erro na realocação");
    free(v); // Libera o original
    return 1;
}
v = temp;
```

---

## Matrizes

### Matrizes estáticas

Uma matriz estática é um vetor de vetores — ou mais formalmente, um array multidimensional com dimensões fixas:

```c
int m[3][4];    // 3 linhas, 4 colunas
char tabuleiro[8][8]; // Xadrez
```

Internamente, a memória é **linearizada**: uma matriz `m[3][4]` ocupa 12 posições consecutivas no padrão **row-major** (linha por linha):

```
m[0][0], m[0][1], m[0][2], m[0][3], m[1][0], ...
```

Acessar `m[i][j]` calcula o endereço como:
```
(endereço base) + (i * numero_colunas + j) * sizeof(tipo)
```

**Observação:** em C, `m[i][j]` é equivalente a `*(*(m + i) + j)`. O primeiro subscrito indexa linhas (ponteiros para linhas), o segundo indexa colunas dentro de cada linha.

Vetores estáticos multidimensionais têm as mesmas limitações: tamanho fixo, risco de *stack overflow*, sem flexibilidade.

### Matrizes dinâmicas

Uma matriz dinâmica é mais complexa. Existem abordagens:

**Abordagem 1: Alocação linear com cálculo manual de índice**

```c
int linhas = 10, colunas = 5;
int* m = (int*) malloc(linhas * colunas * sizeof(int));

if (m == NULL) {
    perror("Erro na alocação");
    return 1;
}

// Acesso: m[i * colunas + j] para m[i][j]
m[2 * colunas + 3] = 42; // Equivalente a m[2][3]

free(m);
```

**Vantagem:** contiguidade de memória, eficiente cache.
**Desvantagem:** notação desconfortável.

**Abordagem 2: Array de ponteiros (matriz de matrizes)**

```c
int linhas = 10, colunas = 5;
int** m = (int**) malloc(linhas * sizeof(int*));

if (m == NULL) {
    perror("Erro na alocação principal");
    return 1;
}

for (int i = 0; i < linhas; i++) {
    m[i] = (int*) malloc(colunas * sizeof(int));
    if (m[i] == NULL) {
        perror("Erro na alocação da linha");
        return 1;
    }
}

// Acesso intuitivo: m[i][j]
m[2][3] = 42;

// Liberação
for (int i = 0; i < linhas; i++) {
    free(m[i]);
}
free(m);
```

**Vantagem:** notação intuitiva `m[i][j]`, cada linha pode ter tamanho diferente (matrizes irregulares).
**Desvantagem:** não contígua, dois níveis de indireção, mais lento.

**Qual usar?** Depende. Para matrizes regulares e sensibilidade a performance, prefira a abordagem 1. Para código legível e flexibilidade, a abordagem 2.
