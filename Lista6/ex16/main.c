#include <stdio.h>
#include <stdlib.h>

/*
entradas:
Reuniao 1
05/11/2019
Aniversario
20/05/1990
Entrevista
01/11/2019
Homologacao
20/04/2018
Ferias
01/07/2019

*/
typedef struct data{
    int dia;
    int mes;
    int ano;
}DATA;

typedef struct agenda_compromissos{
    char compromisso[60];
    DATA dat;
}AGENDA;

int main()
{
    AGENDA ag[5];
    int i, M=1, A, f=0;

    printf("Digite 5 compromissos.");
    for(i=0;i<5;i++){
        printf("\nCompromisso %d", i+1);
        printf("\nCompromisso: ");
        gets(ag[i].compromisso);
        fflush(stdin);

        printf("Data (Dia/Mes/Ano): ");
        scanf("%d/%d/%d", &ag[i].dat.dia, &ag[i].dat.mes, &ag[i].dat.ano);
        fflush(stdin);
    }

    while(M!=0){
        printf("\nDigite uma data para mostrar os compromissos (0 para sair).");
        printf("\nmm/aaaa: ");
        scanf("%d/%d", &M, &A);
        fflush(stdin);
        if(M!=0){
            f=0;
            for(i=0;i<5;i++){
                if(ag[i].dat.mes==M && ag[i].dat.ano==A){
                    printf("\nCompromisso: %s", ag[i].compromisso);
                    printf("\nData: %d/%d/%d\n", ag[i].dat.dia, ag[i].dat.mes, ag[i].dat.ano);
                    f=1;
                }
            }
            if(f==0)
                printf("\nNenhum compromisso encontrado na data especificada.\n");
        }
    }

    return 0;
    system("PAUSE");
}
