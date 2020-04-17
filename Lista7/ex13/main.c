#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*
entradas:
Rafael P
+5512988883333
Aline S2
11999991234
Fulano
0034987654321
Ciclano
988772244
0
0

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
    fclose(f);
}


int main()
{
    FILE *f;
    f=fopen("telefones.txt","w");
    if(f==NULL){
        criaArquivo("telefones.txt");
        fclose(f);
        f=fopen("telefones.txt","r");
    }

    char nome[30], telefone[15]=" ";

    printf("Digite nomes e telefones para gravar no arquivo.\nDigite 0 no telefone para sair.");
    while(strcmp(telefone,"0")!=0){
        printf("\nNome: ");
        gets(nome);
        fflush(stdin);

        printf("Telefone (0 para sair): ");
        gets(telefone);
        fflush(stdin);

        if(strcmp(telefone,"0")!=0){
            fputs(nome, f);
            fputs(" ", f);
            fputs(telefone, f);
            fputs("\n", f);
        }
    }

    fclose(f);

    return 0;
    system("PAUSE");
}
