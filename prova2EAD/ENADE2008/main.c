#include <stdio.h>
#include <stdlib.h>

int main()
{
    int v[]={2,0,4,3,1};
    int i,j,a;

    for(i=0;i<4;i++)
        for(j=0;j<4-i;j++){
            printf("i=%d j=%d\n", i,j);
            if(v[j]>v[j+1]){
                a=v[j];
                v[j]=v[j+1];
                v[j+1]=a;
            }
            printf("%d, %d, %d, %d, %d\n", v[0],v[1],v[2],v[3],v[4]);
        }

    return 0;
    system("PAUSE");
}
