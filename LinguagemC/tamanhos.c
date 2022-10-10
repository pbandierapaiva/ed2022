// Programa para saber o tamanho dos tipos de variáveis


#include <stdio.h>
#include <string.h>

int main() {
	char c;
	int  i;
	long int li;
	float f;
	double d;
	
	int vetor[10];
	char st[] = "12345";	
	char x[10];

	strcpy( x, "12345");
	printf("%s\n", x);


	printf("Tipo char, tamanho: %ld %ld\n", sizeof( c ), &c );
	printf("Tipo int, tamanho: %ld \n", sizeof( i ) );	
	printf("Tipo longint, tamanho: %ld \n", sizeof( li ) );
	printf("Tipo float, tamanho: %ld \n", sizeof( f ) );
	printf("Tipo double, tamanho: %ld \n", sizeof( d ) );
	printf("Tipo vetor de int [10], tamanho: %ld \n", sizeof( vetor ) );
	printf("Tipo char*, tamanho: %ld %ld\n", strlen( st ), &st );

}

