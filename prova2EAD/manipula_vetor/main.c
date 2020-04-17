#include <stdio.h>
#include <stdlib.h>

int main()
{
    int array[]={7,4,8,2,9,1};
    int i,j,aux;
    for(i=0;i<6;i++)
        for(j=i+1;j<6;j++)
            if(array[i]>array[j]){
                aux=array[i];
                array[i]=array[j];
                array[j]=aux;
            }
    for(i=0;i<6;i++)
        printf("%d ", array[i]);
    return 0;
    system("PAUSE");
}
