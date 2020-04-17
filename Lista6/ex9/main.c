#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
entradas:
3
5
-7
18

*/

typedef struct complexo{
    float z;
    float w;
}COMPLEXO;

int main()
{
    COMPLEXO c1, c2;

    printf("Digite dois numeros complexos:\n");
    printf("1o\nParte Real: ");
    scanf("%f", &c1.z);
    fflush(stdin);
    printf("Parte Imaginaria: ");
    scanf("%f", &c1.w);
    fflush(stdin);

    printf("\n2o\nParte Real: ");
    scanf("%f", &c2.z);
    fflush(stdin);
    printf("Parte Imaginaria: ");
    scanf("%f", &c2.w);
    fflush(stdin);

    printf("\nSoma = %.2f + %.2fi", c1.z+c2.z, c1.w+c2.w);
    printf("\nSubtracao = %.2f + %.2fi", c1.z-c2.z, c1.w-c2.w);
    printf("\nProduto = %.2f + %.2fi", c1.z*c2.z, c1.w*c2.w);
    printf("\nModulo:\n%.2f + %.2fi\n%.2f + %.2fi\n\n", fabs(c1.z), fabs(c1.w), fabs(c2.z), fabs(c2.w));

    return 0;
    system("PAUSE");
}
