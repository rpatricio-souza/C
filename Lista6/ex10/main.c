#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
entradas:
Rafael Patricio
Rua Guarani
+55 12 98888888
Aline Cristine
Rua do Senai
995252525
Pessoa 3
Rua dos Bobos, no: 0
31 991112222
Fulano
Av. sem nome, Santana
+55 11 999882222
Fulaninho
Travessa Sao Lourenco
997776666

*/

typedef struct cadastro_pessoas{
    char nome[30];
    char endereco[40];
    char telefone[17];
}PESSOA;


void ordena(PESSOA p[5]){
    int i, j, k, tam;
    char aux[30];
    for(i=1;i<5;i++){
        for(j=0;j<4;j++){
            if(strlen(p[j].nome)>strlen(p[j+1].nome))
                tam=strlen(p[j+1].nome);
            else
                tam=strlen(p[j].nome);
            for(k=0;k<tam;k++){
                if(p[j].nome[k]>p[j+1].nome[k]){
                    strcpy(aux,p[j+1].nome);
                    strcpy(p[j+1].nome,p[j].nome);
                    strcpy(p[j].nome,aux);

                    strcpy(aux,p[j+1].endereco);
                    strcpy(p[j+1].endereco,p[j].endereco);
                    strcpy(p[j].endereco,aux);

                    strcpy(aux,p[j+1].telefone);
                    strcpy(p[j+1].telefone,p[j].telefone);
                    strcpy(p[j].telefone,aux);
                    break;
                }
                else if(p[j].nome[k]<p[j+1].nome[k])
                    break;
            }
        }
    }
}


int main()
{
    PESSOA p[5];
    int i;

    printf("Digite os dados de 5 pessoas");
    for(i=0;i<5;i++){
        printf("\n%da\nNome: ", i+1);
        gets(p[i].nome);
        fflush(stdin);
        printf("Endereco: ");
        gets(p[i].endereco);
        fflush(stdin);
        printf("Telefone: ");
        gets(p[i].telefone);
        fflush(stdin);
    }

    ordena(p);

    printf("\nDados Cadastrados");
    for(i=0;i<5;i++){
        printf("\nCadastro %d\nNome: %s", i+1, p[i].nome);
        printf("\nEndereco: %s", p[i].endereco);
        printf("\nTelefone: %s\n", p[i].telefone);
    }

    return 0;
    system("PAUSE");
}
