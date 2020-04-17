#include <stdio.h>
#include <stdlib.h>


int par(int x){
    if(x%2==0)
        return 1;
    return 0;
}

int main()
{
    int m, n, i, j;
    n=7;
    m=(n+1)/2;

    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            if((par(i) && par(j)) && ( (i-j==0) || (i+j==n+1) || (i==m) || (j==m) ))
                printf("1 ");
            else
                printf("  ");
        }
        printf("\n");
    }

    return 0;
    system("PAUSE");
}
