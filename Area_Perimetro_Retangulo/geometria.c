#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "geometria.h"

int peri_Quad(int lado){
    return lado * 4;
}

void area_Quad(int lado){
    printf("\nArea do Quadrado de lado %d = %d", lado, lado * lado);
}

void peri_Retang(int base, int altura){
    printf("\nPerimetro do Retangulo de base %d e altura %d = %d", base, altura, base * 2 + altura * 2);
}

int area_Retang(int base, int altura){
    return base * altura;
}
