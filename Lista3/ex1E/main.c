#include <stdio.h>
#include <stdlib.h>

/*
E) Considerando a Tabela 6 do artigo,  elabore um programa em C que calcule e imprima o percentual de redução do Km rodado,
 após a leitura do km rodado sem e com a aplicação do algoritmo descrito no artigo.

entradas:
85
85
284
274
165
165
100
96
54
54
136
136
107
93
403
311
120
96
42
42
271
261
-1

*/

float reducao(float km1, float km2){
    return (1-(km2/km1))*100;
}

int main()
{
    float km, kmTotal1=0, kmTotal2=0;
    int verdadeiro=1;

    printf("Digite -1 para interromper a leitura.\n\n");
    while(verdadeiro){
        printf("Digite a km rodada sem o uso do algoritmo: ");
        scanf("%f", &km);
        if(km==-1)
            break;
        kmTotal1+=km;
        printf("Digite a km rodada com o uso do algoritmo: ");
        scanf("%f", &km);
        kmTotal2+=km;
    }

    printf("\nKm total sem algoritmo = %.2fkm", kmTotal1);
    printf("\nKm total com algoritmo = %.2fkm", kmTotal2);
    printf("\nPercentual de reducao = %.0f\%\n", reducao(kmTotal1, kmTotal2));

    return 0;
    system("pause");
}
