CC = gcc
CFLAGS = -Wall -Wextra -pthread -Iinclude
SRC = src/main.c src/jogo.c src/npc.c src/comodos.c src/pistas.c src/save_load.c
OBJ = $(SRC:.c=.o)
TARGET = mansion_mystery

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f $(OBJ) $(TARGET)
