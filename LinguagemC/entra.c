// Função para entrada de valores numéricos (float)
// em um vetor alocado estaticamente

#include <stdio.h>
#include <stdlib.h>

#define MAXVAL 100

void leNumero( float *f ) {
	char entrada[10];
	float lido;
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
	char entra[5];
	
	float vet[MAXVAL];
	float x;

	printf("\nEntre com número de valores: ");
	// scanf("%d", &n);
	fgets(entra, 5, stdin);
	n = atoi(entra);
	
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

