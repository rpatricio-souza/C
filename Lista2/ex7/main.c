#include <stdio.h>
#include <stdlib.h>

/*
entradas:
75.6
1.74

*/

int main()
{
    float peso, altura, IMC;
    printf("Digite seu peso: ");
    scanf("%f", &peso);
    printf("Digite sua altura: ");
    scanf("%f", &altura);
    IMC = peso / (altura*altura);
    printf("\nIMC = %f", IMC);
    return 0;
}
