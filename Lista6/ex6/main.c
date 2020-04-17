#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
entradas:
50463
Rafael Patricio de Souza
29
6
7

52525
Aline Cristine
52
9.5
9.2

66666
Gabriel Patricio
66
6
6.6

111
Fulaninho
11
3.2
1.4

2222
Ciclaninho
22
6.2
2.9
-1

*/

typedef struct alu{
    int matricula;
    char nome[30];
    int disciplina;
    float notas[2];
}ALUNO;


void media(ALUNO a[5], int cont){
    int i;
    float media[10];

    printf("\nSituacao:");
    for(i=0;i<cont;i++){
        media[i]=(a[i].notas[0]+2.0*a[i].notas[1])/(1.0+2.0);
        printf("\n%s - %.2f", a[i].nome, media[i]);
    }
}


int main()
{
    ALUNO a[10];
    int i, j, matricula, cont=0;
    printf("Entre com os dados de ate 10 alunos. Digite -1 para encerrar.\n");
    for(i=0;i<10;i++){
        printf("Digite os dados do %do aluno:", i+1);
        printf("\nMatricula: ");
        scanf("%d", &matricula);
        fflush(stdin);
        if(matricula==-1)
            break;
        a[i].matricula=matricula;
        printf("\nNome: ");
        gets(a[i].nome);
        fflush(stdin);
        printf("\nCodigo da Disciplina:");
        scanf("%d", &a[i].disciplina);
        fflush(stdin);
        printf("\nNotas:");
        for(j=0;j<2;j++){
            printf("\n%da Prova: ", j+1);
            scanf("%f", &a[i].notas[j]);
            fflush(stdin);
        }
        printf("\n");
        cont++;
    }

    media(a, cont);

    return 0;
    system("PAUSE");
}
