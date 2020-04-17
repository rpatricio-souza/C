#include <stdio.h>
#include <stdlib.h>

/*
entradas:
30 3
10 2
20 5

25 6
20 3
10 3

100 100
100 1
1 1

*/

int main()
{
    int T, Q, i=0, covas=0;

    for(i=0;i<3;i++){
        scanf("%d", &T);
        scanf("%d", &Q);

        covas += T/Q;
    }
    printf("%d\n", covas);
    return 0;
}
