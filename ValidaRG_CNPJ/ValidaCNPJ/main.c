#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

/*
2) Elabore um programa, usando Linguagem de Programação C, para armazenar em uma matriz até 20 números de cadastros nacionais de pessoas jurídicas (CNPJ’s).
 O programa deve conter funções para:

a) Ler um CNPJ, via teclado, digitado pelo usuário;

b) Preencher automaticamente quatro CNPJ’s;

c) Verificar se um CNPJ é válido, por meio do cálculo dos dígitos verificadores;

d) Listar todos os CNPJ 's cadastrados que comecem com com um determinado dígito d, passado como parâmetro para a função;

A função int main() deve oferecer um menu para que o usuário escolha qual função deseja executar.

Sugestão para pesquisa: http://www.geradorcnpj.com/algoritmo_do_cnpj.htm

entradas:
114447770001

*/

char cnpj[20][15];
int tam=0;

void lerCNPJ(){
    char entrada[15];
    if(tam<20){
        printf("\nDigite o cnpj (apenas numeros): ");
        gets(entrada);
        fflush(stdin);
        insereCNPJ(entrada);
    }
    else
        printf("\nDesculpe, ja foram cadastrados 20 cnpjs...");
    printf("\n");
}

void gerar4CNPJs(){
    char aux[2];
    int i, j, d;

    for(i=1;i<5;i++){
        if(tam<20){
            for(j=0;j<12;j++){
                d=rand()%9;
                sprintf(aux, "%d", d);
                cnpj[tam][j]=aux[0];
            }
            tam++;
        }
        else{
            printf("\nNumero maximo de CNPJs atingido!\n");
            break;
        }
    }

    printf("\n");
}

void verificarCNPJ(int d){
    int i=0;
    cnpj[d][12]=validarCNPJ(d, 5, 12);
    cnpj[d][13]=validarCNPJ(d, 6, 13);

    printf("\nCNPJ apos validacao: ");
    for(i=0;i<14;i++){
        if(i==2 || i==5)
            printf(".");
        if(i==8)
            printf("/");
        if(i==12)
            printf("-");
        printf("%c", cnpj[d][i]);
    }

    printf("\n\n");
}

void validarCNPJ(int d, int peso, int tamanho){
    char aux[2];
    int validaCNPJ[3][13], i, j, soma=0, verificador;

    for(j=0;j<tamanho;j++){
        validaCNPJ[0][j]=cnpj[d][j]-'0';
        validaCNPJ[1][j]=peso;
        peso--;
        if(peso==1)
            peso=9;
        validaCNPJ[2][j]=validaCNPJ[0][j]*validaCNPJ[1][j];
        soma+=validaCNPJ[2][j];
    }
    /*
    for(i=0;i<3;i++){
        for(j=0;j<12;j++){
            printf("%d ", validaCNPJ[i][j]);
        }
        printf("\n");
    }*/

    soma%=11;
    if(soma<2)
        verificador=0;
    else
        verificador=11-soma;

    sprintf(aux, "%d", verificador);
    printf("%c", aux[0]);
    return aux[0];
}

void imprimeCNPJs(int d){
    int i, j;
    printf("\n");
    if(tam!=0){
        for(i=0;i<tam;i++){
            if(d==-1){
                printf("%d: ", i+1);
                for(j=0;j<14;j++){
                    if(j==2 || j==5)
                        printf(".");
                    if(j==8)
                        printf("/");
                    if(j==12)
                        printf("-");
                    printf("%c", cnpj[i][j]);
                }
            }
            else if(i==d){
                printf("%d: ", i+1);
                for(j=0;j<14;j++)
                    printf("%c", cnpj[i][j]);
            }
            printf("\n");
        }
    }
    else
        printf("\nNao existem CNPJs cadastrados!\n");
    printf("\n");
}

void insereCNPJ(char entrada[15]){
    int i;
    for(i=0;i<13;i++)
        cnpj[tam][i]=entrada[i];
    tam++;
}

int main()
{
    char opcao='a';
    int d=0, digito=10;
    srand(time(0));

    while(toupper(opcao)!='E'){
        printf("Escolha uma opcao:");
        printf("\na) Ler um CNPJ;");
        printf("\nb) Gerar 4 CNPJs automaticamente;");
        printf("\nc) Validar um CNPJ;");
        printf("\nd) Exibir CNPJs;");
        printf("\ne) Sair do programa;");
        printf("\nSua escolha: ");
        scanf("%c", &opcao);
        fflush(stdin);
        opcao=tolower(opcao);

        switch(opcao){
            case 'a':
                lerCNPJ();
                break;
            case 'b':
                gerar4CNPJs();
                break;
            case 'c':
                while(d<1 || d>tam){
                    printf("Selecione um CNPJ para validar:\n");
                    imprimeCNPJs(-1);
                    scanf("%d", &d);
                    fflush(stdin);
                    if(d>0 && d<=tam){
                        verificarCNPJ(d-1);
                        d=0;
                        break;
                    }
                    else
                        printf("\nIndice Invalido!\n");
                }
                break;
            case 'd':
                while(digito<0 || digito>9){
                    printf("Digite um numero. Mostraremos todos os cnpjs que comecam com esse numero: ");
                    scanf("%d", &digito);
                    fflush(stdin);
                    if(digito>=0 && digito<10){
                        imprimeCNPJs(d);
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
