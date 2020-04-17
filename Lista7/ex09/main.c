#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


void escreveNoArquivo(FILE *f, FILE *f3){
    char c;
    c=fgetc(f);
    while(c!=EOF){
        fputc(c,f3);
        c=fgetc(f);
    }
}


int main()
{
    FILE *f1, *f2, *f3;

    f1=fopen("arq1.txt","r");
    if(f1==NULL){
        printf("O arquivo nao foi encontrado...\n");
        exit(1);
    }
    f2=fopen("arq2.txt","r");
    if(f2==NULL){
        printf("O arquivo nao foi encontrado...\n");
        exit(1);
    }
    f3=fopen("concatenacao.txt","w");

    escreveNoArquivo(f1, f3);
    escreveNoArquivo(f2, f3);

    fclose(f1);
    fclose(f2);
    fclose(f3);

    return 0;
    system("PAUSE");
}
