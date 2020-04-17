#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
entradas:
3
3
3

4
3
3

3
4
5

10
2
3

*/

int main()
{
    float a, b, c, area, perimetro, p;
    printf("Digite o 1o lado do triangulo: ");
    scanf("%f", &a);
    printf("Digite o 2o lado do triangulo: ");
    scanf("%f", &b);
    printf("Digite o 3o lado do triangulo: ");
    scanf("%f", &c);

    // Verifica se os lados informados podem formar um triangulo
    if ((fabs(b - c) < a && a < b + c) && (fabs(a - c) < b && b < a + c) && (fabs(a - b) < c && c < a + b)){

        perimetro = a + b + c;
        p = perimetro/2;
        area = sqrt(p*(p-a)*(p-b)*(p-c));

        printf("\nPerimetro: %.2fm\nArea = %.2fm^2\n", perimetro, area);
    }
    else
        printf("\nOs valores informados nao formam um triangulo!\n");

    return 0;
}
