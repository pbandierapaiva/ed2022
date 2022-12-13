
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int pegaValor(int maximo){
    int val;
    char nstr[10];

    while(1) {
        fgets(nstr, 10, stdin);
        val = atoi(nstr);
        if( val>=0 && val < maximo )
            break; 
        printf("Valor inválido.\n");
    } 
    return val;
}

void imprimeMatAdj( int *m, int dim) {
    
    for( int i=0; i<dim; i++ ) 
        printf("\t%d", i);
    for( int i=0; i<dim; i++ ) {
        printf("\n%d", i);
        for( int j=0; j<dim; j++) {
            printf("\t%d", m[(i*dim)+j] );
        }
    }
    printf("\n")
}

int main() {
    int n, v1,v2;
    char incluir[5];
    char nstr[10];
    int *matadj;

    printf("Quantos vértices tem seu grafo? ");
    fgets(nstr, 10, stdin);
    n = atoi(nstr);

    matadj = malloc( sizeof(int)*n*n );
    for(int i=0; i<n*n; i++) matadj[i]=0;

    while(1) {
        printf("Incluir aresta (S/n)? ");
        fgets( incluir, 5, stdin );
        if( toupper(incluir[0])!='S' && incluir[0]!=10 ) break;

        printf("Entre com vértices separados por enter (0-%d):\n ", n-1);
        v1 = pegaValor( n );
        v2 = pegaValor( n );

        matadj[ v1*n + v2 ] = 1;
        matadj[ v2*n + v1 ] = 1;
    }
    imprimeMatAdj( matadj, n);
}