// Lista ligada 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct No {
	char nome[80];
	struct No *prox;
} NO;

void insereNo( NO **head, char *dado ) {
	NO *no;	

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
	NO *cabeca;
	char nome[80];
	
	cabeca = NULL;
	
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

