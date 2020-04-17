#include <stdio.h>
#include <stdlib.h>


void conv_bin(){
    int num, b[4], i;
    printf("\nDigite numero menor que 16\n");
    scanf("%d",&num);
    for(i=0;i<4;i++)
        b[i]=0;
    for(i=0;num>=2;i++){
        b[i]=num%2;
        num=num/2;
    }
    b[i]=num;
    for(i=3;i>=0;i--)
        printf("%d",b[i]);
}


void conv_dec(){
    int b[4], decimal=0, i, peso=1;
    for(i=0;i<4;i++)
        b[i]=0;
    printf("\nDigite numero binario de 4 digitos\n");
    for(i=0;i<4;i++)
        scanf("%d",&b[i]);
    for(i=3;i>=0;i--){
        decimal=decimal+((b[i])*peso);
        peso=peso*2;
    }
    printf("%d", decimal);
}


int main()
{
    char op;
    op='n';

    while(op!='s'){
        printf("\nEscolha:");
        printf("\n b-converter para binario");
        printf("\n d:converter para decimal ");
        printf("\n s:sair\n");
        op=getche();
        if(op=='b')
            conv_bin();
        if(op=='d')
            conv_dec();
    }
    return 0;
    system("PAUSE");
}
