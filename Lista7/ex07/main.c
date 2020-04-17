#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*
7. Faca um programa que receba do usuario um arquivo texto. Crie outro arquivo texto contendo o texto do arquivo de entrada, mas com as vogais substituidas por ‘*’.

*/

int main()
{
    FILE *f1, *f2;
    f1=fopen("arq.txt", "w");
    if(f1==NULL){
        printf("Arquivo nao encontrado...\n");
        exit(1);
    }

    f2=fopen("substitui_vogais.txt", "w");
    if(f2==NULL){
        printf("Arquivo nao encontrado...\n");
        exit(1);
    }

    int i;
    char texto[200], c;

    printf("Escreva um texto:\n");
    gets(texto);
    fflush(stdin);

    fprintf(f1, texto);

    for(i=0;i<strlen(texto);i++){
        c=tolower(texto[i]);
        if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u')
            fputc('*', f2);
        else
            fputc(texto[i], f2);
    }

    fclose(f1);
    fclose(f2);
    return 0;
    system("PAUSE");
}
