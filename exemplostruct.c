// Programa para mostrar a utilização de STRUCT e TYPDEF em C

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLIN 5000

typedef struct {
    char Id_SERVIDOR_PORTAL[10];
    char NOME[100];
    char DESCRICAO_CARGO[60];
    char UORG_LOTACAO[60];
    char ORGSUP_LOTACAO[60];
} REGISTRO;

int main() {
    FILE *fp;
    // REGISTRO reg[100];
    char linha[MAXLIN];
    int tam, tamMaxLin = 0;
    int contalin=0;

    fp = fopen("/home/pub/ed/cadastro.csv", "r");
    if( !fp ) {   // fp==NULL => Erro de abertura
        printf("Erro de abertura do arquivo");
        exit(-1);
    }

    while( ! feof(fp) ) {
        contalin++;
        fgets( linha, MAXLIN, fp );
        tam = strlen(linha);
        if( tam > tamMaxLin ) 
            tamMaxLin = tam;
    }
    printf("\nTamanho máximo da linha: %d\n", tamMaxLin);
    printf("Número de linhas: %d\n", contalin);
}




