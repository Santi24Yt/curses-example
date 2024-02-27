# Compilador
CC = gcc
# Flags del compilador
CFLAGS = -lcurses -I./include/
# Archivos fuente
SOURCES = ./src/*.c

# Los comandos que se ejecutan por default al poner solo `make`
all: clean lspflags compile run

# Compilar los archivos fuente con el compilador y las flags, la salida será el archivo `game`
compile:
	$(CC) $(SOURCES) $(CFLAGS) -o game

# Ejecutar el programa
run:
	./game

# Limpiar la version anterior aunque no exista
clean:
	rm game || true

# Esto es necesario para que el lsp de clangd incluya los headers propios que se incluyen también al compilar
lspflags:
	echo $(CFLAGS) | tr " " "\n" > compile_flags.txt
