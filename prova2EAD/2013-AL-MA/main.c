#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, *b, c;
    a=5;
    b=&a;
    c=10;

    scanf("%d", b);//Digitar 15
    printf("%d %d\n", a, c);
    return 0;
    system("PAUSE");
}
