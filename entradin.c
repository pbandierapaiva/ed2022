// Função para entrada de valores numéricos (float)
// em um vetor alocado DINAMICAMENTE

#include <stdio.h>
#include <stdlib.h>


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
	unsigned int n;
	char entra[100];
	
	float *vet;  //
	float x;

	printf("\nEntre com número de valores: ");
	fgets(entra, 100, stdin);
	n = atoi(entra);

    vet = malloc( n * sizeof(float) ); //
    if( ! vet ) {    // vet==NULL
        printf("\nErro de alocação de memória.\n");
        exit(-1);
    }

	for( int i=0; i<n; i++)
		leNumero( vet+i );
		
	for( int i=0; i<n; i++)
		printf("\n%f", vet[i]);
		
	printf("\n");

    free(vet);
}

