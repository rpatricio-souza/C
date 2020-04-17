#include <stdio.h>
#include <stdlib.h>

// declara??o de vari?veis
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
// defini??o de um novo tipo
 typedef struct {
         int numero;
         char origem [20];
         char destino [20];
         int qtdeAssentosTotal;
         int qtdeAssentosOcupados;
         }AERONAVE;

 // declara??o de vari?veis globais
 // avi?o e ponteiro para arquivo
 AERONAVE aviao;
 FILE *p_aviao;

 void abre_arquivo(){
      p_aviao=fopen ("dados_frota.dat","a+b");
         }

 void mostrar(){
      printf("\n %d %s \t\t%s \t\t%d \t\t%d",
      aviao.numero,aviao.origem,
      aviao.destino, aviao.qtdeAssentosTotal,
      aviao.qtdeAssentosOcupados);
      }

void cadastrar(){
     int continuar=1;
     do {
         //LEITURA DOS DADOS
        system("cls");
        printf("*****Cadastro de Aeronave****");
        printf("\n Voo Num:");
        scanf("%d",&aviao.numero);
        printf("\n Origem:");
        scanf("%s", aviao.origem);
        printf("\n Destino:");
        scanf("%s", aviao.destino);
        printf("\n Numero de assentos:");
        scanf("%d",&aviao.qtdeAssentosTotal);
        printf("\n Assentos ocupados:");
        scanf("%d",&aviao.qtdeAssentosOcupados);
        // Posiciona ponteiro de arquivo no final do arquivo
        // para evitar sobreescrever dados
        fseek(p_aviao,0, SEEK_END);
        // grava dados de um avi?o
        // fwrite(vari?vel, tamanho,
        // qtde de dados por vez,
        //arquivo apontado pelo ponteiro
        fwrite (&aviao, sizeof(AERONAVE), 1,p_aviao);
        printf("\nSucesso. Quer continuar? 1- sim 2 -nao\n");
        scanf ("%d", &continuar);
         }while (continuar==1);
         }
  void listar(){
       printf("\n Voo Origem  Destino  Numero de assentos  Assentos ocupados\n");
        //resetar ponteiro
       // in?cio do arquivo
       rewind(p_aviao);
       do{
       // le arquivo e coloca dados na vari?vel aviao
       fread(&aviao,sizeof(AERONAVE),1,p_aviao);
       // testa se ? fim de arquivo,
       // se n?o for mostra dados lidos
       if(feof(p_aviao)==0) mostrar();
       }while(feof(p_aviao)==0);
       getch();
       }
  void reservar(){
       int voo;
       int fim=1;
       int cont=0;
       int desejos;
       system("cls");
       printf("Digite o numero do voo");
       scanf("%d", &voo);
       p_aviao=fopen("dados_frota.dat", "r+b");
       do
       {
         // procurando o avi?o certo
        fread(&aviao,sizeof(AERONAVE),1,p_aviao);
        if(aviao.numero==voo){
printf("\nQuantidade de assentos dispon?veis %d", aviao.qtdeAssentosTotal-aviao.qtdeAssentosOcupados);
       printf("\nDigite quantidade de assentos desejados");
       scanf("%d",&desejos);
       // controla o fim da procura
       fim=0;
aviao.qtdeAssentosOcupados=aviao.qtdeAssentosOcupados+desejos;
 //posiciona o ponteiro corretamente
 fseek(p_aviao,cont*sizeof(AERONAVE),SEEK_SET);
 //grava dados
 fwrite(&aviao,sizeof(AERONAVE),1,p_aviao);
 break;
     //conta registros
  } cont++;
       }while (fim==1);
       printf("reserva feita com sucesso");
       getch();
       }

     int main(){
            int op=1;
           abre_arquivo();
           do {
           system("cls");
           printf("MENU");
           printf("\n 1 - Cadastrar");
           printf("\n 2 - Listar frota");
           printf("\n 3 - Reservar assento");
           printf("\n 4 - Sair\n");
           scanf("%d",&op);
           switch(op)
           {
           case 1: cadastrar();
                    break;
           case 2: listar();
                   break;
           case 3: reservar();
                   break;
           case 4: printf("\n bye...");
                   break;
           default: printf("Erro");
                    break;
           }
           }while(op!=4);
            fclose(p_aviao);
        return 0;
            }