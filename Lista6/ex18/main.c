#include <stdio.h>
#include <stdlib.h>

/*
entradas:
1
Pao Integral
4.79
5
2
Iogurte
9.99
4
3
Creme Vegetal
7.49
4
4
Sabonete
2.99
12
5
Desodorante
8.99
8
1/1
2/3
2/2
6/4
0

*/

typedef struct estoque_mercado{
    int cod;
    char nome[15];
    float preco;
    int qtd;
}PRODUTO;

int main()
{
    PRODUTO p[5];
    int i, cod=1, qtd, f=0;

    printf("CADASTRO DE PRODUTOS");
    for(i=0;i<5;i++){
        printf("\nCodigo: ");
        scanf("%d", &p[i].cod);
        fflush(stdin);

        printf("Nome: ");
        gets(p[i].nome);
        fflush(stdin);

        printf("Preco: ");
        scanf("%f", &p[i].preco);
        fflush(stdin);

        printf("Quantidade disponivel: ");
        scanf("%d", &p[i].qtd);
        fflush(stdin);
    }

    printf("\n----------PEDIDOS----------");
    while(cod!=0){
        printf("\nDigite o codigo do produto e a quantidade (0 para sair).");
        printf("\nCodigo/Quantidade: ");
        scanf("%d/%d", &cod, &qtd);
        fflush(stdin);

        if(cod!=0){
            f=0;
            for(i=0;i<5;i++){
                if(p[i].cod==cod){
                    f=1;//produto encontrado no estoque
                    if(p[i].qtd>=qtd){
                        p[i].qtd-=qtd;
                        printf("\nPedido realizado com sucesso!\nAtualizacao do estoque:");
                        printf("\n%s\nQuantidade disponivel = %d\n", p[i].nome, p[i].qtd);
                    }
                    else
                        printf("\nPedido nao foi concluido...\nQuantidade insuficiente no estoque.\n");
                }
            }
            if(f==0)
                printf("\nCodigo invalido!\n");
        }
    }

    return 0;
    system("PAUSE");
}
