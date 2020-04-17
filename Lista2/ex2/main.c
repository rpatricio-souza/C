#include <stdio.h>
#include <stdlib.h>

/* MARATONA 2018 - PROBLEMA B
entradas:
V 4
10
20
50
2

A 7
10
10
50
20
100
2
5

*/

void um_pra_cada(int *primeiro, int *segundo, int qtd, int *v){
    int i=0;
    while(i<qtd){
        *primeiro += v[i];
        i++;
        if(i<qtd){
            *segundo += v[i];
            i++;
        }
    }
}

int main()
{
    char pessoa;
    int qtd, i, v[20], voce=0, amigo=0;

    scanf("%c", &pessoa);
    scanf("%d", &qtd);

    for(i=0;i<qtd;i++){
        scanf("%d", &v[i]);
    }
    //Caracteres sao representados por aspas simples
    if(pessoa == 'V')
        um_pra_cada(&voce, &amigo, qtd, v);

    else
        um_pra_cada(&amigo, &voce, qtd, v);

    printf("VOCE: %d AMIGO: %d", voce, amigo);

    return 0;
}
