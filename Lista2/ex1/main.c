#include <stdio.h>
#include <stdlib.h>

int main()
{
    float base, altura, area, perimetro;
    printf("Digite a base do retangulo: ");
    scanf("%f", &base);
    printf("Digite a altura do retangulo: ");
    scanf("%f", &altura);

    area = base * altura;
    perimetro = base * 2 + altura * 2;

    printf("\nArea = %.2f", area);
    printf("\nPerimetro = %.2f", perimetro);

    return 0;
}
