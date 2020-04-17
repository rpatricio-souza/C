#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1000

/*
entradas:
Steven Spielberg
5
Quentin Tarantino
9
Ridley Scott
4
Frank Darabont
2
Guilherme Del Toro
3
Tubarao
1975
130
Os Cacadores da Arca Perdida
1981
115
E.T.: O Extraterrestre
1982
121
Jurassic Park: O Parque dos Dinossauros
1993
127
O Resgate do Soldado Ryan
1998
170
Caes de Aluguel
1992
140
Pulp Fiction: Tempo de Violencia
1994
178
Jackie Brown
1997
160
Kill Bill - Volume 1
2003
112
Kill Bill - Volume 2
2004
138
Bastardos Inglorios
2009
153
Django Livre
2012
165
Os Oito Odiados
2015
187
Era uma vez em Hollywood
2019
160
Alien, o Oitavo Passageiro
1979
117
Blade Runner - O Cacador de Androides
1982
117
Gladiador
2000
171
Hannibal
2001
132
A Espera de um Milagre
1999
189
O Nevoeiro
2007
126
Hellboy
2004
132
O Labirinto do Fauno
2006
119
Círculo de Fogo
2013
132

*/

typedef struct filmes{
    char nome[50];
    int ano;
    int duracao;
}FILME;

typedef struct diretores{
    char nome[20];
    int qtd_film;
    FILME *film[MAX];
}DIRETOR;

int main()
{
    DIRETOR dir[5];
    int i, j, f=0;
    char busca[20]=" ", *p;

    printf("Digite as informacoes de 5 diretores.\n");
    for(i=0;i<5;i++){
        printf("\nNome: ");
        gets(dir[i].nome);
        fflush(stdin);

        printf("Quantidade de Filmes: ");
        scanf("%d", &dir[i].qtd_film);
        fflush(stdin);
    }

    printf("\nCADASTRO DOS FILMES\n");
    for(i=0;i<5;i++){
        printf("\n%s", dir[i].nome);
        for(j=0;j<dir[i].qtd_film;j++){
            dir[i].film[j]=malloc(sizeof(FILME));
            printf("\nNome do Filme:    ");
            gets(dir[i].film[j]->nome);
            fflush(stdin);

            printf("Ano de Lancamento: ");
            scanf("%d", &dir[i].film[j]->ano);
            fflush(stdin);

            printf("Duracao (em min):  ");
            scanf("%d", &dir[i].film[j]->duracao);
            fflush(stdin);
        }
    }

    printf("\n----------FILMES----------\n          Sistema de Busca");
    while(strcmp(busca,"")!=0){
        printf("\nDigite o nome do Diretor e pressione ENTER(deixe vazio para finalizar): ");
        gets(busca);
        fflush(stdin);
        f=0;
        if(strcmp(busca,"")!=0){
            for(i=0;i<5;i++){
                p=strstr(strupr(dir[i].nome), strupr(busca));//strupr converte a string para maiusculo
                if(p!=NULL){ // substring encontrada
                    f=1; //f=1 indicara para o programa que a substring foi encontrada
                    printf("\n%s\n", dir[i].nome);
                    for(j=0;j<dir[i].qtd_film;j++){
                        printf("\n%s", dir[i].film[j]->nome);
                        printf("\n%d", dir[i].film[j]->ano);
                        printf("\n%dmin\n", dir[i].film[j]->duracao);
                    }
                }
            }
            if(f==0)
                printf("\nDiretor nao encontrado...\n");
            else
                printf("\n");
        }
    }

    return 0;
    system("PAUSE");
}
