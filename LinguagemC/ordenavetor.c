// Le vetor de int e ordena

#include <stdio.h>
#include <math.h>

#define MAXLEN 50

int leVetor( int *vet ) {
        int n, num;

        while (1) {
                printf("Entre com tamanho do vetor: ");
                scanf("%d", &n);
                if( n>MAXLEN ) {
                        printf("Número de elementos maior que o máximo permitido (%d)\n", MAXLEN);
                        continue;
                }
                break;
        }
        printf("Entre com vetor: \n");  
        for( int i=0; i<n; i++) {
                printf("> ");
                scanf("%d", &num);
                vet[i] = num;
                }
        return n;
}

void imprimeVetor(int *v, int n) {
        printf("\n");
        for (int i=0; i<n; i++)
                printf("%d ", v[i]);
        printf("\n");
}

int main() {
    int vetor[MAXLEN];
    int tam=0;
    int mudou=1;
    int tmp;

    tam = leVetor( vetor );
    printf("\nLeu vetor com %d elementos\n", tam);
    imprimeVetor(vetor, tam);

    while(mudou){
        mudou=0;
        for(int i=0;i<tam-1;i++){
            if( vetor[i]>vetor[i+1] ) {
                tmp = vetor[i];
                vetor[i] = vetor[i+1];
                vetor[i+1] = tmp;
                mudou=1;
            }
        }

         
    }
    
    imprimeVetor(vetor, tam);

}
