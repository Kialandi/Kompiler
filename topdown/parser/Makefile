SCN := ../scanner

SRC := src
SRC2 := ../scanner/src
OBJ := obj
OBJ2 := ../scanner/obj

CC = gcc
CFLAGS = -g -Wall -Iinclude/ -I../scanner/include

SOURCES := $(wildcard $(SRC)/*.c)
SOURCES2 := $(wildcard $(SRC2)/*.c)
#patsubst <pattern>, <replacement>, <location>
OBJECTS := $(patsubst $(SRC)/%.c, $(OBJ)/%.o, $(SOURCES))
OBJECTS2 := $(patsubst $(SRC2)/%.c, $(OBJ2)/%.o, $(SOURCES2))

all: scan parse

scan:
	$(MAKE) -C $(SCN)/ objects

parse: $(OBJECTS) $(OBJECTS2)
	${CC} $(CFLAGS) $^ -o $@

${OBJ}/%.o: ${SRC}/%.c
	${CC} $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)/*.o parse

cleanall:
	rm -f $(OBJ)/*.o parse
	rm -f $(OBJ2)/*.o
