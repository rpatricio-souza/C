#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX 100


int tam=0;


typedef struct cidade{
    char nome[40];
    int pop;
}CIDADE;


void converteTXT(char fname[30]){
    int i;
    for(i=0;i<strlen(fname);i++)
        if(fname[i]==' ')
            fname[i]='_';
    strcat(fname,".txt");
}


int main()
{
    FILE *f1, *f2;
    CIDADE city[MAX];
    char c, pop[10], texto[40]="";
    int i=0, j=0, k=0, m, maior;

    f1=fopen("cidades.txt","r");
    if(f1==NULL){
        printf("O arquivo nao foi encontrado...\n");
        exit(1);
    }

    f2=fopen("cidade_mais_populosa.txt", "w");
    if(f2==NULL){
        printf("O arquivo nao foi encontrado...\n");
        exit(1);
    }

    c=fgetc(f1);
    while(c!=EOF){
        if(c=='\n'){
            city[i].pop=atoi(pop);
            tam++;
            i++;
            j=0;
            k=0;
        }
        else if(isdigit(c)){
            pop[k]=c;
            k++;
        }
        else if(c!='-'){
            city[i].nome[j]=c;
            j++;
        }
        c=fgetc(f1);
        if(c==EOF){
            city[i].pop=atoi(pop);
            tam++;
        }
    }

    for(i=0;i<tam;i++){
        if(i==0){
            maior=city[i].pop;
            m=i;
        }
        if(city[i].pop>maior){
            maior=city[i].pop;
            m=i;
        }
        printf("%s %d\n", city[i].nome, city[i].pop);
    }

    strcpy(texto, city[m].nome);
    strcat(texto, " ");
    strcat(texto, itoa(city[m].pop, pop, 10));
    fputs(texto, f2);

    fclose(f1);
    fclose(f2);

    return 0;
    system("PAUSE");
}
