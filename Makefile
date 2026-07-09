#────────────  Configuration  ────────────
CC      := gcc
CFLAGS  := -Wall -Wextra -std=c11 -O2 -Iinclude
TARGET  := huffman-satellite-encoder

SRC_DIR := src
SRC     := $(wildcard $(SRC_DIR)/*.c)
OBJ     := $(SRC:.c=.o)

#────────────  Rules  ────────────
build: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

.PHONY: run clean build

run:
	./$(TARGET) $(ARGS)

clean:
	$(RM) $(TARGET)
