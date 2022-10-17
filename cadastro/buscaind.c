// Código fonte do programa principal para buscar nome no CSV de Servidores
// utilizando arquivo de índice "Cadastro.ndx"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "cadastro.h"

int main(int argc, char **argv){   
	FILE *fp, *fndx;
	REGIND reg;
	
	
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
		
	fndx = fopen("Cadastro.ndx","r");
	if( !fndx ) {
		printf("\nErro de abertura de arquivo índice Cadastro.ndx.\n\n");
		exit(-1);
	}	
	fp = fopen("/home/pub/ed/Cadastro.csv", "r");
	if( !fp ) {
		printf("\nErro de abertura de arquivo.\n\n");
		exit(-1);
	}	
	
	while( !feof(fndx) ) {
		fread( &reg, sizeof(REGIND), 1, fndx);
		
		if( strstr( reg.nome, busca) ){
			fseek( fp, reg.offset, 0);
			fgets( lin, MAXLIN, fp);
			pegaCampo(lin, ORG_LOTACAO, orglotacao);
			pegaCampo(lin, UORG_LOTACAO, uorglotacao);
			printf("\n%s\t%s\t%s\n", nome,  
					orglotacao, uorglotacao);
		}
	
	
	}
	
	printf("\nTempo: %lds\n\n",  time(NULL) - inicio);

	return 0;
}


