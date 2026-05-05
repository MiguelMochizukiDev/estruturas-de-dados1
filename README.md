# Estruturas de Dados 1

Este repositório contém notas de aula e resoluções de exercícios relativos à disciplina "Estruturas de Dados I", ministrada na UFPB em 2026.1 pela professora Liliane dos Santos Machado.

## Estrutura do projeto

```bash
estruturas-de-dados1
├── aulas/              # Aulas organizadas por data
│   └── 2026-05/
│       └── 2026-05-04/
│           └── exercicios/
├── artifacts/          # Arquivos gerados durante execução (ignorado pelo Git)
├── bin/                # Executáveis compilados
├── build/              # Arquivos objeto (.o) e dependências (.d)
├── include/            # Headers (.h)
├── src/                # Módulos reutilizáveis (.c)
├── Makefile
├── README.md
└── main.c
```

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

## Executando com captura de arquivos

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
