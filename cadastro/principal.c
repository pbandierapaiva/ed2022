// Código fonte do programa principal para tratar com o CSV de Servidores
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cadastro.h"

int pegaCampo( char *, int, char * );

int main(){   
	FILE *fp;
	char lin[MAXLIN];
	char texto[80];
	char orglotacao[80];
	char nome[80];

	fp = fopen("/home/pub/ed/Cadastro.csv", "r");
	if( !fp ) {
		printf("\nErro de abertura de arquivo.\n\n");
		exit(-1);
	}
	
	fgets(lin, MAXLIN, fp);
	while( !feof(fp) ) {
		fgets(lin, MAXLIN, fp);
		pegaCampo( lin, UORG_LOTACAO, texto );
		if( !strcmp( texto, "CSP-DEPTO DE INFORMATICA EM SAUDE") ){
			pegaCampo(lin, UORG_LOTACAO, orglotacao);
		 	pegaCampo(lin, NOME, nome);
			printf("\n%s\t%s\n", nome,  orglotacao);
		}

	}
	return 0;
}


