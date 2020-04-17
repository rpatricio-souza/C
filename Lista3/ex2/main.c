#include <stdio.h>
#include <stdlib.h>

/*
2) Faça um programa que apresente o menu de opções a seguir e permita ao usuário escolher a opção desejada,
 mostrando o seu resultado final. Verifique a possibilidade de opção inválida ou inexistente. Dica: use switch case.

Menu de Opções
A- Imposto
B- Novo salário
C- Classificação

Atenção: Cada opção deve ser implementada em uma função diferente.

A opção A deverá receber o salário de um funcionário, calcular e apresentar o valor do imposto de renda mensal, usando regras descritas em:
http://idg.receita.fazenda.gov.br/acesso-rapido/tributos/irpf-imposto-de-renda-pessoa-fisica

Confira se o resultado está coerente com:
http://www.receita.fazenda.gov.br/Aplicacoes/ATRJO/Simulador/simulador.asp?tipoSimulador=M


A opção B deverá receber o salário de um funcionário, calcular e mostrar o valor do novo salário, usando as regras a seguir:

SALÁRIO                                 AUMENTO %
Maiores que R$ 15000,00                     10%
De R$ 7500,00 a R$ 15000,00                 20%
De R$ 1000,00 a R$ 7500,00                  30%
Menores que R$1000,00                       40%

A opção C receberá o salário de um funcionário e mostrará a sua classificação usando a relação a seguir:

SALÁRIO CLASSIFICAÇÃO
Até R$ 7000,00 Mal remunerado
Maiores que R$ 7000,00 Bem remunerado
*/

float imposto(float salario){
    if(salario<=1903.98)
        return 0;
    else if(salario<=2826.65)
        return (salario-1903.98)*0.075;
    else if(salario<3751.06)
        return ((salario-2826.65)*0.15 + imposto(2826.65));
    else if(salario<4664.69)
        return ((salario-3751.05)*0.225 + imposto(3751.05));
    else
        return ((salario-4664.68)*0.275 + imposto(4664.68));
}

float aumento(float salario){
    if(salario<1000)
        return salario*1.4;
    else if(salario<7500.01)
        return salario*1.3;
    else if(salario<15000.01)
        return salario*1.2;
    else
        return salario*1.1;
}

void classificacao(float salario){
    if(salario<7000.01)
        printf("\nMal remunerado!\n");
    else
        printf("\nBem remunerado!\n");
}

int main()
{
    char escolha;
    float salario=4800;

    printf("A- Imposto;\n");
    printf("B- Novo Salario;\n");
    printf("C- Classificacao.\n");
    printf("Sua escolha: ");
    escolha=getch();

    switch(escolha){
        case 'a':
            if(salario!=0)
                printf("\nR$%.2f recebe um imposto de R$%.2f", salario, imposto(salario));
            else
                printf("\nSalario nao cadastrado!");
            break;

        case 'b':
            printf("\nSalario antigo = R$%.2f", salario);
            salario=aumento(salario);
            printf("\nNovo salario = R$%.2f", salario);
            break;

        case 'c':
            classificacao(salario);
            break;

        default:
            printf("Opcao Invalida!");
            break;
    }

    return 0;
    system("pause");
}
