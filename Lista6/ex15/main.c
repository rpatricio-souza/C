#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*
entradas:
A Cor Que Caiu do Ceu
H.P. Lovecraft
1927
Cemiterio Maldito
Stephen King
1989
Eu sou a Lenda
Richard Matheson
1954
Caixa de Passaros
Josh Malerman
2014
Coraline
Neil Gailman
2002

*/

typedef struct livros{
    char titulo[30];
    char autor[15];
    int ano;
}LIVRO;

int main()
{
    LIVRO l[5];
    int i, f=0;
    char t[30], *p;

    printf("Entre com os dados de 5 livros.");
    for(i=0;i<5;i++){
        printf("\nLivro %d", i+1);
        printf("\nTitulo: ");
        gets(l[i].titulo);
        fflush(stdin);

        printf("Autor: ");
        gets(l[i].autor);
        fflush(stdin);

        printf("Ano: ");
        scanf("%d", &l[i].ano);
        fflush(stdin);
    }

    printf("\nBusca Livro\nDigite o nome do livro: ");
    gets(t);
    fflush(stdin);

    for(i=0;i<5;i++){
        p=strstr(strupr(l[i].titulo), strupr(t));//strupr converte a string para maiusculo
        if(p!=NULL){//Encontrou a substring
            printf("\nLivro Encontrado!", i+1);
            printf("\nTitulo: %s", l[i].titulo);
            printf("\nAutor:  %s", l[i].autor);
            printf("\nAno:    %d\n", l[i].ano);
            f=1;
        }
    }
    if(f==0)
        printf("\nLivro nao encontrado...\n");

    return 0;
    system("PAUSE");
}
