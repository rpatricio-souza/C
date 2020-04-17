#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
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
    fclose(f);
}


int main()
{
    FILE *f1, *f2;

    f1=fopen("matriz.txt","r");
    if(f1==NULL){
        criaArquivo("matrix.txt");
        fclose(f1);
        f1=fopen("matriz.txt","r");
    }

    f2=fopen("matriz_saida.txt","w");
    if(f2==NULL){
        criaArquivo("matriz_saida.txt");
        fclose(f2);
        f2=fopen("matriz_saida.txt","w");
    }

    int i, j, pos=0, m, n, anula, a, b, v[MAX][MAX];
    char c;

    do{//le o numero de linhas, colunas e quantas posicoes serao anuladas
        c=fgetc(f1);
        if(c!=EOF && isdigit(c)){
            if(pos==0)
                m=c-'0';
            else if(pos==1)
                n=c-'0';
            else if(pos==2)
                anula=c-'0';
            pos++;
        }
    }while(pos<3);

    for(i=0;i<m;i++)//inicializacao do vetor
        for(j=0;j<n;j++)
            v[i][j]=1;

    pos=0;
    do{//anula as posicoes no vetor
        c=fgetc(f1);
        if(c!=EOF && isdigit(c)){
            if(pos==0)
                a=c-'0';
            else if(pos==1)
                b=c-'0';
            pos++;
            if(pos==2){
                pos=0;
                v[a][b]=0;
            }
        }
    }while(c!=EOF);

    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            fprintf(f2, "%d", v[i][j]);
            if(j<n-1)
                fprintf(f2, " ");
        }
        if(i<m-1)
            fprintf(f2, "\n");
    }

    fclose(f1);
    fclose(f2);

    return 0;
    system("PAUSE");
}
