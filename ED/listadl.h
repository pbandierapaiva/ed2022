// listadl.h
// Estrutura e protótipos de funções de 
// EAD que utilizam Listas duplamente ligadas

typedef struct No {
	char nome[80];
	struct No *prox;
    struct No *ant;
} NO;

// Protótipos de funções para Lista 
int removeNo( NO **, NO * );
void insereNo( NO **, char * );
void imprimeLista( NO * );
void imprimeOrdenado(NO *);
void imprimeInverso(NO *);

// Protótipos de funções para Fila
void enfileira( NO **, char * );
void desenfileira( NO **, char * );
void espia( NO *, char * );
 
 
