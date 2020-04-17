#include <stdio.h>
#include <stdlib.h>


int pesquisa(int vet[], int n, int chave){
    int ind;

    ind=0;
    vet[n]=chave;

    while(vet[ind]!=chave)
        ind=ind+1;

    if(ind==n)
        return -1;
    else
        return ind;
}


int main()
{
    return 0;
    system("PAUSE");
}
