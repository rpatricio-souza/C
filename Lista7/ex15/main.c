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


int converteIdade(int d, int m, int a){
    int idade;

    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    //printf("now: %d-%d-%d %d:%d:%d\n", tm.tm_year+1900, tm.tm_mon+1,tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);

    idade=(tm.tm_year+1900)-a;
    if(m>=tm.tm_mon+1 && d>=tm.tm_mday)
        return idade-1;

    return idade;
}


int main()
{
    FILE *f1, *f2;
    f1=fopen("nome_data.txt","r");
    if(f1==NULL){
        criaArquivo("nome_data.txt");
        fclose(f1);
        f1=fopen("nome_data.txt","r");
    }

    f2=fopen("nome_idade.txt","w");

    int i=0, d, m, a, idade;
    char c, data[9];

    memset(data, '\0', sizeof data);
    do{
        c=fgetc(f1);
        if(c!=EOF){
            if(c!=':' && c!='\n' && !isdigit(c)){
                fputc(c, f2);
            }
            else if(isdigit(c)){
                data[i]=c;
                i++;
            }
        }
        if(c=='\n' || c==EOF){ //calculo da idade
            d=10*(data[0]-'0')+(data[1]-'0');
            m=10*(data[2]-'0')+(data[3]-'0');
            a=1000*(data[4]-'0')+100*(data[5]-'0')+10*(data[6]-'0')+(data[7]-'0');
            idade=converteIdade(d,m,a);
            fprintf(f2, ": %d anos", idade);
            if(idade<18)
                fprintf(f2, ", menor de idade.\n");
            else if(idade>18)
                fprintf(f2, ", maior de idade.\n");
            else
                fprintf(f2, ", entrando na maior idade.\n");
            memset(data, '\0', sizeof data);
            i=0;
        }
    }while(c!=EOF);

    fclose(f1);
    fclose(f2);

    return 0;
    system("PAUSE");
}
