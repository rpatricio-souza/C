#include <stdio.h>
#include <stdlib.h>

// C) Elabore um programa em C que leia cinco distâncias entre cidades e imprima a distância total a ser percorrida.
/*
entradas:
44
19
134
64.2
137

*/


int main()
{
    float distancias[5], disTotal=0;
    int i=0;

    for(i=0;i<5;i++){
        printf("Distancia da cidade %d ate a cidade %d: ", i+1, i+2);
        scanf("%f", &distancias[i]);
        disTotal+=distancias[i];
    }

    printf("\nDistancia total entre as cidades = %.2fkm\n", disTotal);

    return 0;
    system("pause");
}
