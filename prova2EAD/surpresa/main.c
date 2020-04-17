#include <stdio.h>
#include <stdlib.h>


void surpresa(int n){
    int a=0, b=0;

    while(n>0){
        if((n%2)==0)
            a=a+1;
        else
            b=b+1;
        n=n/2;
    }
    printf("%d %d\n", a,b);
}


int main()
{
    int i;
    for(i=0;i<50;i++){
        printf("n=%d, ", i);
        surpresa(i);
    }
    return 0;
    system("PAUSE");
}
