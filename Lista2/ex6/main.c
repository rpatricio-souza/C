#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
entradas:
3
4
5

*/

int main()
{
    double a, b, c, a1, a2, a3;
    printf("Digite o 1o lado do triangulo: ");
    scanf("%lf", &a);
    printf("Digite o 2o lado do triangulo: ");
    scanf("%lf", &b);
    printf("Digite o 3o lado do triangulo: ");
    scanf("%lf", &c);

    //Regra dos Cosenos: utilizamos os 3 lados para encontrar os 3 angulos
    a1 = acos((b*b + c*c - a*a)/(2*b*c));
    a2 = acos((a*a + c*c - b*b)/(2*a*c));
    a3 = acos((a*a + b*b - c*c)/(2*a*b));

    // conversao de radianos para graus
    a1 = (a1 * 180)/acos(-1.0);
    a2 = (a2 * 180)/acos(-1.0);
    a3 = (a3 * 180)/acos(-1.0);

    if (a1 == 90 || a2 == 90 || a3 == 90)
        printf("\nTriangulo Retangulo.\n");
    else if (a1 < 90 && a2 < 90 && a3 <90)
        printf("\nTriangulo Acutangulo.\n");
    else
        printf("\nTriangulo Obtusangulo.\n");

    return 0;
}
