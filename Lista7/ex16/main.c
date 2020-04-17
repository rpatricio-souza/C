#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>


void converteTXT(char fname[30]){
    int i;
    for(i=0;i<strlen(fname);i++)
        if(fname[i]==' ')
            fname[i]='_';
    strcat(fname,".txt");
}


void criaArquivo(char nome[40]){
    FILE *f=fopen(nome,"w");
    fclose(f);
}


void converteDecBin(FILE *f, int x, int fim){
    char s1[16]="";
    char s2[16]="";

    while(x>0){
        if((x%2)==0){
            strcpy(s1, "0");
            strcat(s1,s2);
            strcpy(s2,s1);
            x=x/2;
        }
        else{
            strcpy(s1, "1");
            strcat(s1,s2);
            strcpy(s2,s1);
            x=x/2+0.5;
        }
    }
    if(fim)
        fprintf(f, "%s", s1);
    else
        fprintf(f, "%s\n", s1);
}


int main()
{
    FILE *f1;
    f1=fopen("binarios","wb");

    if(f1==NULL){
        criaArquivo("binarios");
        fclose(f1);
        f1=fopen("binarios","wb");
    }

    srand(time(0));

    int i=0, n[10];

    for(i=0;i<10;i++){
        n[i]=rand()%255;
        //fwrite(&n[i], sizeof(int), 1, f1);
        if(i<9)
            converteDecBin(f1,n[i],0);
        else
            converteDecBin(f1,n[i],1);
    }

    //fwrite(&n[0], sizeof(int), 10, f1);
    fclose(f1);

    return 0;
    system("PAUSE");
}
