// Código fonte do programa principal para tratar com o CSV de Servidores
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "cadastro.h"

int main(int argc, char **argv){   
	FILE *fp;
	char lin[MAXLIN];
	char texto[80];
	char orglotacao[80];
	char uorglotacao[80];
	
	long int inicio;

	char nome[80];
	char busca[80];

	if( argc!=2 ) {
		printf("\nUso: %s \"Nome a buscar\" \n\n",argv[0]);
		exit(-1);
	}	
	paraMaiusculas( argv[1], busca );
	
	// Inicia cronometro
	inicio = time(NULL);
		
	fp = fopen("/home/pub/ed/Cadastro.csv", "r");
	if( !fp ) {
		printf("\nErro de abertura de arquivo.\n\n");
		exit(-1);
	}
	
	fgets(lin, MAXLIN, fp);
	while( !feof(fp) ) {
		fgets(lin, MAXLIN, fp);
		pegaCampo( lin, NOME, nome );
		if( strstr( nome, busca) ){
			pegaCampo(lin, ORG_LOTACAO, orglotacao);
			pegaCampo(lin, UORG_LOTACAO, uorglotacao);
			printf("\n%s\t%s\t%s\n", nome,  
					orglotacao, uorglotacao);
		}

	}
	printf("\nTempo: %lds\n\n",  time(NULL) - inicio);

	return 0;
}


