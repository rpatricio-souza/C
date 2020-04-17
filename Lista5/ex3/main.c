#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
entradas:
0,4,-1
5,4,-1
3,4,-1
4,4,-1
2,4,-1
1,4,-1

*/

float distancia1D(float a, float b){
    return pow(b-a,2);
}

float distancia3D(float xa, float xb, float ya, float yb, float za, float zb){
    return sqrt(distancia1D(xa,xb)+distancia1D(ya,yb)+distancia1D(za,zb));
}

void bubblesort(float v[2][5], int tam){
    int i, passo;
    float aux=0;
    for(passo=0;passo<tam;passo++){
        for(i=0;i<tam-1;i++){
            if(v[1][i]>v[1][i+1]){
                aux=v[1][i];
                v[1][i]=v[1][i+1];
                v[1][i+1]=aux;
                aux=v[0][i];
                v[0][i]=v[0][i+1];
                v[0][i+1]=aux;
            }
        }
    }
}

int main()
{
    int planeta[3], naves[5][3], i;
    float distancias[2][5];
    scanf("%d,%d,%d", &planeta[0], &planeta[1], &planeta[2]);
    for(i=0;i<5;i++){
        scanf("%d,%d,%d", &naves[i][0], &naves[i][1], &naves[i][2]);
        distancias[0][i]=i;
        distancias[1][i]=distancia3D(naves[i][0], planeta[0], naves[i][1], planeta[1], naves[i][2], planeta[2]);
    }
    bubblesort(distancias, 5);
    /*printf("\nNave Distancia\n");
    for(i=0;i<5;i++){
        printf("  %.0f    ", distancias[0][i]);
        printf("%.2f\n", distancias[1][i]);
    }*/
    for(i=0;i<5;i++){
        if(i==4)
            printf("%.0f", distancias[0][i]);
        else
            printf("%.0f, ", distancias[0][i]);
    }

    return 0;
    system("PAUSE");
}
