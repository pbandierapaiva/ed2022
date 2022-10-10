// Faz merge de dois vetores

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
                if(i>0) {
                	if(num <= vet[i-1]) {
                		printf("Os valores têm que ser ordenados e distintos\n");
                		return(-1);
                		}
                	}
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
        int a[MAXLEN], b[MAXLEN];
        int juntos[MAXLEN*2];
        int nA, nB;
        int x=0, ia=0, ib=0;
         
        nA = leVetor( a );
        nB = leVetor( b );

        imprimeVetor(a,nA);
        imprimeVetor(b,nB);

        while( ia < nA || ib < nB ) {
                if(ia==nA) {
                        for(;ib<nB;ib++) {
                                juntos[x] = b[ib];
                                ib++;
                                x++;
                        }
                        break;
                }
                if(ib==nB) {
                        for(;ia<nA;ia++) {
                                juntos[x] = a[ia];
                                ia++;
                                x++;
                        }
                        break;
                }
                if(a[ia] == b[ib]){
                        juntos[x] = a[ia];
                        x++; ia++; ib++;
                }
                else if(a[ia] < b[ib]) {
                        juntos[x] = a[ia];
                        x++; ia++;
                }
                else {  // a[ia] >  b[ib]
                        juntos[x] = b[ib];
                        x++, ib++;
                }
        }    
        imprimeVetor(juntos, x);
}
