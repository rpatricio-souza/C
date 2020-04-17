#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    FILE *f = fopen("conta_caracter.txt", "r");
    if(f==NULL){
        printf("Arquivo nao encontrado...\n");
        exit(1);
    }

    int cont=0;
    char c, cb;

    printf("Digite um caractere: ");
    scanf("%c", &cb);
    fflush(stdin);

    c=(fgetc(f));
    while(c!=EOF){
        if(tolower(cb)==tolower(c))
            cont++;
        c=fgetc(f);
    }

    printf("O caractere %c aparece %d vez(es) no arquivo.\n", cb, cont);

    fclose(f);

    return 0;
    system("PAUSE");
}
