#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
ax^2 + bx + c

entradas:
2
4
-1

2
9
5

*/

int main()
{
    float a, b, c, x1, x2, delta;
    printf("Digite o valor de a: ");
    scanf("%f", &a);
    printf("Digite o valor de b: ");
    scanf("%f", &b);
    printf("Digite o valor de c: ");
    scanf("%f", &c);

    delta = b*b -(4*a*c);
    x1 = (-b + sqrt(delta))/(2*a);
    x2 = (-b - sqrt(delta))/(2*a);

    printf("\nx1 = %.2f\nx2 = %.2f\n", x1, x2);
    return 0;
}
