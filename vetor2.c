// Faz merge de dois vetores

#include <stdio.h>
#include <math.h>

#define MAXLEN 5

int main() {
        int a[MAXLEN], b[MAXLEN];
        int junto[MAXLEN*2];
        int num;
        
        printf("Entre com vetor A: \n");  
        for( int i=0; i<MAXLEN; i++) {
                printf("> ");
                scanf("%d", &num);
                if(i>0) {
                	if(num>a[i-1]) {
                		printf("Os valores têm que ser ordenados\n");
                		return(-1);
                		}
                	}
                a[i] = num;
                }
        printf("Entre com vetor B: \n");      
        for( int i=0; i<MAXLEN; i++) {
                printf("> ");
                scanf("%d", &num);
              	if(i>0) {
              		if(num>a[i-1]) {
                		printf("Os valores têm que ser ordenados\n");
                		return(-1);
                		}
                	}
                b[i] = num;
                }                
                
                


}

