# Compilador
CC = gcc
# Flags del compilador
CFLAGS = -lcurses -I./include/
# FLags de desarrollo
DEVFLAGS = -Wall -Wextra -Werror
# Archivos fuente
SOURCES = ./src/*.c

# Los comandos que se ejecutan por default al poner solo `make`
all: clean compile run

# Comandos que se ejecutan al hacer `make dev`
dev: clean lspflags compiledev

# Compilar los archivos fuente con el compilador y las flags, la salida será el archivo `game`
compile:
	$(CC) $(SOURCES) $(CFLAGS) -o game

# Compilar con flags dev
compiledev:
	$(CC) $(SOURCES) $(CFLAGS) $(DEVFLAGS) -o game

# Ejecutar el programa
run:
	./game

# Limpiar la version anterior aunque no exista
clean:
	rm game || true

# Esto es necesario para que el lsp de clangd incluya los headers propios que se incluyen también al compilar
lspflags:
	echo $(CFLAGS) $(DEVFLAGS) | tr " " "\n" > compile_flags.txt
