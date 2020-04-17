#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1000

/*
entradas:
Bolo de Cenoura
7
Brigadeiro
4
Mousse de Maracuja
4
Nhoque
5
Lasanha Bolonhesa
7
cenouras medias raspadas e picadas
3
ovos
3
xicara de oleo
1
xicaras de acucar
2
xicaras de farinha de trigo
2
colher de sopa de fermento em po
1
pitada de sal
1
caixa de leite condensado
1
colher (sopa) de margarina sem sal
1
colheres (sopa) de achocolatado
7
chocolate granulado
1
lata de leite condensado
1
lata de creme de leite
1
medida da lata do leite condensado de suco concentrado de maracuja
1
gelatina de maracuja diluida em 250 ml de agua
1
kg de batata
2
gemas
2
xicara (cha) de farinha de trigo
1
sal a gosto
1
farinha de trigo para polvilhar a bancada
1
colheres (sopa) de oleo
2
meio quilo de carne moida
1
cebola pequena picada
1
cenoura pequena ralada no ralo fino
1
meia xicara (cha) de salsao picado
1
lata de polpa de tomate
1
tabletes de MAGGI Caldo Carne
2

*/

typedef struct ingredientes{
    char nome[100];
    int qtd;
}INGREDIENTE;

typedef struct receitas{
    char nome[25];
    int qtd_ingr;
    INGREDIENTE *ingr[MAX];
}RECEITA;

int main()
{
    RECEITA r[5];
    int i, j, f=0;
    char busca[25]=" ", *p;

    printf("Digite 5 receitas e a quantidade de ingredientes usada em cada uma.\n");
    for(i=0;i<5;i++){
        printf("\nNome da Receita: ");
        gets(r[i].nome);
        fflush(stdin);

        printf("Quantidade de Ingredientes: ");
        scanf("%d", &r[i].qtd_ingr);
        fflush(stdin);
    }

    printf("\nAgora vamos cadastrar os ingredientes.");
    for(i=0;i<5;i++){
        printf("\n%s", r[i].nome);
        for(j=0;j<r[i].qtd_ingr;j++){
            r[i].ingr[j]=malloc(sizeof(INGREDIENTE));
            printf("\nNome do Ingrediente: ");
            gets(r[i].ingr[j]->nome);
            fflush(stdin);

            printf("Quantidade:          ");
            scanf("%d", &r[i].ingr[j]->qtd);
            fflush(stdin);
        }
    }

    printf("\n----------LIVRO DE RECEITAS----------\n          Sistema de Busca");
    while(strcmp(busca,"")!=0){
        printf("\nDigite o nome da receita e pressione ENTER(deixe vazio para finalizar): ");
        gets(busca);
        fflush(stdin);
        f=0;
        if(strcmp(busca,"")!=0){
            for(i=0;i<5;i++){
                p=strstr(strupr(r[i].nome), strupr(busca));//strupr converte a string para maiusculo
                if(p!=NULL){ //receita encontrada
                        f=1; //f=1 indica que a receita foi encontrada
                    printf("\n%s", r[i].nome);
                    for(j=0;j<r[i].qtd_ingr;j++)
                        printf("\n%d %s", r[i].ingr[j]->qtd, r[i].ingr[j]->nome);
                }
            }
            if(f==0)
                printf("\nReceita nao encontrada...\n");
            else
                printf("\n");
        }
    }

    return 0;
    system("PAUSE");
}
