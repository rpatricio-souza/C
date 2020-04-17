#include <stdio.h>
#include <stdlib.h>

/*
entrada:
Rafael Patricio de Souza
29
M
39409432820
20/05/1990
8190
Tecnico de Informatica
1620.00

*/

typedef struct funcionario{
    char nome[30];
    int idade;
    char sexo;
    char cpf[12];
    char data_nasc[11];
    int cod_setor;
    char cargo[30];
    float salario;
}FUNCIONARIO;


int main()
{
    FUNCIONARIO f;
    printf("Digite os dados do funcionario:\n");
    printf("Nome: ");
    gets(f.nome);
    fflush(stdin);

    printf("Idade: ");
    scanf("%d", &f.idade);
    fflush(stdin);

    printf("Sexo: ");
    scanf("%c", &f.sexo);
    fflush(stdin);

    printf("CPF: ");
    gets(f.cpf);
    fflush(stdin);

    printf("Data de Nascimento: ");
    gets(f.data_nasc);
    fflush(stdin);

    printf("Codigo do Setor: ");
    scanf("%d", &f.cod_setor);
    fflush(stdin);

    printf("Cargo: ");
    gets(f.cargo);
    fflush(stdin);

    printf("Salario: ");
    scanf("%f", &f.salario);
    fflush(stdin);

    printf("\nNome: %s", f.nome);
    printf("\nIdade: %d anos", f.idade);
    printf("\nSexo: %c", f.sexo);
    printf("\nCPF: %s", f.cpf);
    printf("\nData de Nascimento: %s", f.data_nasc);
    printf("\nCodigo do Setor: %d", f.cod_setor);
    printf("\nCargo: %s", f.cargo);
    printf("\nSalario: R$%.2f\n\n", f.salario);

    return 0;
    system("PAUSE");
}
