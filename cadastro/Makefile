###
###

CC = gcc
# para DEBUG...
# OPT = -g
OPT = 

criaindice : criaindice.o	util.o
	$(CC)  criaindice.o util.o -o criaindice

principal : principal.o util.o
	$(CC)  principal.o util.o -o principal
buscaind : buscaind.o util.o
	$(CC)  buscaind.o util.o -o buscaind

tamlinhas : tamlinhas.c
	$(CC)  tamlinhas.c -o tamlinhas

criaindice.o : criaindice.c cadastro.h
	$(CC) -c $(OPT)  criaindice.c -o criaindice.o
util.o : util.c cadastro.h
	$(CC) -c $(OPT)  util.c -o util.o
principal.o : principal.c cadastro.h
	$(CC) -c $(OPT)  principal.c -o principal.o
buscaind.o : buscaind.c cadastro.h
	$(CC) -c $(OPT)  buscaind.c -o buscaind.o	
clean:
	rm principal.o util.o principal criaindice.o criaindice tamlinhas tamlinhas.o buscaind buscaind.o

all: criaindice principal tamlinhas buscaind
