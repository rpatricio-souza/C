#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
entradas:
3
5

*/

typedef struct pol{
    float r;
    float a;
}POLAR;

typedef struct car{
    float x;
    float y;
}CARTESIANO;


void conversao(POLAR p){
    CARTESIANO c;
    c.x=p.r*cos(p.a);
    c.y=p.r*sin(p.a);

    printf("\nCoordenadas Cartesianas:\nx = %.2f\ny = %.2f\n\n", c.x, c.y);
}


int main()
{
    POLAR p;
    printf("Conversao de coordenadas polares para cartesianas\nDigite os valores:\n");
    printf("Raio: ");
    scanf("%f", &p.r);
    fflush(stdin);
    printf("Argumento: ");
    scanf("%f", &p.a);
    fflush(stdin);

    conversao(p);

    return 0;
    system("PAUSE");
}
