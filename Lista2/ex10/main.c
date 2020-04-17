#include <stdio.h>
#include <stdlib.h>

/*
entradas:
15 1500.00
11 1500.00
12 1000.00
16 1000.00
0

8 1835.40
9 1000.00
10 1000.00
11 1000.00
0

9 500.00
9 500.00
10 1000.00
11 1000.00
0

9 2600.00
9 500.00
10 1000.00
11 1000.00
0

9 2600.00
9 500.00
10 1000.00
11 1000.00
28 500.00
0

*/

void funcao(int diaSaldo, float saldoDia, float *valorRetirada){
    float resgate;

    if(saldoDia<=*valorRetirada){
        *valorRetirada-=saldoDia;
        resgate=saldoDia;
        saldoDia=0;
        printf("\n%d %.2f (resgate de %.2f)", diaSaldo, saldoDia, resgate);
    }
    else{
        saldoDia-=*valorRetirada;
        resgate=*valorRetirada;
        *valorRetirada=0;
        printf("\n%d %.2f (resgate de %.2f)", diaSaldo, saldoDia, resgate);
    }
}

int main()
{
    int data, tam=0, diaRetirada, diaSaldo[10], i=0, verdadeiro=1;
    float valorRetirada, saldoDia[10], valorTotal=0;

    //le o dia e o valor da retirada
    scanf("%d %f", &diaRetirada, &valorRetirada);

    //le as datas e os valores de saldo em cada dia. 0 e a condicao de parada.
    while(verdadeiro==1){
        scanf("%d", &data);
        if(data==0)
            break;
        diaSaldo[i]=data;
        scanf("%f", &saldoDia[i]);
        valorTotal += saldoDia[i];
        i++;
    }
    tam=i; //tam recebe a quantidade de elementos lidos

    if(valorTotal < valorRetirada)
        printf("\nINSUFICIENTE\n");

    else{
        i=tam-1;
        while(valorRetirada>0){
            if(diaSaldo[i]<=diaRetirada)
                funcao(diaSaldo[i], saldoDia[i], &valorRetirada);
            i--;

            if(i==-1 && valorRetirada>0){
                i=tam-1;
                while(valorRetirada>0){
                    funcao(diaSaldo[i], saldoDia[i], &valorRetirada);
                    i--;
                }
            }
        }
    }

    return 0;
}
