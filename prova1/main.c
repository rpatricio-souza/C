#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*
Elabore um programa, usando Linguagem de Programacao C, que leia de nomes de pessoas via teclado
e armazene-os em uma matriz. O programa deve conter funcoes para:
a)verificar se somente caracteres alfabeticos foram digitados.
b)verificar se existem e quantas sao as pessoas que possuem o mesmo pre-nome.
    Exemplo: Renato Barbosa e Renato Vieira (2)

entradas:
Rafael Patricio
S
Aline CristineS2
Aline Cristine
S
Joaquim de Souza
S
Zilda Patricio
s
Rafael de Souza
S
Aline Souza
S
Rafael Patricio de Souza
S
Rafael P Souza
s
Aline C Souza
c
n

*/

int alfabetico(char nome[]){
    int i=0;
    for(i=0;nome[i]!='\0';i++)
        if((tolower(nome[i])<'a' || tolower(nome[i])>'z') && nome[i]!=' ')
            return 0;
    return 1;
}

void nomesIguais(char nomes[50][100], int tam){
    int i, j, cont=1;
    char *p, aux[50][100], auxInt[2];

    for(i=0;i<tam;i++)
        strcpy(aux[i], nomes[i]);

    //faz um split por 'espaco' na matriz, guardando apenas o 1o nome de cada string
    for(i=0;i<tam;i++)
        p=strtok(aux[i], " ");

    printf("\nPessoas com o mesmo pre-nome:\n");
    for(i=0;i<tam;i++){
        for(j=i+1;j<tam;j++){
            if(strcmp(aux[i], aux[j])==0){
                printf("%s e ", nomes[j]);
                sprintf(auxInt, "%d", j); //converte o j em string
                strcat(aux[j], auxInt); //adiciona o j convertido ao final da string, assim evitamos redundancia dos nomes
                cont++;
            }
        }
        if(cont>1)
            printf("%s (%d)\n", nomes[i], cont);
        cont=1;
    }
    //imprimir(aux, tam);
}

void imprimir(char s[50][100], int tam){
    int i;
    printf("\n");
    for(i=0;i<tam;i++)
        puts(s[i]);
    printf("\n");
}

int main()
{
    int i=0, tam=0, nomeCorreto;
    char continuar='S', nomes[50][100];

    while(toupper(continuar)=='S'){
        printf("\nDigite o nome de uma pessoa: ");
        gets(nomes[i]);
        fflush(stdin);

        nomeCorreto=alfabetico(nomes[i]);
        while(nomeCorreto==0){
            printf("\nCaracteres invalidos foram digitados!");
            printf("\nDigite apenas caracteres alfabeticos: ");
            gets(nomes[i]);
            fflush(stdin);
            nomeCorreto=alfabetico(nomes[i]);
        }

        printf("Deseja continuar? (S ou N)\nEscolha: ");
        scanf("%c", &continuar);
        fflush(stdin);

        while(toupper(continuar)!='S' && toupper(continuar)!='N'){
            printf("\nEscolha Invalida!\nDigite S para Sim ou N para nao\nEscolha: ");
            scanf("%c", &continuar);
            fflush(stdin);
        }

        tam++;
        i++;
    }
    nomesIguais(nomes, tam);
    //imprimir(nomes, tam);
    return 0;
    system("pause");
}
