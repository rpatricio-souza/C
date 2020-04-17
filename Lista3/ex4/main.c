#include <stdio.h>
#include <stdlib.h>

/*
4) Faça um programa que contenha as seguintes características
a) variáveis -> char nome[20], int idade, float peso e float altura
b) funções -> void envelhecer(int anos), void engordar(float kg), void emagrecer(float kg), void crescer(),
float Imc (float peso,  float altura)
Obs: Por padrão, a cada ano que a pessoa envelhece, sendo a idade dela menor que 21 anos, ela deve crescer 0,5 cm.
A função main fornecerá um menu para que o usuário escolha a opção desejada.

entradas:
Rafael Patricio
13
75.6
1.74

*/

int idade;
float peso, altura;

void envelhecer(int anos){
    int i;
    for(i=0;i<anos;i++){
        if(idade<21)
            crescer();
        idade++;
    }
}

void engordar(float kg){
    peso+=kg;
}

void emagrecer(float kg){
    peso-=kg;
}

void crescer(){
    altura+=0.005;
}

float Imc (float peso,  float altura){
    return peso/(altura*altura);
}

int main()
{
    char nome[20], escolha;
    int anos, verdadeiro=1;
    float kg;

    printf("Digite os seguintes dados: ");
    printf("\nNome: ");
    scanf("%[^\n]s", &nome); // le frase incluindo os espacos
    printf("Idade: ");
    scanf("%d", &idade);
    printf("Peso: ");
    scanf("%f", &peso);
    printf("Altura: ");
    scanf("%f", &altura);

    while(verdadeiro==1){
        printf("\nEscolha uma opcao:");
        printf("\nA- Envelhecer;");
        printf("\nB- Engordar;");
        printf("\nC- Emagrecer;");
        printf("\nD- IMC;");
        printf("\nS- Sair.");
        printf("\nSua escolha: ");
        escolha=getch();

        if(escolha=='s'){
            printf("\n\nnome: %s\nidade: %d anos\npeso: %.2fKg\naltura: %.2fm\n", nome, idade, peso, altura);
            break;
        }
        switch(escolha){
            case 'a':
                printf("\nEnvelhecer quantos anos? ");
                scanf("%d", &anos);
                envelhecer(anos);
                break;
            case 'b':
                printf("\nEngordar quantos kilos? ");
                scanf("%f", &kg);
                engordar(kg);
                break;
            case 'c':
                printf("\nEmagrecer quantos kilos? ");
                scanf("%f", &kg);
                emagrecer(kg);
                break;
            case 'd':
                printf("\nIMC = %.2f", Imc(peso, altura));
                break;
            default:
                printf("\nOpcao invalida!");
                break;
        }
    }

    return 0;
    system("pause");
}
