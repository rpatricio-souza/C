#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

/*
1- Elabore um programa, usando Linguagem de Programação C, para armazenar em uma matriz até 20 números de registros gerais (RG’s) do estado de São Paulo.
O programa deve conter funções para:

a) Ler um RG, via teclado, digitado pelo usuário;

b) Preencher automaticamente três RG’s;

c) Verificar se um RG é válido, por meio do cálculo do dígito verificador;

d) Listar todos os RG's cadastrados que comecem com um determinado dígito d, passado como parâmetro para a função;

A função int main() deve oferecer um menu para que o usuário escolha qual função deseja executar.

Sugestão para pesquisa:

http://www.fernandosilva.pro.br/portal/index.php/en/para-pensar/curiosidades/item/168-como-determinar-o-d%C3%ADgito-verificador-do-rg-registro-geral


entrada:
a
46162667
c
1

56843539

*/

char rg[20][10];
int tam=0;

void lerRG(){
    char entrada[9];
    if(tam<20){
        printf("\nDigite o RG (apenas numeros): ");
        gets(entrada);
        fflush(stdin);
        insereRG(entrada);
    }
    else
        printf("\nDesculpe, ja foram cadastrados 20 RGs...");
    printf("\n");
}

void gerar3RGs(){
    char aux[2];
    int i, j, d;

    for(i=1;i<4;i++){
        if(tam<20){
            for(j=0;j<8;j++){
                d=rand()%9;
                sprintf(aux, "%d", d);
                rg[tam][j]=aux[0];
            }
            tam++;
        }
        else{
            printf("\nNumero maximo de RGs atingido!\n");
            break;
        }
    }

    printf("\n");
}

void verificarRG(int d){
    char aux[2];
    int validaRG[3][8], i=0, j=0, verificador, soma=0;
    for(j=0;j<8;j++){
        validaRG[0][j]=rg[d][j]-'0';
        validaRG[1][j]=j+2;
        validaRG[2][j]=validaRG[0][j]*validaRG[1][j];
        soma+=validaRG[2][j];
    }
    /*
    for(i=0;i<3;i++){
        for(j=0;j<8;j++){
            printf("%d ", validaRG[i][j]);
        }
        printf("\n");
    }*/

    soma%=11;
    verificador=11-soma;

    if(verificador==10)
        rg[d][8]='X';
    else{
        sprintf(aux, "%d", verificador);
        rg[d][8]=aux[0];
    }
    printf("\nRG apos validacao: ");
    for(i=0;i<9;i++)
        printf("%c", rg[d][i]);

    printf("\n\n");
}

void imprimeRGs(int d){
    int i, j;
    printf("\n");
    if(tam!=0){
        for(i=0;i<tam;i++){
            if(d==-1){
                printf("%d: ", i+1);
                for(j=0;j<9;j++)
                    printf("%c", rg[i][j]);
            }
            else if(i==d){
                printf("%d: ", i+1);
                for(j=0;j<9;j++)
                    printf("%c", rg[i][j]);
            }
            printf("\n");
        }
    }
    else
        printf("\nNao existem RGs cadastrados!\n");
    printf("\n");
}

void insereRG(char entrada[9]){
    int i;
    for(i=0;i<8;i++)
        rg[tam][i]=entrada[i];
    tam++;
}

int main()
{
    char opcao='a';
    int d=0, digito=10;
    srand(time(0));

    while(toupper(opcao)!='E'){
        printf("Escolha uma opcao:");
        printf("\na) Ler um RG");
        printf("\nb) Gerar 3 RGs automaticamente");
        printf("\nc) Validar um RG");
        printf("\nd) Exibir RGs");
        printf("\ne) Sair do programa");
        printf("\nSua escolha: ");
        scanf("%c", &opcao);
        fflush(stdin);
        opcao=tolower(opcao);

        switch(opcao){
            case 'a':
                lerRG();
                break;
            case 'b':
                gerar3RGs();
                break;
            case 'c':
                while(d<1 || d>tam){
                    printf("Selecione um RG para validar:\n");
                    imprimeRGs(-1);
                    scanf("%d", &d);
                    fflush(stdin);
                    if(d>0 && d<=tam){
                        verificarRG(d-1);
                        d=0;
                        break;
                    }
                    else
                        printf("\nIndice Invalido!\n");
                }
                break;
            case 'd':
                while(digito<0 || digito>9){
                    printf("Digite um numero. Mostraremos todos os RGs que comecam com esse numero: ");
                    scanf("%d", &digito);
                    fflush(stdin);
                    if(digito>=0 && digito<10){
                        imprimeRGs(d);
                        digito=10;
                        break;
                    }
                    else
                        printf("\nDigito Invalido!\n");
                }
                break;
            case 'e':
                opcao='E';
                break;
            default:
                printf("\nEscolha invalida!\n\n");
        }
    }

    return 0;
    system("pause");
}
