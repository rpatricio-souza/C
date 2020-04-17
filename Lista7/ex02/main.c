#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *arq = fopen("qtd_linhas.txt", "r");
    char c=' ';
    int linhas=0;

    if(arq==NULL){
        printf("O arquivo nao foi encontrado...\n");
        exit(1);
    }

    c=fgetc(arq);
    while(c!=EOF){
        if(c=='\n')
            linhas++;
        c=fgetc(arq);
    }
    printf("O arquivo possui %d linhas.\n", linhas);

    fclose(arq);

    return 0;
    system("PAUSE");
}
