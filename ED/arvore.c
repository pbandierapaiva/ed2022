#include <stdio.h>
#include <stdlib.h>

#include "arvore.h"

int geranum(){
    return rand()%100;
}

void insere(NO **r, int valor){
    NO *novoNo;

    if( *r==NULL ) {
        novoNo = malloc( sizeof(NO) );
        if( !novoNo ) exit(-1);
        novoNo->dado = valor;
        // novoNo->pai    = NULL;
        novoNo->filhoE = NULL;
        novoNo->filhoD = NULL;
        *r=novoNo;
    }
    else {
        if( (*r)->dado > valor ) 
            insere( &((*r)->filhoE), valor ); 
        else
            insere( &((*r)->filhoD), valor );
    }
}

int altura(NO *r) {
    int altE, altD;

    if( r==NULL )
        return -1;
    
    altE = altura( r->filhoE );
    altD = altura( r->filhoD );
    
    if( altE > altD )
        return altE + 1;
    return altD + 1;
}

void erd(NO *r) {
    if( r==NULL ) return;

    erd(r->filhoE);
    printf("%d ", r->dado);
    erd(r->filhoD);
}


int main() {
    NO *raiz=NULL;
    int n;

    for( int i=0; i<40; i++){
        n = geranum();
        printf("%d ", n);
        insere( &raiz, n);
    }
    printf("\n\n");

    printf("Altura da árvore binária: %d \n\n", altura(raiz));

    erd(raiz);

}