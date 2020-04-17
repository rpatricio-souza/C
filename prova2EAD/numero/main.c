#include <stdio.h>
#include <stdlib.h>


/*
m=3, printf=245
m=2, printf=24
m=1, printf=2
*/

int numero(double a, int m){
    int r, pot;
    pot=1;
    while(m>1){
        printf("%d ", pot);
        pot=pot*10;
        m=m-1;
    }
    r=a*pot;
    return r;
}


int main()
{
    printf("\n%d\n", numero(2.45334,4));
    return 0;
    system("PAUSE");
}
