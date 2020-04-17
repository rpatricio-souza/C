#include <stdio.h>
#include <stdlib.h>

/*
entradas:
Rafael Patricio de Souza
50463
Banco de Dados
Aline Cristine
52525
Arquitetura
Gabriel Patricio
66666
Eletricista de Manutencao
Fulaninho
111
Vadiagem
Ciclaninho
2222
Engenharia

*/

typedef struct alu{
    char nome[30];
    int matricula;
    char curso[30];
}ALUNO;

int main()
{
    ALUNO a[5];
    int i;

    for(i=0;i<5;i++){
        printf("Digite os dados do %do aluno:", i+1);
        printf("\nNome: ");
        gets(a[i].nome);
        fflush(stdin);
        printf("Matricula: ");
        scanf("%d", &a[i].matricula);
        fflush(stdin);
        printf("Curso: ");
        gets(a[i].curso);
        fflush(stdin);
        printf("\n");
    }

    printf("Dados dos alunos:\n");
    for(i=0;i<5;i++){
        printf("aluno(a) %d\nNome: %s", i+1, a[i].nome);
        printf("\nMatricula: %d", a[i].matricula);
        printf("\nCurso: %s\n\n", a[i].curso);
    }

    return 0;
    system("PAUSE");
}
