// Estrutura de dados para ABB

typedef struct no {
    int dado;
    struct no *pai;
    struct no *filhoE;
    struct no *filhoD;
} NO;



int geranum();
int fb( NO *subraiz );
NO *encontra(NO *raiz, int query );
void rotacaoDireita( NO **subraiz );
void insere(NO **r, int valor);
int altura(NO *r);
void erd(NO *r);
void erdFB(NO *r);


