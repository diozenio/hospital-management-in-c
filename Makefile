# Compilador
CC = gcc

# Flags de compilação
CFLAGS = -Wall -Wextra -std=c99

# Nome do executável
TARGET = hospital_management

# Diretórios
SRC_DIR = src
UTILS_DIR = $(SRC_DIR)/utils
INCLUDE_DIR = $(SRC_DIR)/include
APPS_DIR = $(SRC_DIR)/apps
BIN_DIR = $(SRC_DIR)/bin

# Arquivos fonte
SOURCES = $(wildcard $(SRC_DIR)/*.c) $(wildcard $(SRC_DIR)/**/*.c) $(wildcard $(UTILS_DIR)/*.c) $(wildcard $(INCLUDE_DIR)/*.c) $(wildcard $(APPS_DIR)/*.c)

# Objetos gerados
OBJECTS = $(patsubst $(SRC_DIR)/%.c,$(BIN_DIR)/%.o,$(SOURCES))

# Regra padrão
all: $(BIN_DIR) $(BIN_DIR)/$(TARGET)

# Criar diretório bin e subdiretórios se não existirem
$(BIN_DIR):
	mkdir -p $(BIN_DIR)
	mkdir -p $(BIN_DIR)/utils
	mkdir -p $(BIN_DIR)/include
	mkdir -p $(BIN_DIR)/apps

# Regra para criar o executável
$(BIN_DIR)/$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

# Regra para compilar arquivos .c em .o
$(BIN_DIR)/%.o: $(SRC_DIR)/%.c | $(BIN_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BIN_DIR)/%.o: $(UTILS_DIR)/%.c | $(BIN_DIR)/utils
	$(CC) $(CFLAGS) -c $< -o $@

$(BIN_DIR)/%.o: $(INCLUDE_DIR)/%.c | $(BIN_DIR)/include
	$(CC) $(CFLAGS) -c $< -o $@

$(BIN_DIR)/%.o: $(APPS_DIR)/%.c | $(BIN_DIR)/apps
	$(CC) $(CFLAGS) -c $< -o $@

# Limpar arquivos gerados
clean:
	rm -rf $(BIN_DIR)

mock:
	echo "1;Admin;admin;123;ADMIN" > $(BIN_DIR)/users.txt
	echo "2;Enfermeiro;enfermeiro;123;NURSE" >> $(BIN_DIR)/users.txt 
	echo "3;Medico;medico;123;DOCTOR" >> $(BIN_DIR)/users.txt

# Executar o programa
run: $(BIN_DIR)/$(TARGET)
	./$(BIN_DIR)/$(TARGET)

.PHONY: all clean run mock	
