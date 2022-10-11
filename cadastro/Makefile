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

tamlinhas : tamlinhas.c
	$(CC)  tamlinhas.c -o tamlinhas

criaindice.o : criaindice.c cadastro.h
	$(CC) -c $(OPT)  criaindice.c -o criaindice.o
util.o : util.c cadastro.h
	$(CC) -c $(OPT)  util.c -o util.o
principal.o : principal.c cadastro.h
	$(CC) -c $(OPT)  principal.c -o principal.o
	
clean:
	rm principal.o util.o principal criaindice.o criaindice tamlinhas tamlinhas.o

all: criaindice principal tamlinhas