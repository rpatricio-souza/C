#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX 100

/*
Faca um programa no qual o usuario informa o nome do arquivo e uma palavra, e retorne o numero de vezes que aquela palavra aparece no arquivo.
*/


void converteTXT(char fname[30]){
    int i;
    for(i=0;i<strlen(fname);i++)
        if(fname[i]==' ')
            fname[i]='_';
    strcat(fname,".txt");
}


void criaArquivo(char nome[40]){
    FILE *f=fopen(nome,"w");
    char texto[]={"Faca um programa no qual o usuario informa o nome do arquivo e uma palavra, e retorne o numero de vezes que aquela palavra aparece no arquivo."};
    fputs(texto, f);
    fclose(f);
}


int main()
{
    FILE *f1;
    int cont=0, i=0;
    char c, palavra[15], temp[15]="";

    f1=fopen("conta_palavras.txt","r");
    if(f1==NULL){
        criaArquivo("conta_palavras.txt");
        f1=fopen("conta_palavras.txt","r");
    }

    printf("Digite uma palavra para procurar no arquivo: ");
    scanf("%s", &palavra);
    fflush(stdin);

    c=fgetc(f1);
    while(c!=EOF){
        while((c!=' ' && c!='.' && c!=',') && (c!=EOF)){ //desconsidera espacos, pontos e virgulas
            temp[i]=c;
            i++;
            c=fgetc(f1);
        }
        if(strcmp(palavra, temp)==0)
            cont++;
        memset(temp, '\0', sizeof temp); //apaga o conteudo da variavel temp
        i=0;
        c=fgetc(f1);
    }

    printf("\nA palavra %s apareceu %d vez(es) no arquivo.\n\n", palavra, cont);

    fclose(f1);

    return 0;
    system("PAUSE");
}
