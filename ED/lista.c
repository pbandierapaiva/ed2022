// Lista ligada 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "listasl.h"

int removeNo( NO **head, NO *noDel ) {
	NO *ptr;
	
	ptr = *head;
	if(!ptr) return 0; //lista vazia
	if(ptr==noDel) {
		*head = ptr->prox;
		free(noDel);
	}
	while( ptr->prox != noDel && ptr->prox != NULL){
		ptr = ptr->prox;	
		}
	if( !ptr->prox )
		return 0;
	else {
		ptr->prox = noDel->prox;
		free(noDel);
	}
}

void insereNo( NO **head, char *dado ) {
	NO *no = NULL;	

	no = malloc( sizeof(NO) );
	if( !no ) {
		printf("\nErro de alocação de memória\n\n");
		return;
		}
	strcpy( no->nome, dado );
	no->prox = NULL;	
	
	if( *head == NULL ) { // lista vazia
		*head = no;
		}
	else {
		no->prox = *head;
		*head = no; 
		}
	}
	
void imprimeLista( NO *head ) {
	NO *ptr;
	
	ptr = head;
	printf("\nLista:\n");
	
	while( ptr ){
		printf("\n%s", ptr->nome );
		ptr = ptr->prox;
		}
	printf("\n\n");
	}	

int main() {
	NO *cabeca = NULL;  // Cria lista vazia
	char nome[80];
	
	
	while( 1 ) {
		printf("\nEntre com um nome (FIM termina): ");
		fgets( nome, 80, stdin);
		if( ! strcmp("FIM", nome) )   // digitou FIM
			break;
		insereNo( &cabeca, nome );
		}
	imprimeLista(cabeca);
	
	return 0;
}

