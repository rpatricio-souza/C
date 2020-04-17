#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
entradas:
Rafael Patricio de Souza
Rua Guarani
20/05/1990
Sao Jose dos Campos
12211-740
rpatricio.souza@gmail.com

*/

typedef struct dados_pessoais {
    char nome[30];
    char endereco[50];
    char data_nasc[11];
    char cidade[25];
    char cep[10];
    char email[25];
}DADOS;

int main()
{
    DADOS p;
    int i, a=0;

    printf("Digite seus dados pessoais:");
    printf("\nNome: ");
    gets(p.nome);
    fflush(stdin);

    printf("Endereco: ");
    gets(p.endereco);
    fflush(stdin);

    printf("Data de Nascimento (dd/mm/aaaa): ");
    gets(p.data_nasc);
    fflush(stdin);

    printf("Cidade: ");
    gets(p.cidade);
    fflush(stdin);

    printf("CEP (ddddd-ddd): ");
    gets(p.cep);
    fflush(stdin);

    printf("E-mail: ");
    gets(p.email);
    fflush(stdin);

    if(p.data_nasc[2]!='/' || p.data_nasc[5]!='/')
        printf("\nFormato de Data invalido!");

    if(p.cep[5]!='-')
        printf("\nFormato de CEP invalido!");

    for(i=0;i<strlen(p.email);i++){
        if(p.email[i]=='@')
            a++;
        if(a>1)
            break;
    }
    if(a!=1)
        printf("\nFormato de E-mail invalido!");

    return 0;
    system("PAUSE");
}
