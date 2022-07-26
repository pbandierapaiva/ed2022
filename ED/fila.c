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
	strcpy( nomeresp, p->nome );
	*head = p->prox;
	free( p );
}

void espia( NO *fila, char *nomeresp ) {
	if( fila == NULL ){
		strcpy( nomeresp, ""); 
		return;
		}
	strcpy( nomeresp, fila->nome);
}

void imprimeInverso(NO *fila){
    NO *p;
    p = fila;
    if(!p) {
        printf("\nLista vazia.\n");
        return;
    }
	imprimeRecur( fila, fila );
}

void imprimeRecur(NO *fila, NO * corrente) {
	if( corrente->prox == NULL ){
		printf("%s\n", corrente->nome);
		return;
	}
	imprimeRecur( fila, corrente->prox );
	printf("%s\n",corrente->nome);
}

void imprimeOrdenado(NO *fila){
    NO *p;
    p = fila;
    if(!p) {
        printf("\nLista vazia.\n");
        return;
    }
    while(p) {
        printf("%s\n", p->nome);
        p = p->prox;
    }   
}

int main() {
	NO *fila;
	char n[80];
	char prompt[] = "\nFILA\nI - insere, R - retira, O - olha, P/Q - imprime, S - sai\n";
	char resp[5];
	
	fila = NULL;
	printf(prompt);
	
	while( 1 ) {
		printf("\n >> ");
		fgets( resp, 4, stdin);
		
		switch(toupper(resp[0])) {
		case 'I':
			printf("Entre com dado: ");
			fgets( n, 79, stdin);
			enfileira( &fila, n );
			break;
		case 'R':
			desenfileira( &fila, n );
			printf("\n%s ", n);		
			break;
		case 'O':
			espia( fila, n );
			printf("\n%s ", n);
			break;
        case 'P':
            imprimeOrdenado( fila );
            break;
        case 'Q':
            imprimeInverso( fila );
            break; 
		case 'S':
			return 0;
		default:
			printf("\nI - insere, R - retira, O - olha, S - sai\n\n>> ");
			break;
		}
	}
}
