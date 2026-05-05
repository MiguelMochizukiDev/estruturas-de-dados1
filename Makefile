# Makefile
# Autor: Miguel Mochizuki Silva
# Descricao: Compila todos os arquivos .c do projeto, gerando executáveis em bin/,
# com gerenciamento automático de dependências de headers.
# Arquivos em src/ são tratados como módulos (sem main) e não geram executáveis.

CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -O0 -Iinclude
LDFLAGS =
LDLIBS = -lm

# Diretórios
BUILD_DIR = build
BIN_DIR = bin
INCLUDE_DIR = include

# Encontra todos os arquivos .c (excluindo build e bin)
SOURCES := $(shell find . -path ./$(BUILD_DIR) -prune -o -path ./$(BIN_DIR) -prune -o -name "*.c" -print)

# Separa módulos (src/) e programas (restante)
MODULE_SOURCES := $(filter ./src/%, $(SOURCES))
PROGRAM_SOURCES := $(filter-out ./src/%, $(SOURCES))

# Objetos
OBJECTS := $(patsubst ./%.c, $(BUILD_DIR)/%.o, $(SOURCES))
MODULE_OBJECTS := $(patsubst ./%.c, $(BUILD_DIR)/%.o, $(MODULE_SOURCES))

# Executáveis (apenas programas)
EXECUTABLES := $(patsubst ./%.c, $(BIN_DIR)/%, $(PROGRAM_SOURCES))

# Arquivos de dependência (.d)
DEPS := $(patsubst ./%.c, $(BUILD_DIR)/%.d, $(SOURCES))

# Alvo padrão: compila todos os executáveis
all: $(EXECUTABLES)

# Regra para linkar um executável (inclui módulos)
$(BIN_DIR)/%: $(BUILD_DIR)/%.o $(MODULE_OBJECTS)
	@mkdir -p $(dir $@)
	@$(CC) $(LDFLAGS) $^ $(LDLIBS) -o $@

# Regra para compilar .c -> .o
$(BUILD_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

# Regra para gerar arquivos .d
$(BUILD_DIR)/%.d: %.c
	@mkdir -p $(dir $@)
	@$(CC) -MM -I$(INCLUDE_DIR) $< -MT $(BUILD_DIR)/$*.o -MT $@ > $@

# Inclui dependências
-include $(DEPS)

# Executa um programa e organiza arquivos criados em artifacts/
run:
	@if [ -z "$(file)" ]; then \
		echo "Usage: make run file=<relative_path_to_executable>"; \
		echo "Example: make run file=aulas/2026-05/2026-05-04/exercicios/atividade_arquivo01"; \
		exit 1; \
	fi
	@EXECUTABLE="$(BIN_DIR)/$(file)"; \
	if [ ! -f "$$EXECUTABLE" ]; then \
		echo "Error: $$EXECUTABLE not found. Build it first with 'make'."; \
		exit 1; \
	fi; \
	ARTIFACT_DIR="artifacts/$$(dirname "$(file)")"; \
	mkdir -p artifacts; \
	find . -path ./$(BUILD_DIR) -prune -o -path ./$(BIN_DIR) -prune -o -path ./artifacts -prune -o -type f -print 2>/dev/null | sort > /tmp/before.txt; \
	echo "Running $$EXECUTABLE..."; \
	./$$EXECUTABLE; \
	EXIT_CODE=$$?; \
	find . -path ./$(BUILD_DIR) -prune -o -path ./$(BIN_DIR) -prune -o -path ./artifacts -prune -o -type f -print 2>/dev/null | sort > /tmp/after.txt; \
	NEW_FILES=$$(diff /tmp/before.txt /tmp/after.txt | grep "^>" | sed 's/^> //'); \
	if [ -n "$$NEW_FILES" ]; then \
		echo "Moving created files to artifacts/..."; \
		mkdir -p "$$ARTIFACT_DIR"; \
		echo "$$NEW_FILES" | while read newfile; do \
			mv "$$newfile" "$$ARTIFACT_DIR/"; \
			echo "  → $$ARTIFACT_DIR/$$(basename "$$newfile")"; \
		done; \
	fi; \
	rm -f /tmp/before.txt /tmp/after.txt; \
	exit $$EXIT_CODE

# Limpeza
clean:
	@rm -rf $(BUILD_DIR) $(BIN_DIR) artifacts

.PHONY: all clean run
