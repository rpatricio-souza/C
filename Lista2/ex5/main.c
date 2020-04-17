#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    float a, b, c;
    printf("Digite o 1o lado do triangulo: ");
    scanf("%f", &a);
    printf("Digite o 2o lado do triangulo: ");
    scanf("%f", &b);
    printf("Digite o 3o lado do triangulo: ");
    scanf("%f", &c);

    if ((fabs(b - c) < a && a < b + c) && (fabs(a - c) < b && b < a + c) && (fabs(a - b) < c && c < a + b)){
        printf("\nAs retas informadas podem formar um triangulo!");

        if (a == b && a == c)
            printf("\nO triangulo formado e Equilatero!");
        else if ((a == b && b != c) || (a == c && c != b) || (b == c && c != a))
            printf("\nO triangulo formado e Isosceles!");
        else
            printf("\nO triangulo formado e Escaleno!");
    }
    else
        printf("Os valores informados nao formam um triangulo!");

    return 0;
}
