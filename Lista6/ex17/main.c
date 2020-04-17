#include <stdio.h>
#include <stdlib.h>

/*
entradas:
Geladeira
0.25
24
TV 32''
0.1
8
PS4
0.135
3
PC Gamer
0.6
4
Microondas
2.0
0.183

*/

typedef struct eletrodomesticos{
    char nome[15];
    float potencia;
    float horas_ativo;
    float consumo_relativo;
}ELETRO;

int main()
{
    ELETRO e[5];
    int i, t;
    float consumo_total=0.0;

    printf("Digite as informacoes de 5 eletrodomesticos.");
    for(i=0;i<5;i++){
        printf("\n%do", i+1);
        printf("\nNome: ");
        gets(e[i].nome);
        fflush(stdin);

        printf("Potencia (kW): ");
        scanf("%f", &e[i].potencia);
        fflush(stdin);

        printf("Tempo ativo por dia (h): ");
        scanf("%f", &e[i].horas_ativo);
        fflush(stdin);
    }

    printf("\nDigite um tempo (dias) para calcularmos o consumo total da casa e o consumo relativo de cada eletrodomestico.");
    printf("\nTempo (dias): ");
    scanf("%d", &t);
    fflush(stdin);

    for(i=0;i<5;i++)
        consumo_total+=e[i].potencia*e[i].horas_ativo*t;

    printf("\nConsumo Total = %.2fkWh\n", consumo_total);
    for(i=0;i<5;i++){
        e[i].consumo_relativo=((e[i].potencia*e[i].horas_ativo*t)/consumo_total)*100;
        printf("\nConsumo Relativo do(a) %s = %.2f%%", e[i].nome, e[i].consumo_relativo);
    }

    return 0;
    system("PAUSE");
}
