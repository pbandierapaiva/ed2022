// verifica maior tamanho de linha
#include <stdio.h>
#include <string.h>

#define SUPERMAX 20000

int main(){   
	FILE *fp;
    char linha[SUPERMAX];
    int max=0;

    fp = fopen("/home/pub/ed/Cadastro.csv", "r");
    fgets(linha, SUPERMAX, fp);
    while(!feof(fp)){
        if(strlen(linha)>max) {
            max = strlen(linha);
        }
        fgets(linha, SUPERMAX, fp);
    }
    printf("Tamanho máximo da linha: %d\n\n", max);

}