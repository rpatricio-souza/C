#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX 100

void converteTXT(char fname[30]){
    int i;
    for(i=0;i<strlen(fname);i++)
        if(fname[i]==' ')
            fname[i]='_';
    strcat(fname,".txt");
}


void criaArquivo(char nome[40]){
    FILE *f=fopen(nome,"w");
    char texto[]={"12. Abra um arquivo texto, calcule e escreva o numero de caracteres, o numero de linhas e o numero de palavras neste arquivo.\nEscreva tambem quantas vezes cada letra ocorre no arquivo (ignorando letras com acento).\nObs.: palavras sao separadas por um ou mais caracteres espaco, tabulacao ou nova linha."};
    fputs(texto, f);
    fclose(f);
}


int main()
{
    FILE *f;
    int numCaracteres=0, numLinhas=0, numPalavras=0;

    f=fopen("conta_caracteres_linhas_palavras.txt","r");
    if(f==NULL){
        criaArquivo("conta_caracteres_linhas_palavras.txt");
        f=fopen("conta_caracteres_linhas_palavras.txt","r");
    }

    char c, alfabeto[]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    int i=0, contagem[]={0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    c=fgetc(f);
    while(c!=EOF){
        //contagem de linhas
        if(c!=EOF && numLinhas==0)
            numLinhas++;
        else if(c=='\n')
            numLinhas++;

        //contagem de caracteres
        c=tolower(c);
        for(i=0;i<26;i++)
            if(c==alfabeto[i]){
                contagem[i]++;
                numCaracteres++;
            }

        //contagem de palavras
        if(c==' ' || c=='\n')
            numPalavras++;

        c=fgetc(f);
    }

    printf("O arquivo contem:");
    printf("\nLinhas     = %d", numLinhas);
    printf("\nCaracteres = %d", numCaracteres);
    printf("\nPalavras   = %d\n", numPalavras);

    fclose(f);

    return 0;
    system("PAUSE");
}
