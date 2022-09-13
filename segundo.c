#include <stdio.h>

int main() {
    int q, val;
    int acum=0;

    printf("Quantos valores? ");
    scanf("%d", &q);

    printf("Lendo %d valores\n", q);

    for(int i=0; i < q; i++ ) {
        printf("%d > ",i);
        scanf("%d", &val);
        acum += val;
    }

    printf("\nA média é: %f \n\n", (float)acum/q  );

}