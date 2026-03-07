#────────────  Configurații  ────────────
CC      := gcc
CFLAGS  := -Wall -Wextra -std=c11 -O2
TARGET  := tema2
SRC     := tema2.c auxiliary.c heap.c tree.c binary.c task.c
HEADERS := structuri.h auxiliary.h heap.h tree.h binary.h task.h

#────────────  Reguli implicite  ────────────
build: $(SRC) $(HEADERS)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

#────────────  Utilitare  ────────────
.PHONY: run clean build

run:
	./$(TARGET) $(ARGS)

clean:
	$(RM) $(TARGET)
