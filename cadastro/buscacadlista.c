// Programa para coletar dados de um CSV muuuuito grande

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "cadastro.h"

typedef struct Registro {
	char nome[80];
	char uorglotacao[50];
	char orglotacao[50];
} REGISTRO;

typedef struct No {
	REGISTRO reg;
	struct No *prox;
} NO;


void push( NO **head, REGISTRO *r ) {    // push
    NO *novoNo;

    novoNo = malloc(sizeof(NO));
    if( novoNo == NULL ) {
        printf("Erro de alocação de memória.\n\n");
        exit(-1);
    }
    
	// cópia de REGISTRO, um string de cada vez
	//strcpy(novoNo->reg.nome, r->nome);
	//strcpy(novoNo->reg.uorglotacao, r->uorglotacao);
    //strcpy(novoNo->reg.orglotacao,	r->orglotacao);

	// alternativa à cópia string a string da estrutura
	memcpy( novoNo, r, sizeof(NO) );


    novoNo->prox = NULL;

    if(*head!=NULL) {  // Pilha vazia
        novoNo->prox = *head;
    }
    *head = novoNo;
}

void pop( NO **head, REGISTRO *r ) {
    NO *p;
    if( *head == NULL ) {  //Pilha vazia
        strcpy( r->nome, "");
        return;
    }
    p = *head;
    strcpy(r->nome, (*head)->reg.nome);
    strcpy(r->uorglotacao, (*head)->reg.uorglotacao);
    strcpy(r->orglotacao, (*head)->reg.orglotacao);

    *head = p->prox;
    free(p);
}

int conta( NO *head ) {
	int i = 0;
	NO *p = head;

	while( p ) {
		i++;
		p = p->prox;
	}
	return i;
}

int main() {
    FILE *fp;
    char linha[MAXLIN];
	char busca[81];
	char *p;
	char lotacao[81];
	char orglotacao[81];
	char lotacaoEncontrada[80];
	char nome[80];
	int contador;
    REGISTRO r;
	NO *pilha=NULL;

	printf("Entre com sua busca: ");
	fgets( busca, 80, stdin );
	p = busca;
	while( *p!='\0' && *p!='\n') {
		*p = toupper(*p);
		p++;
	}
	*p = '\0';

    fp = fopen("/home/pub/ed/Cadastro.csv", "r");
    if( !fp ) {   // fp==NULL => Erro de abertura
        printf("Erro de abertura do arquivo");
        exit(-1);
    }    
    // Lê a primeira linha
    fgets( linha, MAXLIN, fp );
   
    while( !feof(fp) ) {	
		fgets( linha, MAXLIN, fp );
		pegaCampo(linha, UORG_LOTACAO, lotacao);
 
		if( strstr(lotacao, busca) ){
			pegaCampo(linha, NOME, nome);
			pegaCampo(linha, ORG_LOTACAO, orglotacao);
			strcpy(r.nome, nome);
			strcpy(r.uorglotacao, lotacao);
			strcpy(r.orglotacao, orglotacao);
			push(&pilha, &r);
		}
	}

	contador = conta(pilha);
	while(1) {
		pop(&pilha, &r);
		if( strcmp(r.nome,"")==0 ) { //fim da pilha
			break;
		}
		printf("%s %s %s\n", r.nome, r.orglotacao, r.uorglotacao);
	}

	printf("Número de registros encontrados: %d\n\n", contador);

}




