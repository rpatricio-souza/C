#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
entradas:
0
1
2
3
5
2
6
4
4
1
0
0
2

*/

typedef struct aeroportos{
    int cod;
    int qtd_out;
    int qtd_in;
}AERO;

typedef struct voos{
    int aero_orig;
    int aero_dest;
}VOO;


int validaCodAeroporto(AERO a[5], int cod){
    int i;
    for(i=0;i<5;i++)
        if(a[i].cod==cod)
            return 1;
    return 0;
}


int loop(AERO a[5], VOO v[5],int orig,char palavra[8]){
    int cod=-1;
    while(validaCodAeroporto(a, cod)==0){
        printf("%s: ", palavra);
        scanf("%d", &cod);
        fflush(stdin);
        if(validaCodAeroporto(a, cod)){
            if(strcmp(palavra, "Destino")==0 && cod==v[orig].aero_orig){
                printf("\nERRO: O Aeroporto de Destino nao pode ser o mesmo de Origem!\n");
                cod=-1;
            }
            else
                return cod;
        }
        else
            printf("\nCodigo de Aeroporto Inexistente!\n");
    }
    return 0;
}

int main()
{
    AERO a[]={
        {0, 20, 10},
        {1, 10, 12},
        {2, 30, 27},
        {3, 5, 5},
        {4, 8, 6}
    };
    VOO v[5];
    int i;

    printf("Cadastro de Voos\nDigite o aeroporto de origem e destino de cada voo.");
    for(i=0;i<5;i++){
        printf("\nVoo %d\n", 1+i);
        v[i].aero_orig=loop(a, v, i, "Origem");
        v[i].aero_dest=loop(a, v, i, "Destino");
    }

    printf("\nEscala de Voos:");
    for(i=0;i<5;i++)
        printf("\nVoo %d\nOrigem = %d\nDestino = %d\n", i+1, v[i].aero_orig, v[i].aero_dest);

    return 0;
    system("PAUSE");
}
