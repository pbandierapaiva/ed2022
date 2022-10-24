// fila.c
// implementa uma fila utilizando a ED de uma lista simplesmente ligada (listasl)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "listasl.h"


void enfileira( NO **head, char *novoNome ) {    // enqueue
	NO *p, *novoNo;
	
	novoNo = malloc( sizeof(NO) );
	novoNo->prox = NULL;
	strcpy(novoNo->nome, novoNome);
	
	p = *head;
	if( !p ) {  // *head == NULL
		*head = novoNo;
		return;
		}
	while( p->prox ) {  //  p->prox != NULL
		p = p->prox;
		}
	p->prox = novoNo;
}

void desenfileira( NO **head, char *nomeresp )  {
	NO *p;
	
	p = *head;
	
	if( !p ){  //Fila vazia
		strcpy( nomeresp, ""); 
		return;
		}
	
	if( p->prox == NULL ) {
		strcpy( nomeresp, p->nome );
		free( p );
		*head = NULL;
		return;
	}	
	
	while( p->prox->prox != NULL ) {
		p = p->prox;
	}
	strcpy( nomeresp, p->prox->nome );
	free( p->prox );
	p->prox = NULL;
}

void espia( NO *fila, char *nomeresp ) {
	NO *p;
	
	p=fila;
	if( p == NULL ){
		strcpy( nomeresp, ""); 
		return;
		}
	while( p->prox != NULL )
		p = p->prox;
	strcpy( nomeresp, p->nome);
}

int main() {
	NO *fila;
	char n[80];
	
	char resp[5];
	
	printf("\nFILA\nI - insere, R - retira, O - olha, S - sai\n>>");
	
	while( 1 ) {
		fgets( resp, 4, stdin);
		
		switch(toupper(resp[0])) {
		case 'I':
			printf("Entre com dado: ");
			fgets( n, 79, stdin);
			printf(">> ");
			enfileira( &fila, n );
			break;
		case 'R':
			desenfileira( &fila, n );
			printf("\n%s\n>> ", n);		
			break;
		case 'O':
			espia( fila, n );
			printf("\n%s\n>> ", n);
			break;
		case 'S':
			return 0;
		default:
			printf("\nI - insere, R - retira, O - olha, S - sai\n\n>> ");
			break;
		}
	}
}
