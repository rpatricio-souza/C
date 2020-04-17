#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    FILE *f = fopen("conta_vogais.txt", "r");
    if(f==NULL){
        printf("Arquivo nao encontrado...\n");
        exit(1);
    }

    int vogais=0;
    char c;
    c=fgetc(f);
    while(c!=EOF){
        c=tolower(c);
        if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u')
            vogais++;
        c=fgetc(f);
    }

    printf("O arquivo possui %d vogais.\n", vogais);

    fclose(f);

    return 0;
    system("PAUSE");
}
