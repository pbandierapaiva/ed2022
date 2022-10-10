###
###

CC = gcc
# para DEBUG...
# OPT = -g
OPT = 


principal : principal.o util.o
	$(CC)  principal.o util.o -o principal
	
util.o : util.c cadastro.h
	$(CC) -c $(OPT)  util.c -o util.o
principal.o : principal.c cadastro.h
	$(CC) -c $(OPT)  principal.c -o principal.o
	
limpa:
	rm principal.o util.o principal
