#include <stdio.h>
#include <stdlib.h>

#include "arvore.h"

int geranum(){
    return rand()%100;
}

int fb( NO *subraiz ) {
	return altura(subraiz->filhoD) - altura(subraiz->filhoE);	
}

void rotacaoDireita( NO **subraiz ) {
	NO *u;
	
	u = (*subraiz)->filhoE;	
	(*subraiz)->filhoE = u->filhoD;
	u->filhoD = *subraiz;
	*subraiz = u;
}

NO *encontra(NO *raiz, int query ) {
	if( ! raiz )   // raiz é NULL
		return NULL;
	
	if( raiz->dado == query )
		return raiz;
	if( raiz->dado > query ) {
		return encontra( raiz->filhoE, query);
	}
	else {   // Menor
		return encontra( raiz->filhoD, query);
	}
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

void erdFB(NO *r) {
    if( r==NULL ) return;

    erdFB(r->filhoE);
    printf("%d FB: %d\n", r->dado, fb(r) );
    erdFB(r->filhoD);
}

int main() {
    NO *raiz=NULL;
    NO *p;
    
    int n;

//    for( int i=0; i<40; i++){
//        n = geranum();
//        printf("%d ", n);
//        insere( &raiz, n);
//    }
//   printf("\n\n");
//    printf("Altura da árvore binária: %d \n\n", altura(raiz));
//
//    erd(raiz);  
//    printf("Altura da árvore binária: %d \n\n", altura(raiz));

    insere( &raiz, 42);
    insere( &raiz, 88); 
    insere( &raiz, 15);
    insere( &raiz, 6);   
    insere( &raiz, 27);   
    insere( &raiz, 4);   
     
    erdFB(raiz);  
    
    //p = encontra(raiz, 42);
    if( !p ) {
    	printf("Valor não encontrado.\n\n");
    	return -1;
    }
    
    rotacaoDireita( &raiz );
    printf("\napós rotação direita\n");
    erdFB(raiz);  
    	


}
