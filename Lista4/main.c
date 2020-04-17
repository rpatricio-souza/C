#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include<time.h>
#include "programas.h"

int main()
{
    int escolha, i, ano;
    printf("Qual programa voce quer executar?\n");
    for(i=1;i<42;i++){
        printf("Programa %d\n", i);
    }
    printf("\nEscolha: ");
    scanf("%d", &escolha);
    switch(escolha){
        case 1:
            programa01();
            break;
        case 2:
            programa02();
            break;
        case 3:
            programa03();
            break;
        case 4:
            programa04();
            break;
        case 5:
            programa05();
            break;
        case 6:
            programa06();
            break;
        case 7:
            programa07();
            break;
        case 8:
            programa08();
            break;
        case 9:
            programa09();
            break;
        case 10:
            programa10();
            break;
        case 11:
            programa11();
            break;
        case 12:
            programa12();
            break;
        case 13:
            programa13();
            break;
        case 14:
            programa14();
            break;
        case 15:
            programa15();
            break;
        case 16:
            programa16();
            break;
        case 17:
            programa17();
            break;
        case 18:
            programa18();
            break;
        case 19:
            programa19();
            break;
        case 20:
            programa20();
            break;
        case 21:
            programa21();
            break;
        case 22:
            programa22();
            break;
        case 23:
            printf("Digite um ano para verificar se e bissexto: ");
            scanf("%d", &ano);
            if(programa23(ano))
                printf("\n%d e Bissexto!\n", ano);
            else
                printf("\n%d nao e Bissexto...\n", ano);
            break;
        case 24:
            programa24();
            break;
        case 25:
            programa25();
            break;
        case 26:
            programa26();
            break;
        case 27:
            programa27();
            break;
        case 28:
            programa28();
            break;
        case 29:
            programa29();
            break;
        case 30:
            programa30();
            break;
        case 31:
            programa31();
            break;
        case 32:
            programa32();
            break;
        case 33:
            programa33();
            break;
        case 34:
            programa34();
            break;
        case 35:
            programa35();
            break;
        case 36:
            programa36();
            break;
        case 37:
            programa37();
            break;
        case 38:
            programa38();
            break;
        case 39:
            programa39();
            break;
        case 40:
            programa40();
            break;
        case 41:
            programa41();
            break;
        default: printf("\nOpcao Invalida!\n");
    }
    return 0;
    system("PAUSE");
}
