// Convertendo string para float
//
#include <stdio.h>
#include <stdlib.h>
	
int main(){
	int resp;
	char entrada[10];

	char *ptr;
	
	ptr = entrada;
	
	resp = 6;
	
	printf("Conteúdo de ptr (antes de chamar strtol: %c \n\n", *ptr );
	printf("Valor de resp: %d \nEntre novo valor: ", resp);
	
	fgets( entrada, 10, stdin);
	
	resp = strtol(entrada, &ptr, 10	);
	
	
	printf("Resultado em resp: %d \n\n", resp);
	printf("Conteúdo de ptr: %c\n\n", *ptr );
}






