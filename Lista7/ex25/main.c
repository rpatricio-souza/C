#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX 100


/*
entradas:
a
Primeiro Contato
+5512988885555
25/12
a
Contato Dois
988776644
09/12
a
Terc Contato
12999991111
05/01
a
Cont Quatro
977665544
31/01

*/


typedef struct agenda{
    char nome[40];
    char tel[15];
    int diaNasc;
    int mesNasc;
}CONTATO;


int tam=0;
CONTATO con[MAX];


void cadastrar(){
    printf("\Nome: ");
    gets(con[tam].nome);
    fflush(stdin);
    printf("Telefone: ");
    gets(con[tam].tel);
    fflush(stdin);
    printf("Aniversario (dd/mm): ");
    scanf("%d/%d", &con[tam].diaNasc,&con[tam].mesNasc);
    fflush(stdin);

    tam++;
    printf("\nContato adicionado!\n");
    printf("\n---------------------------------------\n\n");
}


void lerDados(){
    FILE *f=fopen("contatos.dat", "rb");

    if(f==NULL){
        printf("\nAinda nao existem dados no programa.\n");
        printf("\n---------------------------------------\n\n");
        return;
    }
    else{
        rewind(f);//posiionar o ponteiro no inicio do arquivo
        while(feof(f)==0){
            fread(&con[tam], sizeof(CONTATO), 1, f);
            tam++;
        }
    }
    tam--;
    fclose(f);
    printf("\n%d Dados lidos com sucesso!\n", tam);
    printf("\n---------------------------------------\n\n");
}


void gravarDados(){
    int i;
    FILE *f=fopen("contatos.dat", "wb");
    fseek(f,0, SEEK_SET);//posicionar o ponteiro no inicio do arquivo
    for(i=0;i<tam;i++)
        fwrite(&con[i], sizeof(CONTATO), 1, f);
    fclose(f);
    printf("\nDados gravados com sucesso!\n---------------------------------------\n\n");
}


void atualizarDados(int pos){
    FILE *f=fopen("despensa.dat", "a+b");
    fseek(f,pos,SEEK_SET);//posiciona o ponteiro no inicio do arquivo e avanca 'pos' posicoes
    fwrite(&con[pos], sizeof(CONTATO), 1, f);
    fclose(f);
}


void mostrarTudo(char letra){
    int i;
    for(i=0;i<tam;i++){
        printf("\nNome:        %d", con[i].nome);
        printf("\nTelefone:    %s", con[i].tel);
        printf("\nAniversario: %d/%d\n", con[i].diaNasc, con[i].mesNasc);
    }
}


int main()
{
    lerDados();

    int id, qtd;
    char escolha=' ';
    do{
        printf("Escolha uma opcao:");
        printf("\na) Inserir contato;");
        printf("\nb) Remover contato;");
        printf("\nc) Pesquisar contato;");
        printf("\nd) Listar todos os contatos;");
        printf("\ne) Listar todos os contatos pela 1a letra do nome;");
        printf("\nf) Listar os aniversariantes do mes;");
        printf("\ns) Sair;");
        printf("\nSua escolha: ");
        scanf("%c", &escolha);
        fflush(stdin);
        escolha=tolower(escolha);

        switch(escolha){
        case 'a':
            printf("\n-----------INSERIR CONTATO-----------\n");
            cadastrar();
            break;
        case 'b':
            printf("\n-----------REMOVER CONTATO-----------\n");
            break;
        case 'c':
            printf("\n----------PESQUISAR CONTATO----------\n");
            mostrarTudo(1);
            break;
        case 'd':
            printf("\n-----------LISTAR CONTATOS-----------\n");
            mostrarTudo(' ');
            break;
        case 'e':
            printf("\n------LISTAR CONTATOS PELA LETRA-----\n");
            mostrarTudo(' ');
            break;
        case 'f':
            printf("\n--------ANIVERSARIANTES DO MES-------\n");
            mostrarTudo(' ');
            break;
        case 's':
            gravarDados();
            printf("\n----------PROGRAMA ENCERRADO-----------\n");
            break;
        default:
            printf("\nOpcao Invalida!\n");
        }
    }while(escolha!='s');

    //memset(nome, '\0', sizeof nome);//limpa a variavel nome
    return 0;
    system("PAUSE");
}
