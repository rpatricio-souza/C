#include <stdio.h>
#include <stdlib.h>

/*
3) Faça um programa que leia, via teclado, cinco números inteiros, calcule e mostre, conforme escolha do usuário:
a) O maior número dentre eles;
b) O menor número dentre eles.
c) a média aritmética entre eles;
d) a mediana entre eles;
e) a moda entre eles.
Use uma função para cada item.

entradas:
10
7
45
22
5

10
7
5
2
5

2
4
2
3
3

3
1
3
3
1


*/

int maiorNumero(int v[], int tam){
    int max=0, i;
    for(i=0;i<tam;i++){
        if(i==0)
            max=v[i];
        if(v[i]>max)
            max=v[i];
    }
    return max;
}

int menorNumero(int v[], int tam){
    int min=0, i;
    for(i=0;i<tam;i++){
        if(i==0)
            min=v[i];
        if(v[i]<min)
            min=v[i];
    }
    return min;
}

float mediaAritmetica(int v[], int tam){
    float media=0;
    int i;
    for(i=0;i<tam;i++)
        media+=v[i];
    return media/(i+1);
}

int mediana(int v[], int tam){
    int mediana;
    bubblesort(v,tam);
    if(tam%2!=0)
        return v[tam/2];
    else
        return v[tam/2]+v[(tam/2)+1];
}

int moda(int v[], int tam){
    int i, cont=1, maiormoda=1, moda=0;
    for(i=0;i<tam-1;i++){
        if(v[i]==v[i+1]){
            cont++;
        }
        else if(cont>1 && maiormoda<cont){
            maiormoda=cont;
            moda=v[i];
            cont=1;
        }
        if(i==3 && v[i]==v[i+1] && maiormoda<=cont){
            maiormoda=cont;
            moda=v[i];
        }
    }
    return moda;
}

void bubblesort(int *v, int tam){
    int i, j, aux;
    for(i=0;i<tam;i++){
        for(j=0;j<tam-1;j++){
            if(*v>*(v+1)){
                aux=*v;
                *v=*(v+1);
                *(v+1)=aux;
            }
            v++;
        }
        v-=(tam-1);
    }
}

int main()
{
    int numeros[5], i, tam=0;

    printf("Digite 5 numeros inteiros:\n");
    for(i=0;i<5;i++){
        printf("%do: ", i+1);
        scanf("%d", &numeros[i]);
        tam++;
    }

    printf("\nMaior numero = %d", maiorNumero(numeros, tam));
    printf("\nMenor numero = %d", menorNumero(numeros, tam));
    printf("\nMedia aritmetica = %.2f", mediaAritmetica(numeros, tam));
    printf("\nMediana = %d", mediana(numeros, tam));
    printf("\nModa = %d", moda(numeros, tam));
    printf("\nVetor Ordenado: ");
    for(i=0;i<tam;i++)
        printf("%d ", numeros[i]);
    printf("\n");

    return 0;
    system("pause");
}
