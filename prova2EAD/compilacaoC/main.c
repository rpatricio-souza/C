#include <stdio.h>
#include <stdlib.h>

/*
saida: 7-8
*/

int main()
{
    int i=7;
    int *p;
    p=&i;
    printf("%d-",*p);
    *p=8;
    printf("%d\n",*p);
    return 0;
    system("PAUSE");
}
