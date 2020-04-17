#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct super_trunfo_dinossauros{
    float altura;
    float comprimento;
    float peso;
    int viveu_ha;
}TRUNFO;

int main()
{
    TRUNFO jogador1[5], jogador2[5];
    int i;

    srand(time(NULL));

    for(i=0;i<5;i++){
        jogador1[i].altura=rand()%20;
        jogador1[i].comprimento=rand()%20;
        jogador1[i].peso=rand()%10000;
        jogador1[i].viveu_ha=rand()%100;
        jogador2[i].altura=rand()%20;
        jogador2[i].comprimento=rand()%20;
        jogador2[i].peso=rand()%10000;
        jogador2[i].viveu_ha=rand()%100;
    }

    printf("\nCartas do 1o Jogador:");
    for(i=0;i<5;i++){
        printf("\nAltura: %.2fm", jogador1[i].altura);
        printf("\nComprimento: %.2fm", jogador1[i].comprimento);
        printf("\nPeso: %.2fKg", jogador1[i].peso);
        printf("\nViveu ha %d milhoes de anos\n", jogador1[i].viveu_ha);
    }

    printf("\nCartas do 2o Jogador:");
    for(i=0;i<5;i++){
        printf("\nAltura: %.2fm", jogador2[i].altura);
        printf("\nComprimento: %.2fm", jogador2[i].comprimento);
        printf("\nPeso: %.2fKg", jogador2[i].peso);
        printf("\nViveu ha %d milhoes de anos\n", jogador2[i].viveu_ha);
    }

    return 0;
    system("PAUSE");
}
