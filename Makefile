# Makefile
# Autor: Miguel Mochizuki Silva
# Descricao: Compila todos os arquivos .c do projeto, gerando executáveis em bin/,
# com gerenciamento automático de dependências de headers.

CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -O0 -Iinclude
LDFLAGS =
LDLIBS = -lm

# Diretórios
BUILD_DIR = build
BIN_DIR = bin
INCLUDE_DIR = include

# Encontra todos os arquivos .c (excluindo diretórios de build e bin)
SOURCES := $(shell find . -path ./$(BUILD_DIR) -prune -o -path ./$(BIN_DIR) -prune -o -name "*.c" -print)

# Mapeia cada .c para um objeto em build/ e um executável em bin/
OBJECTS := $(patsubst ./%.c, $(BUILD_DIR)/%.o, $(SOURCES))
EXECUTABLES := $(patsubst ./%.c, $(BIN_DIR)/%, $(SOURCES))

# Arquivos de dependência (.d)
DEPS := $(patsubst ./%.c, $(BUILD_DIR)/%.d, $(SOURCES))

# Alvo padrão: compila todos os executáveis
all: $(EXECUTABLES)

# Regra para linkar um executável a partir de seu objeto
$(BIN_DIR)/%: $(BUILD_DIR)/%.o
	@mkdir -p $(dir $@)
	@$(CC) $(LDFLAGS) $^ $(LDLIBS) -o $@

# Regra para compilar .c -> .o (com geração automática de dependências)
$(BUILD_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

# Regra para gerar arquivos .d (dependências de headers)
$(BUILD_DIR)/%.d: %.c
	@mkdir -p $(dir $@)
	@$(CC) -MM -I$(INCLUDE_DIR) $< -MT $(BUILD_DIR)/$*.o -MT $@ > $@

# Inclui os arquivos de dependência (se existirem)
-include $(DEPS)

# Remove todos os objetos, dependências e executáveis
clean:
	@rm -rf $(BUILD_DIR) $(BIN_DIR)

# Garante que a limpeza não seja interrompida por arquivos inexistentes
.PHONY: all clean
