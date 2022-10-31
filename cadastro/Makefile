###
###

CC = gcc
# para DEBUG...
OPT = -g

criaindice : criaindice.o	util.o
	$(CC)  criaindice.o util.o -o criaindice
principal : principal.o util.o
	$(CC)  principal.o util.o -o principal
buscaind : buscaind.o util.o
	$(CC)  buscaind.o util.o -o buscaind
buscacadlista : buscacadlista.o util.o
	$(CC)  buscacadlista.o util.o -o buscacadlista

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
buscacadlista.o : buscacadlista.c cadastro.h
	$(CC) -c $(OPT)  buscacadlista.c -o buscacadlista.o
clean:
	rm principal.o util.o principal criaindice.o criaindice tamlinhas tamlinhas.o buscaind buscaind.o buscacadlista.o buscacadlista

all: criaindice principal tamlinhas buscaind buscacadlista
