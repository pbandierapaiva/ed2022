// Cria arquivo de índice "Cadastro.ndx"
#include <stdio.h>
#include <string.h>
#include "cadastro.h"


int main() {
    FILE *infp, *outfp;
    REGIND regind;
    char linha[MAXLIN];
    unsigned long int desloca=0;
    int contador = 0;

    regind.offset=0;

    infp = fopen("/home/pub/ed/Cadastro.csv", "r");
    outfp = fopen("Cadastro.ndx", "w");

    if( !infp || !outfp ) {
        printf("Erro de abertura de arquivo.\n\n");
        return -1;
    }

    fgets( linha, MAXLIN, infp ); //descarta primeira linha
    desloca = ftell(infp);
    fgets( linha, MAXLIN, infp );

    while( !feof(infp) ) {
        printf("\r%d", contador++);
        pegaCampo( linha, NOME, regind.nome );
        regind.offset = desloca;
        fwrite( &regind, sizeof(regind), 1, outfp);
        desloca = ftell(infp);
        fgets( linha, MAXLIN, infp );
    }
    fclose(infp);
    fclose(outfp);
}
