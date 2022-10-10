// Calcula desvio padrão de 5 números
#include <stdio.h>
#include <math.h>

#define MAXLEN 5

int main() {
        int notas[MAXLEN];
	int num;
	float media=0;
	float acd = 0;
	int acumula = 0;

        for( int i=0; i<MAXLEN; i++) {
                printf("Entre com suas notas: ");
                scanf("%d", &num);
                notas[i] = num;
                acumula += num;
                }
        media = acumula / MAXLEN;
	
        for( int i=0; i<MAXLEN; i++) {
        	acd  += pow( notas[i] - media, 2 );
                }
        printf("Desvio padrão: %f \n", sqrt( acd )/MAXLEN);
        printf("Desvio padrão amostral: %f \n", sqrt( acd )/(MAXLEN-1));


}

