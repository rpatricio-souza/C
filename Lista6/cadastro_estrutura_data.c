#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

// definição de um novo tipo
typedef struct dado
{
        //campos da estrutura
         char nome [20];
         int anonasc;
}PESSOA;

//variáveis globais
PESSOA cadastro[10];//máximo de 10 pessoas
int controle=0;//quantas pessoas já foram cadastradas
int ANO;//ano atual

void insere()
{
    char n[20];
    printf("\nDigite nome:");
    fflush(stdin);//limpa buffer
    gets(n);//ler uma string com espaço
    strcpy(cadastro[controle].nome,n);//cópia da string para o vetor
    printf("\nDigite ano de nascimento:");
    scanf("%d",&cadastro[controle].anonasc);
    controle++;
}

void imprime()
{
     char dateStr [9];//data no formato dd/mm/aa\0
     int i;
     _strdate(dateStr);//chamada de uma função da biblioteca time.h: retorna a data de hoje no formato americano "mm/dd/aa\0"
     printf( "\nData atual %s \n", dateStr);
     ANO=2000+((dateStr[6]-48)*10)+((dateStr[7]-48));//ajuste do ano atual
     printf("\nANO: %d\t",ANO);
     for(i=0;i<controle;i++)//loop até número total de pessoas cadastradas
     {
           printf("\nnome: %s\t",cadastro[i].nome);//imprime nome da pessoa
           printf("idade:%d\n",ANO - cadastro[i].anonasc);//imprime a idade da pessoa
     }

}

int main ()
{
    char op='s';//variável para ler opção do usuário
    char timeStr [9];//data no formato hh:mm:ss\0
    while((op=='s')&&(controle<10))//enquanto o usuário quiser e tiver espaço...
     {
       insere();//chamada da função para inserir pessoa
       printf("\ndeseja continuar?(S/N)");
       op=getch();
     }
       imprime();
       printf("\nData :%s \nHora:%s",__DATE__,__TIME__);
       _strtime(timeStr);//chamada de uma função da biblioteca time.h
       printf( "\nHora atual %s \n", timeStr);
       getch();
       return 0;

     }
