#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "geometria.h"

int main()
{
    int l=2, b = 3, a = 4;
    char opcao;

    printf("a) Perimetro do Quadrado;");
    printf("\nb) Area do Quadrado;");
    printf("\nc) Perimetro do Retangulo;");
    printf("\nd) Area do Retangulo;");
    printf("\nDigite sua escolha: ");
    scanf("%c", &opcao);

    switch(opcao){
        case 'a':   printf("Perimetro do Quadrado de lado %d = %d", l, peri_Quad(l));
                    break;
        case 'b':   area_Quad(l);
                    break;
        case 'c':   peri_Retang(b, a);
                    break;
        case 'd':   printf("\nArea do Retangulo de base %d e altura %d = %d", b, a, area_Retang(b, a));
                    break;
        default:    printf("\nOpcao invalida!");
                    break;
    }

    return 0;
}
