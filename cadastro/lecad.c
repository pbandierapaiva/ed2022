// Programa para coletar dados de um CSV muuuuito grande

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLIN 5000

int main() {
    FILE *fp, *outfp;
    char linha[MAXLIN];
    char *p1, *p2;
    short int conta = 0;
    short int n;
    int *tamMaxCpos;
    int *pInt;
	int numLinhas=0;

    fp = fopen("/home/pub/ed/Cadastro.csv", "r");
    outfp = fopen("pre-cadastro.h", "w");
    if( !fp || !outfp) {   // fp==NULL => Erro de abertura
        printf("Erro de abertura do arquivo");
        exit(-1);
    }

    fputs("// Arquivo gerado automaticamente usando lecad\n\n", outfp);
    
    // Lê a primeira linha
    fgets( linha, MAXLIN, fp );

    // extrai e imprime os nomes dos campos e seus respectivos índices
    p1 = linha;
    while( *p1 != '\0' ) {

	    if( *p1 == '"' ) {
	    	p1++;
	    	p2 = p1;
	    	}
	    while( *p2 != '"' ) 
	    	p2++;
	    *p2='\0';
	    
	    fprintf(outfp, "\n#define %s\t%d", p1, conta);
	    
	    conta++;
	    do {
	    	p2++;
	    } while( *p2 !='"' &&  *p2 !='\0' );
	    p1 = p2;
	}
    fprintf(outfp, "\n\n");

    tamMaxCpos = malloc( sizeof(int) * conta );
    if( !tamMaxCpos ) {
    	printf("Erro de alocação de memória\n\n");
    	exit(-1);
    }
    
    //inicializando vetor de inteiros com 0
    for(int i=0; i<conta; i++ ) tamMaxCpos[i]=0;
    
    while( !feof(fp) ) {	
		fgets( linha, MAXLIN, fp );
		numLinhas++;
		n = 0;
		p1 = linha;
		while( *p1 != '\0' ) {
			if( *p1 == '"' ) {
				p1++;
				p2 = p1;
				}
			while( *p2 != '"' ) 
				p2++;
			*p2='\0';
			if( strlen(p1) > tamMaxCpos[n] ) {
				tamMaxCpos[n] = strlen(p1);
				}
			n++;
			do {
				p2++;
			} while( *p2 !='"' &&  *p2 !='\0' );
			p1 = p2;
		}
    } // lendo arquivo linha a linha
    
    fputs("\n\ntypedef  struct { ", outfp);
    for(int i=0; i<conta; i++)
		fprintf(outfp, "\n\tchar CPO_%d[%d];",i, tamMaxCpos[i]+1);
	
	fputs("\n\t} REGISTRO;", outfp);

	printf("Número de linhas lidas %d", numLinhas);
}










