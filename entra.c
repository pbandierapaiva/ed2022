// Função para entrada de valores numéricos

#include <stdio.h>
#include <stdlib.h>

#define MAXVAL 100

void leNumero( float *f ) {
	float lido;
	char entrada[10];
	char *endptr;
	
	printf("> ");
	while(1) {
		fgets( entrada, 9, stdin);
		lido = strtof( entrada, &endptr );
		
		if( *endptr =='\n' || *endptr =='\0' ) {
			*f = lido;
			return;
			}
		printf("Número ponto flutuante inválido. Entre novamente: \n> ");
		}
}

int main() {
	int n;
	
	float vet[MAXVAL];
	float x;

	printf("\nEntre com número de valores: ");
	scanf("%d", &n);
	
	if( n>MAXVAL ) {
		printf("\nNúmero máximo de valores %d\n\n",MAXVAL);
		return -1;
		}

	for( int i=0; i<n; i++)
		leNumero( vet+i );
		
	for( int i=0; i<n; i++)
		printf("\n%f", vet[i]);
		
	printf("\n");

}

