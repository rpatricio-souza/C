#include <stdio.h>
#include <stdlib.h>

int main()
{
    int dia, mes, ano, A, B, C, D, E, F, G, H, I, J;
    char dias[7][4]={"SAB", "DOM", "SEG", "TER", "QUA", "QUI", "SEX"};
    printf("Digite uma data:\ndd/mm/aaaa\n");
    scanf("%d/%d/%d", &dia, &mes, &ano);
    A=(12-mes)/10;
    B=ano-A;
    C=mes+12*A;
    D=B/100;
    E=D/4;
    F=2-D+E;
    G=365.25*B;
    H=30.6001*(C+1);
    I=F+G+H+dia+5;
    J=I%7;
    printf("%s", dias[J]);
    return 0;
    system("PAUSE");
}
