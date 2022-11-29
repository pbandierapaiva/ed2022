#include <stdio.h>
#include <stdlib.h>

#include "arvore.h"

int geranum(){
    return rand()%100;
}

int fb( NO *subraiz ) {
	return altura(subraiz->filhoD) - altura(subraiz->filhoE);	
}

NO *naoAVL( NO *no ) {
    int fator;
    NO *ptr;

    fator = fb( no );
    if( fator > 1 || fator < -1 )
        return no;
    if( no->filhoE ) {
        ptr = naoAVL(no->filhoE);
        if( ptr ) return ptr;
    }
    if( no->filhoD ) {
        ptr = naoAVL(no->filhoD);
        if( ptr ) return ptr;
    }
    return 0;
}

void rotacaoDireita( NO **subraiz ) {
	NO *u;
	
	u = (*subraiz)->filhoE;	
	(*subraiz)->filhoE = u->filhoD;
	u->filhoD = *subraiz;
	*subraiz = u;
}

void rotacaoDuplaDireita( NO **subraiz ) {
    rotacaoEsquerda( &( (*subraiz)->filhoE ));
    rotacaoDireita( subraiz );
}

void rotacaoDuplaEsquerda( NO **subraiz ) {
    rotacaoDireita( &( (*subraiz)->filhoE ));
    rotacaoEsquerda( subraiz );
}

void rotacaoEsquerda( NO **subraiz ) {
	NO *u;
	
	u = (*subraiz)->filhoD;	
	(*subraiz)->filhoD = u->filhoE;
	u->filhoE = *subraiz;
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

NO *encontraPai( NO *q, NO **raiz ){
    NO *pai;

    if( q=(*raiz) )
        return *raiz;
    pai = encontraPai( q, &( (*raiz)->filhoE) );
    if( pai ) return pai;
    pai = encontraPai( q, &((*raiz)->filhoD) );
    if( pai ) return pai;
    return 0;
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
    NO *p, *paux;
    
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
    insere( &raiz, 30);   

    erdFB(raiz);  

    while( 1 ) {
        p = naoAVL(raiz);
        if( !p )
            break;
        paux = encontraPai( p, &raiz ); 
        if( !paux ){
            printf("Erro - pai não encontrado");
            return 0;
        }

        if( fb( paux ) > 1 ) {
            if( fb(paux->filhoD)<0 )
                rotacaoDuplaEsquerda( &paux );
            else    
                rotacaoEsquerda( &paux );
        }
        else {
            if( fb(paux->filhoE)<0 )
                rotacaoDuplaDireita( &paux );
            else    
                rotacaoDireita( &paux );
        }
    }

    printf("Após operação AVL\n\n");
    erdFB(raiz);  



    // p = naoAVL(raiz);
    // if( p ) 
    //     printf("Árvore NÃO AVL no nó %d\n ", p->dado);
    // else
    //     printf("Árvore AVL");

    // //p = encontra(raiz, 42);
    // // if( !p ) {
    // // 	printf("Valor não encontrado.\n\n");
    // // 	return -1;
    // // }
    
    // rotacaoDuplaDireita( &raiz );
    // printf("\napós rotação dupla direita\n");
    // erdFB(raiz);  
 
    // p = naoAVL(raiz);
    // if( p ) 
    //     printf("Árvore NÃO AVL no nó %d\n ", p->dado);
    // else
    //     printf("Árvore AVL");
    	


}
