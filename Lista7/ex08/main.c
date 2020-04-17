#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*
8. Faca um programa que leia o conteudo de um arquivo e crie um arquivo com o mesmo
conteudo, mas com todas as letras minusculas convertidas para maiusculas. Os nomes
dos arquivos serao fornecidos, via teclado, pelo usuario. A funcao que converte
maiuscula para minuscula e o toupper(). Ela e aplicada em cada caractere da string.
*/


void converteTXT(char fname[30]){
    int i;
    for(i=0;i<strlen(fname);i++)
        if(fname[i]==' ')
            fname[i]='_';
    strcat(fname,".txt");
}


int main()
{
    FILE *f1, *f2;
    char fname1[30], fname2[30] = {" "}, c;
    char texto[]={"8. Faca um programa que leia o conteudo de um arquivo e crie um arquivo com o mesmo conteudo, mas com todas as letras minusculas convertidas para maiusculas. Os nomes dos arquivos serao fornecidos, via teclado, pelo usuario. A funcao que converte maiuscula para minuscula e o toupper(). Ela e aplicada em cada caractere da string."};

    printf("Digite o nome de dois arquivos:\n1o nome: ");
    gets(fname1);
    fflush(stdin);

    converteTXT(fname1);
    f1=fopen(fname1, "w");

    strcpy(fname2,fname1);
    while(strcmp(fname1, fname2)==0){
        printf("\n2o nome: ");
        gets(fname2);
        fflush(stdin);
        converteTXT(fname2);
        if(strcmp(fname1, fname2)==0)
            printf("\nOs arquivos nao podem ter o mesmo nome!\n");
    }

    f2=fopen(fname2, "w");

    fprintf(f1, texto);
    fclose(f1);
    f1=fopen(fname1,"r");

    c=fgetc(f1);
    while(c!=EOF){
        printf("%c", c);
        c=toupper(c);
        fputc(c,f2);
        c=fgetc(f1);
    }

    fclose(f1);
    fclose(f2);

    return 0;
    system("PAUSE");
}
