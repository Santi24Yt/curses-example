# Compilador
CC = gcc
# Flags del compilador
CFLAGS = -lcurses -I./include/ -std=c89
# FLags de desarrollo
DEVFLAGS = -Wall -Wextra -Werror
# Archivos fuente
SOURCES = ./src/*.c
# Archivos ejecutables
BINS = ./bin

# Los comandos que se ejecutan por default al poner solo `make`
all: bindir clean compile run

# Comandos que se ejecutan al hacer `make dev`
dev: bindir clean lspflags compiledev

# Crear directorio de ejecutables
bindir:
	mkdir -p $(BINS)

# Compilar los archivos fuente con el compilador y las flags, la salida será el archivo `game`
compile:
	$(CC) $(SOURCES) $(CFLAGS) -o $(BINS)/game

# Compilar con flags dev
compiledev:
	$(CC) $(SOURCES) $(CFLAGS) $(DEVFLAGS) -o $(BINS)/game

# Ejecutar el programa
run:
	./bin/game

# Limpiar la version anterior aunque no exista
clean:
	rm -f $(BINS)/game || true

# Esto es necesario para que el lsp de clangd incluya los headers propios que se incluyen también al compilar
lspflags:
	echo $(CFLAGS) $(DEVFLAGS) | tr " " "\n" > compile_flags.txt
