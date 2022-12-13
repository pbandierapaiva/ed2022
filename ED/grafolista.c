#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typdef struct VERT {
    int v;
    struct VERT *prox;
} Vertice;


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

int main() {
    int n, v1,v2;
    char incluir[5];
    char nstr[10];
    Vertice *vertices; 
    Vertice *tmp;

    printf("Quantos vértices tem seu grafo? ");
    fgets(nstr, 10, stdin);
    n = atoi(nstr);

    vertices = malloc( sizeof(Vertice)*n );
    for(int i=0; i<n*n; i++) vertices[i]=NULL;

    while(1) {
        printf("Incluir aresta (S/n)? ");
        fgets( incluir, 5, stdin );
        if( toupper(incluir[0])!='S' && incluir[0]!=10 ) break;

        printf("Entre com vértices separados por enter (0-%d):\n ", n-1);
        v1 = pegaValor( n );
        v2 = pegaValor( n );

        tmp = malloc( sizeof(Vertice) );
        tmp.v = v2;
        tmp.prox = NULL;
        if( vertices[ v1 ] != NULL ) 
            tmp->prox = vertices[ v1 ];
        vertices[ v1 ] = tmp;

        tmp = malloc( sizeof(Vertice) );
        tmp.v = v1;
        tmp.prox = NULL;
        if( vertices[ v2 ] != NULL ) 
            tmp->prox = vertices[ v2 ];
        vertices[ v2 ] = tmp;
    }






