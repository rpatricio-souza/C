#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void viagem(){
    char escolha, destino[50], local[50], lazer[100];
    printf("\nSabe para onde ir? (S/N)\n");
    escolha=getch();
    if(escolha=='N' || escolha=='n'){
        printf("\nEscolha o destino: ");
        gets(destino);
    }
    printf("\nOnde vai ficar?\n");
    gets(local);
    printf("\nO que vai fazer?\n");
    gets(lazer);
}

void par_impar(){
    int verdadeiro=1, n;
    while(verdadeiro){
        printf("\nDigite um numero natural diferente de zero: ");
        scanf("%d", &n);
        if(n>0){
            if(n%2==0)
                printf("\n%d e par!\n", n);
            else
                printf("\n%d e impar!\n", n);
            verdadeiro=0;
        }
        else
            printf("\nValor invalido!\n");
    }
}

void n_10(){
    int n=0, r[11];
    while(n<11){
        r[n]=6*n;
        n++;
    }
    printf("\n");
    for(n=0;n<11;n++)
        printf("%d ", r[n]);
    printf("\n");
}

void multiplo3(){
    int n;
    printf("\nInsira um numero natural N: ");
    scanf("%d", &n);
    if(n%3==0)
        printf("\n%d e multiplo de 3\n", n);
    else
        printf("\n%d NAO e multiplo de 3\n", n);
}

int main()
{
    char escolha;
    int verdadeiro=1;

    while(verdadeiro==1){
        printf("\nEscolha uma opcao:");
        printf("\nA- Viajar;");
        printf("\nB- Par ou Impar;");
        printf("\nC- N ate 10;");
        printf("\nD- Multiplo de 3;");
        printf("\nS- Sair.");
        printf("\nSua escolha: ");
        escolha=getch();

        if(escolha=='s')
            break;

        switch(escolha){
            case 'a':
                viagem();
                break;
            case 'b':
                par_impar();
                break;
            case 'c':
                n_10();
                break;
            case 'd':
                multiplo3();
                break;
            default:
                printf("\nOpcao invalida!\n");
                break;
        }
    }

    return 0;
    system("pause");
}
