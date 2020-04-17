#include <stdio.h>
#include <stdlib.h>

/*D)  Elabore um programa em C que leia uma distância a ser percorrida em Km, o preço do litro do combustível,
 o consumo, os gastos com manutenção do veículo e com pedágio.
  Em seguida, deverá ser impresso o gasto por km rodado.

entradas:
104
3.99
11
300
14.10

*/

float kilometragem(float distancia, float precoCombustivel, float consumo, float gastoManutencao, float pedagio){
    return ((distancia/consumo)*precoCombustivel + gastoManutencao + pedagio)/distancia;
}

int main()
{
    float distancia, precoCombustivel, consumo, gastoManutencao, pedagio, gastoKM;

    printf("Entre com os valores:\n");
    printf("Distancia a ser percorrida (Km): ");
    scanf("%f", &distancia);
    printf("Preco do litro de combustivel: ");
    scanf("%f", &precoCombustivel);
    printf("Consumo do veiculo (Km/l): ");
    scanf("%f", &consumo);
    printf("Gasto com manutencao do veiculo (ao mes): ");
    scanf("%f", &gastoManutencao);
    printf("Pedagio: ");
    scanf("%f", &pedagio);

    gastoKM = kilometragem(distancia, precoCombustivel, consumo, gastoManutencao, pedagio);
    printf("\nGasto por Km rodado = R$%.2f", gastoKM);

    return 0;
    system("pause");
}
