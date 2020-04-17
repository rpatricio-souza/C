#include <stdio.h>
#include <stdlib.h>


int f(int n){
    if(n<=0)
        return 1;
    else
        return n*f(n-2);
}


int main()
{
    printf("%d\n", f(10));
    return 0;
    system("PAUSE");
}
