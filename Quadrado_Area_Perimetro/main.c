#include <stdio.h>
#include <stdlib.h>

int main()
{
    float area, perimetro, lado;

    printf("Digita o tamanho do lado do quadrado: ");
    scanf("%f", &lado);

    area = lado * lado;
    perimetro = lado * 4;

    printf("\nArea do quadrado = %.2f", area);
    printf("\nPerimetro do quadrado = %.2f", perimetro);
    return 0;
}
