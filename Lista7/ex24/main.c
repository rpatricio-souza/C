#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX 100


/*
entradas:
a
1
sabonete
3
a
2
shampoo
1
a
3
desodorante
2

*/


typedef struct despensa{
    int id;
    char descricao[50];
    int qtd;
}PRODUTO;


int tam=0;
PRODUTO prod[MAX];


void cadastrar(){
    printf("\nCodigo: ");
    scanf("%d", &prod[tam].id);
    fflush(stdin);
    printf("Descricao: ");
    gets(prod[tam].descricao);
    fflush(stdin);
    printf("Quantidade atual: ");
    scanf("%d", &prod[tam].qtd);
    fflush(stdin);

    gravarDados();

    tam++;
}


void lerDados(){
    FILE *f=fopen("despensa.dat", "rb");

    if(f==NULL){
        printf("\nAinda nao existem dados no programa.\n");
        printf("\n---------------------------------------\n\n");
        return;
    }
    else{
        rewind(f);//posiionar o ponteiro no inicio do arquivo
        while(feof(f)==0){
            fread(&prod[tam], sizeof(PRODUTO), 1, f);
            tam++;
        }
    }
    tam--;
    fclose(f);
    printf("\n%d Dados lidos com sucesso!\n", tam);
    printf("\n---------------------------------------\n\n");
}


void gravarDados(){
    FILE *f=fopen("despensa.dat", "a+b");
    fseek(f,0, SEEK_END);//posicionar o ponteiro no final do arquivo
    fwrite(&prod[tam], sizeof(PRODUTO), 1, f);
    fclose(f);
    printf("\nDados gravados com sucesso!\n---------------------------------------\n\n");
}


void atualizarDados(int pos){
    FILE *f=fopen("despensa.dat", "a+b");
    fseek(f,pos,SEEK_SET);//posiciona o ponteiro no inicio do arquivo e avanca 'pos' posicoes
    fwrite(&prod[pos], sizeof(PRODUTO), 1, f);
    fclose(f);
}


void mostrarTudo(int qtd){
    int i;
    if(qtd==1){
        for(i=0;i<tam;i++){
            printf("\nCodigo:           %d", prod[i].id);
            printf("\nDescricao:        %s", prod[i].descricao);
            printf("\nQuantidade atual: %d\n", prod[i].qtd);
        }
    }
    else{
        for(i=0;i<tam;i++){
            if(prod[i].qtd==0){
                printf("\nCodigo:           %d", prod[i].id);
                printf("\nDescricao:        %s", prod[i].descricao);
                printf("\nQuantidade atual: %d\n", prod[i].qtd);
            }
        }
    }
    printf("---------------------------------------\n\n");
}


void retirada(int id, int qtd){
    int i=0, encontrou=0;
    for(i=0;i<tam;i++){
        if(prod[i].id==id){
            encontrou=1;
            if(prod[i].qtd>=qtd){
                prod[i].qtd-=qtd;
                printf("\nRetirada efetuada!\nAtualizacao:");
                printf("\nCodigo:           %d", prod[i].id);
                printf("\nDescricao:        %s", prod[i].descricao);
                printf("\nQuantidade atual: %d\n", prod[i].qtd);
                atualizarDados(i);
            }
            else{
                printf("\nNao foi possivel retirar\nQuantidade em estoque = %d\n", prod[i].qtd);
                printf("\n--------------------------------------\n\n");
                return;
            }
        }
    }
    if(!encontrou)
        printf("\nProduto nao cadastrado!\n");
    printf("\n---------------------------------------\n\n");
}


int main()
{
    lerDados();

    int id, qtd;
    char escolha=' ';
    do{
        printf("Escolha uma opcao:");
        printf("\na) Cadastrar produto;");
        printf("\nb) Retirar produto;");
        printf("\nc) Relatorio geral;");
        printf("\nd) Relatorio de produtos em falta;");
        printf("\ns) Sair;");
        printf("\nSua escolha: ");
        scanf("%c", &escolha);
        fflush(stdin);
        escolha=tolower(escolha);

        switch(escolha){
        case 'a':
            printf("\n-----------CADASTRAR PRODUTO-----------\n");
            cadastrar();
            break;
        case 'b':
            printf("\n------------RETIRAR PRODUTO------------\n");
            printf("Digite o codigo do produto e a quantidade a ser retirada:\n");
            printf("Codigo:     ");
            scanf("%d", &id);
            fflush(stdin);
            printf("Quantidade: ");
            scanf("%d", &qtd);
            fflush(stdin);
            retirada(id,qtd);
            break;
        case 'c':
            printf("\n------------RELATORIO GERAL------------\n");
            mostrarTudo(1);
            break;
        case 'd':
            printf("\n-----------PRODUTOS EM FALTA-----------\n");
            mostrarTudo(0);
            break;
        case 's':
            printf("\n----------PROGRAMA ENCERRADO-----------\n");
            break;
        default:
            printf("\nOpcao Invalida!\n");
        }
    }while(escolha!='s');

    //memset(nome, '\0', sizeof nome);//limpa a variavel nome
    return 0;
    system("PAUSE");
}
