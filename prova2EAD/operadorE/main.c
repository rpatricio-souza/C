#include <stdio.h>
#include <stdlib.h>


int f(int a, int b){
    while(a>0 && b>0){
        if(a>b)
            a=a-b;
        else
            b=b-a;
    }
    return a+b;
}


int main()
{
    printf("%d", f(18,12));
    return 0;
    system("PAUSE");
}
