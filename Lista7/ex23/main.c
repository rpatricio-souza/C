#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>


/*
entradas:
Funci o nario
5
Funcionario
10
Estagiario
1
Chefe da Empresa
15
Func Aposentado
20

*/

void criaArquivo(char nome[40]){
    FILE *f=fopen(nome,"w");
    fclose(f);
}


void bubblesort(int v[3]){
    int i, j, aux;
    for(i=0;i<3;i++)
        for(j=0;j<2;j++)
            if(v[j]>v[j+1]){
                aux=v[j];
                v[j]=v[j+1];
                v[j+1]=aux;
            }
}


int main()
{
    FILE *f=fopen("emp.txt","w");

    if(f==NULL){
        criaArquivo("emp.txt");
        f=fopen("emp.txt","r");
    }

    char funcionarios[5][40], nome_func[40];
    int i=0, anos;

    for(i=0;i<5;i++){
        printf("%d funcionario: ", i+1);
        gets(funcionarios[i]);
        fflush(stdin);
        printf("Tempo de servico: ");
        scanf("%d", &anos);
        fflush(stdin);

        fprintf(f, "%s,%d\n", funcionarios[i], anos);
    }

    fclose(f);

    f=fopen("emp.txt","r");
    if(f==NULL){
        printf("Nao foi possivel abrir o arquivo!\n");
        exit(1);
    }

    for(i=0;i<5;i++){
        fscanf(f, "%40[^,],%d\n", &nome_func, &anos);
        printf("\n%s %d", nome_func, anos);
    }
    fclose(f);

    return 0;
    system("PAUSE");
}
