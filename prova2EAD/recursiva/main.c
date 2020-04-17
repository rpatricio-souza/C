#include <stdio.h>
#include <stdlib.h>


int f(int v[], int n){
    if(n==0)
        return 0;
    else{
        int s;
        s=f(v,n-1);
        if(v[n-1]>0)
            s=s+v[n-1];
        return s;
    }
}


int main()
{
    int v[]={2,-4,7,0,-1,4};
    printf("%d", f(v,6));
    return 0;
    system("PAUSE");
}
