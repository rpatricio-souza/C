#include <stdio.h>
#include <stdlib.h>
#include <time.h>


struct dma{
    int dia;
    int mes;
    int ano;
};


int bissexto(int ano){
    if((ano%4==0 && ano%100!=0) || (ano%100==0 && ano%400==0))
        return 1;
    else
        return 0;
}


int defineDia(struct dma d){
    if(d.mes==1 || d.mes==3 || d.mes == 5 || d.mes==7 || d.mes==8 || d.mes==10 || d.mes==12)
        return rand()%30+1;
    else if(d.mes==2){
        if(bissexto(d.ano))
            return rand()%28+1;
        else
            return rand()%27+1;
    }
    else
        return rand()%29+1;
}


int difDatas(struct dma d1, struct dma d2){
    int d=0, m=0, a=0;
    if(d1.ano>d2.ano)
        a=d1.ano-d2.ano;
    else
        a=d2.ano-d1.ano;
    if(d1.mes>d2.mes)
        m=d1.mes-d2.mes;
    else
        m=d2.mes-d1.mes;
    if(d1.dia>d2.dia)
        d=d1.dia-d2.dia;
    else
        d=d2.dia-d1.dia;
    return d+m*30+a*365;
}


int main()
{
    srand(time(NULL));
    struct dma d1 = {0, rand()%11+1, rand()%2019};
    d1.dia=defineDia(d1);
    struct dma d2 = {0, rand()%11+1, rand()%2019};
    d2.dia=defineDia(d2);

    printf("Data 1: %d/%d/%d", d1.dia, d1.mes, d1.ano);
    printf("\nData 2: %d/%d/%d", d2.dia, d2.mes, d2.ano);

    printf("\nEntre as duas datas se passaram %d dias", difDatas(d1,d2));

    return 0;
    system("PAUSE");
}
