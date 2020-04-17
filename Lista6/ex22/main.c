#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*
entradas:
Rafael Patricio de Souza
Rua Guarani, 450
Santana
Sao Jose dos Campos
Sao Paulo
12211-740
1620.00
461626676
39409432820
solteiro
+5512988394295
29
M
Aline Cristine
Rua Guarani, 450
Santana
Sao Jose dos Campos
Sao Paulo
12211-740
1600.00
43657867X
39409432820
solteiro
+5512988394295
30
f
Gabriel Patricio de Souza
Rua Guarani, 450
Santana
Sao Jose dos Campos
Sao Paulo
12211-740
800.00
481626678
39409432820
solteiro
+5512988394295
22
M
Joaquim de Souza
Rua Guarani, 450
Santana
Sao Jose dos Campos
Sao Paulo
12211-740
1500.00
30162667X
39409432820
casado
+5512988394295
64
m
Zilda Patricio de Souza
Rua Guarani, 450
Santana
Sao Jose dos Campos
Sao Paulo
12211-740
1100.00
431626673
39409432820
solteiro
+5512988394295
60
F
48162667

*/

typedef struct enderecos{
    char rua[30];
    char bairro[30];
    char cidade[30];
    char uf[20];
    char cep[10];
}ENDERECO;

typedef struct cadastros{
    char nome[30];
    ENDERECO end;
    float salario;
    char rg[13];
    char cpf[15];
    char est_civil[15];
    char tel[16];
    int idade;
    char sexo;
}CADASTRO;


void maiorIdade(CADASTRO c[5]){
    int i, m, maior;
    for(i=0;i<5;i++){
        if(i==0){
            maior=c[i].idade;
            m=i;
        }
        else if(c[i].idade>maior){
            maior=c[i].idade;
            m=i;
        }
    }
    printf("\nA pessoa mais velha e %s\n", c[m].nome);
}


void filtraSexo(CADASTRO c[5], char s){
    int i;
    printf("\nPessoas do sexo ");
    if(s=='F')
        printf("Feminino:");
    else
        printf("Masculino:");
    for(i=0;i<5;i++)
        if(c[i].sexo==s)
            printf("\n%s", c[i].nome);
    printf("\n");
}


void filtraSalario(CADASTRO c[5], float salario){
    int i;
    printf("\nPessoas com salario acima de R$%.2f", salario);
    for(i=0;i<5;i++)
        if(c[i].salario>salario)
            printf("\n%s", c[i].nome);
    printf("\n");
}


void buscaRG(CADASTRO c[5], char id[13]){
    int i, f=0;
    for(i=0;i<5;i++){
        if(strcmp(c[i].rg, id)==0){
            printf("\nO RG %s pertence a %s\n", id, c[i].nome);
            f=1;
        }
    }
    if(f==0)
        printf("\nRG nao encontrado...\n");
}


int main()
{
    CADASTRO c[5];
    int i;
    char id[13];

    printf("Entre com os dados para preencher 5 cadastros.");
    for(i=0;i<5;i++){ //leitura de todos os dados
        printf("\nCadastro %d", i+1);
        printf("\nNome: ");
        gets(c[i].nome);
        fflush(stdin);

        printf("Endereco");
        printf("\nRua: ");
        gets(c[i].end.rua);
        fflush(stdin);

        printf("Bairro: ");
        gets(c[i].end.bairro);
        fflush(stdin);

        printf("Cidade: ");
        gets(c[i].end.cidade);
        fflush(stdin);

        printf("Estado: ");
        gets(c[i].end.uf);
        fflush(stdin);

        printf("CEP: ");
        gets(c[i].end.cep);
        fflush(stdin);

        printf("Salario: R$");
        scanf("%f", &c[i].salario);
        fflush(stdin);

        printf("RG: ");
        gets(c[i].rg);
        fflush(stdin);

        printf("CPF: ");
        gets(c[i].cpf);
        fflush(stdin);

        printf("Estado Civil: ");
        gets(c[i].est_civil);
        fflush(stdin);

        printf("Telefone: ");
        gets(c[i].tel);
        fflush(stdin);

        printf("Idade: ");
        scanf("%d", &c[i].idade);
        fflush(stdin);

        printf("Sexo (M ou F): ");
        scanf("%c", &c[i].sexo);
        fflush(stdin);
        c[i].sexo=toupper(c[i].sexo);
    }

    maiorIdade(c);
    filtraSexo(c, 'M');
    filtraSalario(c, 1000.00);
    printf("\nDigite um RG para buscar: ");
    gets(id);
    fflush(stdin);
    buscaRG(c, id);

    return 0;
    system("PAUSE");
}
