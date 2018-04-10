
SRC := src
OBJ := obj

CC = gcc
CFLAGS = -g -Wall -Iinclude/

SOURCES := $(wildcard $(SRC)/*.c)
OBJECTS := $(patsubst $(SRC)/%.c, $(OBJ)/%.o, $(SOURCES))


all: scan

objects: $(OBJECTS)

scan: $(OBJECTS)
	${CC} $^ -o $@

${OBJ}/%.o: ${SRC}/%.c
	${CC} $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)/*.o scan
