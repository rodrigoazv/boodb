# Compiler and flags
CC := gcc
CFLAGS := -std=c17 -Wall -Wextra -O2 -g
INCLUDES := -Iinclude

# Source and build directories
SRC_DIR := src
OBJ_DIR := build
BIN_DIR := bin
TARGET := $(BIN_DIR)/idb

# Source and object files
SRC := $(wildcard $(SRC_DIR)/*.c)
OBJ := $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC))

# Default target
all: $(TARGET)

# Linking
$(TARGET): $(OBJ)
	@mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) $^ -o $@

# Compilation
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Run
run: all
	./$(TARGET)

# Clean
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)

.PHONY: all clean run
