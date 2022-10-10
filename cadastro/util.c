// Funções auxiliares para tratar com o CSV de Servidores

#include "cadastro.h"
#include <stdio.h>


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


