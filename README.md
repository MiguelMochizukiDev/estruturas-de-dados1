# Estruturas de Dados 1

Este repositório contém notas de aula e resoluções de exercícios relativos à disciplina "Estruturas de Dados I", ministrada na UFPB em 2026.1 pela professora Liliane dos Santos Machado.

## Estrutura do projeto

```bash
estruturas-de-dados1
├── aulas/              # Aulas organizadas por data
│   └── 2026-05/
│       └── 2026-05-04/
│           └── exercicios/
├── artifacts/          # Gerados durante execução (ignorado pelo Git)
├── bin/                # Executáveis compilados
├── build/              # Arquivos objeto (.o) e dependências (.d)
├── include/            # Headers (.h)
├── src/                # Módulos reutilizáveis (.c)
├── Makefile
├── README.md
└── main.c
```

## Biblioteca de Estruturas de Dados (ED)

Como projeto para a disciplina, implementamos aqui uma biblioteca reutilizável de Tipos Abstratos de Dados (TADs) em C. A biblioteca está em expansão.

### Códigos de Status

Todas as operações admitidas pelos TADs retornam um `Status`:
- `STATUS_OK` - Operação bem-sucedida
- `STATUS_ERR_NULL` - Argumento nulo
- `STATUS_ERR_INDEX` - Índice fora dos limites

### Testes Automatizados

Execute os testes com:
```bash
make run file=main
```

Os testes cobrem:
- Criação e liberação de estruturas
- Operações de acesso e modificação
- Inserção e remoção de elementos
- Validação de casos de erro

## Compilando

Compilar todos os programas:
```bash
make
```

Gera `build/` (objetos) e `bin/` (executáveis).

Limpar:
```bash
make clean
```

Remove `build/`, `bin/` e `artifacts/`.

## Executando

O comando `make run` executa um programa e organiza automaticamente arquivos criados em `artifacts/` com a mesma estrutura de diretórios:

```bash
make run file=aulas/2026-05/2026-05-04/exercicios/atividade_arquivo02
```

Arquivos criados pelo programa são movidos para:
```
artifacts/aulas/2026-05/2026-05-04/exercicios/
```

## Arquivo .gitignore

A pasta `artifacts/` e os diretórios `build/`, `bin/` são automaticamente ignorados pelo Git.

## Licença

Este repositório é privado.
