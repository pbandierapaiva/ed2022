// Programa para saber o tamanho dos tipos de variáveis


#include <stdio.h>

int main() {
	char c;
	int  i;
	long int li;
	float f;
	double d;
	
	int vetor[10];
	
	printf("Tipo char, tamanho: %ld \n", sizeof( c ) );
	printf("Tipo int, tamanho: %ld \n", sizeof( i ) );	
	printf("Tipo longint, tamanho: %ld \n", sizeof( li ) );
	printf("Tipo float, tamanho: %ld \n", sizeof( f ) );
	printf("Tipo double, tamanho: %ld \n", sizeof( d ) );
	printf("Tipo vetor de int [10], tamanho: %ld \n", sizeof( vetor ) );
}

