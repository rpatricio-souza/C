#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    FILE *f = fopen("conta_alfabeto.txt", "r");
    if(f==NULL){
        printf("Arquivo nao encontrado...\n");
        exit(1);
    }

    char c, alfabeto[]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    int i, contagem[]={0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    c=fgetc(f);
    while(c!=EOF){
        c=tolower(c);
        for(i=0;i<26;i++)
            if(c==alfabeto[i])
                contagem[i]++;
        c=fgetc(f);
    }

    printf("Contagem de letras:\n");
    for(i=0;i<26;i++)
        printf("%c = %d\n",alfabeto[i], contagem[i]);

    fclose(f);

    return 0;
    system("PAUSE");
}
