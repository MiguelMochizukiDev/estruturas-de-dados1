## 04/05/2026

### Dados e memória secundária

Até aqui, nossa discussão sobre computação focou na **memória primária** (RAM), onde variáveis residem durante a execução do programa. Mas há um problema fundamental: a memória primária é **volátil**. Ao desligar o computador ou terminar o programa, todos os dados se evaporam.

A pergunta, portanto, é: **como persistimos dados?**

A resposta está na **memória secundária** — discos rígidos, SSDs e outros dispositivos de armazenamento permanente. Diferentemente da RAM, que oferece acesso rápido mas temporário, a memória secundária é lenta mas durável.

Nela, organizamos dados em estruturas chamadas **arquivos**. Um arquivo é um *container* de bytes armazenado no disco, identificado por um nome e localização (caminho). Os arquivos permitem:

- Persistência: dados sobrevivem ao término do programa
- Compartilhamento: múltiplos programas acessam os mesmos dados
- Escala: armazenar mais dados do que a RAM comporta

Contudo, há um *trade-off*: acessar dados em memória secundária é **ordens de magnitude mais lento** que acessar RAM. Uma operação de leitura/escrita em disco demanda milissegundos, enquanto acesso à memória leva nanossegundos.

Portanto, a eficiência ao trabalhar com arquivos exige que compreendamos não apenas *o que* fazer com os dados, mas *como acessá-los*.

### Arquivos

Um arquivo, do ponto de vista do programa, é uma **sequência de bytes**. O sistema operacional fornece abstrações e funções para que o programador não precise se preocupar com os detalhes físicos do armazenamento em disco.

Em C, trabalhamos com arquivos por meio de:

```c
FILE* fopen(const char* nome, const char* modo);
int fclose(FILE* arquivo);
```

Porém, antes de abrir um arquivo, é essencial entender os **modos de acesso**.

#### Modos de acesso

Um arquivo pode ser acessado de diferentes maneiras:

- **Leitura sequencial** (`"r"`): comecamos no início, lemos byte a byte, até o fim. Não podemos voltar para trás sem fechar e reabrir.
- **Escrita sequencial** (`"w"`): escrevemos sequencialmente do início. Se o arquivo existe, é truncado (apagado). Se não existe, é criado.
- **Acréscimo** (`"a"`): escrevemos sempre no final do arquivo, preservando o conteúdo anterior.
- **Acesso aleatório**: é possível "saltar" para qualquer posição no arquivo sem ler tudo antes. Funções como `fseek()` e `ftell()` permitem isso.

Modos em C:

| Modo | Descrição | Cria se não existir | Trunca |
| --- | --- | --- | --- |
| `"r"` | Leitura | Não | — |
| `"w"` | Escrita | Sim | Sim |
| `"a"` | Acréscimo | Sim | Não |
| `"r+"` | Leitura/escrita | Não | Não |
| `"w+"` | Leitura/escrita | Sim | Sim |
| `"a+"` | Leitura/acréscimo | Sim | Não |

**Observação crucial**: ao trabalhar com dados estruturados (não apenas texto), cuidado com a **codificação**. Um arquivo escrito em modo texto (`"w"`) pode realizar conversões de fim de linha (`\n` para `\r\n` no Windows), corrompendo dados binários. Use `"wb"` e `"rb"` para modo binário.

#### Trabalhando com arquivos

Um padrão seguro é:

```c
FILE* arquivo = fopen("dados.txt", "r");

if (arquivo == NULL) {
    perror("Erro ao abrir arquivo");
    return 1;
}

// Processamento do arquivo

if (fclose(arquivo) != 0) {
    perror("Erro ao fechar arquivo");
    return 1;
}
```

Pontos importantes:

- Sempre verificar se `fopen()` retorna `NULL` (falha na abertura)
- Sempre fechar o arquivo com `fclose()`, mesmo em caso de erro (ou usar técnicas avançadas como `atexit()`)
- Usar `perror()` para mensagens de erro descritivas
- Considerar a ordem de leitura/escrita: uma operação de escrita segue a posição do cursor; ler após escrever sem usar `fseek()` lê a partir da posição atual
