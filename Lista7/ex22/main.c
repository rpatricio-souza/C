#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>


void criaArquivo(char nome[40]){
    FILE *f=fopen(nome,"w");
    fclose(f);
}


void bubblesort(int v[3]){
    int i, j, aux;
    for(i=0;i<3;i++)
        for(j=0;j<2;j++)
            if(v[j]>v[j+1]){
                aux=v[j];
                v[j]=v[j+1];
                v[j+1]=aux;
            }
}


int main()
{
    FILE *f1,*f2;
    f1=fopen("aluno_entrada.txt","r");
    f2=fopen("aluno_saida.txt","w");

    if(f1==NULL){
        criaArquivo("aluno_entrada.txt");
        f1=fopen("aluno_entrada.txt","r");
    }

    char c;
    int i=0, notas[3], nota=0;

    do{
        c=fgetc(f1);
        if(isdigit(c)){
            notas[i]=c-'0';
            i++;
            nota=1;
        }
        else if(nota==0)
            fputc(c,f2);
    }while(c!=EOF);

    bubblesort(notas);
    fprintf(f2, "%d %d %d", notas[0], notas[1], notas[2]);

    fclose(f1);
    fclose(f2);

    return 0;
    system("PAUSE");
}
