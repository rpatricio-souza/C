#include <stdio.h>
#include <stdlib.h>

/*
entradas:
Fiat
1997
8400.00
Ford
1998
9000.00
Mitsubishi
2010
50000.00
Peugeot
2008
32999.99
Ferrari
2000
145000.00

*/

typedef struct carros{
    char marca[15];
    int ano;
    float preco;
}CARRO;

int main()
{
    CARRO c[5];
    float p=1.0;
    int i;

    printf("Entre com os dados de 5 carros.");
    for(i=0;i<5;i++){
        printf("\nCarro %d:", i+1);
        printf("\nMarca: ");
        gets(c[i].marca);
        fflush(stdin);

        printf("Ano: ");
        scanf("%d", &c[i].ano);
        fflush(stdin);

        printf("Preco: ");
        scanf("%f", &c[i].preco);
        fflush(stdin);
    }

    while(p!=0){
        printf("\nDigite um preco (0 para sair):\nR$");
        scanf("%f", &p);
        if(p!=0){
            for(i=0;i<5;i++)
                if(c[i].preco<p){
                    printf("\nCarro %d:", i+1);
                    printf("\nMarca %s", c[i].marca);
                    printf("\nAno %d", c[i].ano);
                    printf("\nPreco %.2f\n", c[i].preco);
                }
        }
    }

    return 0;
    system("PAUSE");
}
