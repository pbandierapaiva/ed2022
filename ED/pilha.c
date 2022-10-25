// pilha.c
// implementa uma pilha utilizando a ED 
// de uma lista simplesmente ligada (listasl)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "listasl.h"


void push( NO **head, char *novoNome ) {    // push
    NO *novoNo;
    novoNo = malloc(sizeof(NO));
    if( novoNo == NULL ) {
        printf("Erro de alocação de memória.\n\n");
        exit(-1);
    }
    strcpy(novoNo->nome, novoNome);
    novoNo->prox = NULL;

    if(*head!=NULL) {  // Pilha vazia
        novoNo->prox = *head;
    }
    *head = novoNo;
}

void pop( NO **head, char *nomeRet) {
    NO *p;
    if( *head == NULL ) {  //Pilha vazia
        strcpy(nomeRet, "");
        return;
    }
    p = *head;
    strcpy(nomeRet, p->nome);
    *head = p->prox;
    free(p);
}

void espia( NO *head,  char *nomeRet ) {
    if( head==NULL )
        strcpy(nomeRet, "");
    else
        strcpy(nomeRet, head->nome);
}


int main() {
	NO *pilha;
	char n[80];
	
	char resp[5];
	
	printf("\nPilha\nI - Push, O - Pop, E - olha, S - sai\n>>");
	
	while( 1 ) {
		fgets( resp, 4, stdin);
		
		switch(toupper(resp[0])) {
		case 'I':
			printf("Entre com dado: ");
			fgets( n, 79, stdin);
			printf(">> ");
			push( &pilha, n );
			break;
		case 'O':
			pop( &pilha, n );
			printf("\n%s\n>> ", n);		
			break;
		case 'E':
			espia( pilha, n );
			printf("\n%s\n>> ", n);
			break;
		case 'S':
			return 0;
		default:
			printf("\n\nI - Push, O - Pop, E - olha, S - sai\n>> ");
			break;
		}
	}
}
