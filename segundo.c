#include <stdio.h>

int main() {
    int q, val;
    int acum=0;

    printf("Quantos valores? ");
    scanf("%d", &q);

    printf("Lendo %d valores\n", q);

    for(int i=0; i < q; i++ ) {
        scanf("%d", &val);
        acum += val;
    }

    printf("%f", (float)acum/q  );

}