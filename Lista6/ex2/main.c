#include <stdio.h>
#include <stdlib.h>

/*
entradas:
Rafael Patricio de Souza
29
Rua Guarani

*/

typedef struct dados{
    char nome[30];
    int idade;
    char endereco[100];
}PESSOA;

int main()
{
    PESSOA p;

    printf("Digite seus dados:");
    printf("\nNome: ");
    gets(p.nome);
    fflush(stdin);
    printf("Idade: ");
    scanf("%d", &p.idade);
    fflush(stdin);
    printf("Endereco: ");
    gets(p.endereco);
    fflush(stdin);

    printf("\nDados Cadastrais:\n%s\n%d\n%s\n", p.nome, p.idade, p.endereco);

    return 0;
    system("PAUSE");
}
