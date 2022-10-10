// Programa que lê uma matriz, alocando espaço dinamicamente 
// e retorna a transposta
//

#include <stdio.h>
#include <stdlib.h>

int *leMat(int *l, int *c) {
    int li, co;
    int val;
    int *m;

    printf("\nEntre com número de linhas: ");
    scanf("%d", &li);
    printf("\nEntre com número de colunas: ");
    scanf("%d", &co);
    *l = li;
    *c = co;
    m = malloc(li * co * sizeof(int) );
    if(!m){
        printf("Erro de alocação de memória.\n\n");
        exit(-1);
    }

    for(int i=0; i<li; i++) {
        for(int j=0; j<co; j++) {
            printf("%d,%d >", i, j);
            scanf("%d", &val);
            m[ (i*co) + j  ] = val;
        }
    }
    return m;
}

void imprimeMat(int *m, int l, int c) {
    for(int i=0; i< l; i++) {
        for(int j=0; j<c; j++) {
            printf("%d\t", m[(i*c)+j]);
        }
        printf("\n");
    }
}

int main() {
    int *mat;
    int lin,col;

    mat = leMat(&lin, &col);

    imprimeMat(mat, lin, col);

}
