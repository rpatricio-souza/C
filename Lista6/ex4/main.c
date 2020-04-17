#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
entradas:
50463
Rafael Patricio de Souza
6.3
6
7

52525
Aline Cristine
10
9.5
9.2

66666
Gabriel Patricio
6
6
6.6

111
Fulaninho
0.8
3.2
1.4

2222
Ciclaninho
5.1
6.2
2.9

*/

typedef struct alu{
    int matricula;
    char nome[30];
    float notas[3];
}ALUNO;

void maiorNota(ALUNO a[5]){
    int i;
    float maior=0.0;
    char alunoMaior[30];
    for(i=0;i<5;i++)
        if(a[i].notas[0]>maior){
            maior=a[i].notas[0];
            strcpy(alunoMaior, a[i].nome);
        }
    printf("\nAluno(a) com maior nota na 1a prova: %s\n\n", alunoMaior);
}


void media(ALUNO a[5]){
    int i, j;
    float media[5], maior=0.0, menor=0.0;
    char mediaMenor[30], mediaMaior[30];

    printf("\nSituacao:");
    for(i=0;i<5;i++){
        media[i]=0.0;
        for(j=0;j<3;j++)
            media[i]+=a[i].notas[j];
        media[i]/=3.0;

        printf("\n%s - %.2f - ", a[i].nome, media[i]);
        if(media[i]>=6)
            printf("Aprovado");
        else
            printf("Reprovado");

        if(i==0)
            menor=maior=media[i];
        if(media[i]<menor){
            menor=media[i];
            strcpy(mediaMenor,a[i].nome);
        }
        if(media[i]>maior){
            maior=media[i];
            strcpy(mediaMaior,a[i].nome);
        }
    }
    printf("\nAluno(a) com menor media: %s\n", mediaMenor);
    printf("\nAluno(a) com maior media: %s\n\n", mediaMaior);
}


int main()
{
    ALUNO a[5];
    int i, j;

    for(i=0;i<5;i++){
        printf("Digite os dados do %do aluno:", i+1);
        printf("\nMatricula: ");
        scanf("%d", &a[i].matricula);
        fflush(stdin);
        printf("\nNome: ");
        gets(a[i].nome);
        fflush(stdin);
        printf("\nNotas:");
        for(j=0;j<3;j++){
            printf("\n%da Prova: ", j+1);
            scanf("%f", &a[i].notas[j]);
            fflush(stdin);
        }
        printf("\n");
    }

    printf("Dados dos alunos:\n");
    for(i=0;i<5;i++){
        printf("\naluno(a) %d\nMatricula: %d", i+1, a[i].matricula);
        printf("\nNome: %s\n", a[i].nome);
    }

    maiorNota(a);
    media(a);

    return 0;
    system("PAUSE");
}
