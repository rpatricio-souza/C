#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
entradas:
50463
Rafael Patricio de Souza
9.2
52525
Aline Cristine
10
66666
Gabriel Patricio
6.6
111
Fulaninho
0.8
2222
Ciclaninho
5.1
6969
Epaminondas
2.9
1317
Bolsominion
4.9
666
Capeta Jr.
6.66
3133
Jolinelson
7.3
2829
Kolynos
3.1

*/

typedef struct alunos{
    int matricula;
    char nome[30];
    float media;
}ALUNO;


void situacao(ALUNO a[10]){
    ALUNO aprovados[10], reprovados[10];
    int i, j=0, k=0;

    for(i=0;i<10;i++){
        if(a[i].media>=5.0){
            aprovados[j].matricula=a[i].matricula;
            strcpy(aprovados[j].nome,a[i].nome);
            aprovados[j].media=a[i].media;
            j++;
        }
        else{
            reprovados[k].matricula=a[i].matricula;
            strcpy(reprovados[k].nome,a[i].nome);
            reprovados[k].media=a[i].media;
            k++;
        }
    }

    printf("\n\nAprovados:\n");
    printf("Nome                            |     Media     ");
    for(i=0;i<j;i++)
        printf("\n%s                              |     %.2f", aprovados[i].nome, aprovados[i].media);

    printf("\n\nReprovados:\n");
    printf("Nome                            |     Media     ");
    for(i=0;i<k;i++)
        printf("\n%s                              |     %.2f", reprovados[i].nome, reprovados[i].media);
}


int main()
{
    ALUNO a[10];
    int i;

    for(i=0;i<10;i++){
        printf("Digite os dados do %do aluno:", i+1);
        printf("\nMatricula: ");
        scanf("%d", &a[i].matricula);
        fflush(stdin);
        printf("\nNome: ");
        gets(a[i].nome);
        fflush(stdin);
        printf("\nMedia: ");
        scanf("%f", &a[i].media);
        fflush(stdin);
        printf("\n");
    }

    situacao(a);

    return 0;
    system("PAUSE");
}
