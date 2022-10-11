// Funções auxiliares para tratar com o CSV de Servidores

#include "cadastro.h"
#include <stdio.h>
#include <ctype.h>

int pegaCampo( char *linha, int ind, char *retorno ) {
	char *pi, *pf, *ret;
	int contaCpo = 0;
	
	ret = retorno;
	pi = linha;
	pf = pi;
	
	while( *pi != '\0' ){
		if( *pi=='"' ) {
			pi++;
			pf=pi;
		}
		while( *pf!='"' )
			pf++;
		if( contaCpo==ind ) {
			while( pi<pf ){
				*ret = *pi;
				pi++;
				ret++;
			}	
			*ret='\0';
			return 0;
		}
		contaCpo++;
		pi = pf+1;
		while( *pi!='"' ) pi++;
	}
	return -1;
}

void paraMaiusculas(char *entrada, char *saida) {
	char *p1, *p2;
	p1 = entrada;
	p2 = saida;

	while(*p1!='\0') {
		*p2 = toupper(*p1);
		p1++;p2++;
	}
	*p2 = '\0';
}
