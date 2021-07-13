CC=gcc
CFLAG=-O2

make: main.c
	$(CC) $(CFLAG) -o add-nbo main.c
