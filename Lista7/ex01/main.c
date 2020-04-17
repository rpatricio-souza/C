#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *arq = fopen("arq.txt", "w");
    char caractere=' ';

    while(caractere!='0'){
        printf("Digite um caractere (0 para sair): ");
        scanf("%c", &caractere);
        fflush(stdin);
        fputc(caractere, arq);
        printf("\n");
    }
    fclose(arq);

    arq = fopen("arq.txt", "r");
    caractere = fgetc(arq);
    while(caractere!=EOF){
        printf("%c", caractere);
        caractere = fgetc(arq);
    }

    fclose(arq);
    return 0;
    system("PAUSE");
}
