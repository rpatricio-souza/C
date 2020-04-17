#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX 100

/*
entradas:
f
Rafael Patricio de Souza
rpatricio.souza@gmail.com
Rua Guarani
450
casa
Santana
122211-740
Sao Jose dos Campos
Sao Paulo
Brasil
12
988394295
20/05/1990
Nenhuma obs...

f
Aline Cristine
aline.dlc@gmail.com
Rua do Senai
52
casa
Santana
122211-710
Sao Jose dos Campos
Sao Paulo
Brasil
12
988525252
26/07/1989
S2

f
Gabriel Patricio de Souza
gpatricio.souza@gmail.com
Rua Guarani
450
casa
Santana
122211-740
Sao Jose dos Campos
Sao Paulo
Brasil
12
988999999
10/05/1990
Vagabundo!

s

*/

typedef struct enderecos{
    char rua[30];
    int num;
    char comp[10];
    char bairro[30];
    char cep[10];
    char cidade[30];
    char uf[20];
    char pais[20];
}ENDERECO;

typedef struct telefone{
    int ddd;
    char num[10];
}TELEFONE;

typedef struct data_aniversario{
    int dia;
    int mes;
    int ano;
}NIVER;

typedef struct agenda{
    char nome[30];
    char email[25];
    ENDERECO end;
    TELEFONE tel;
    NIVER dat;
    char obs[50];
}AGENDA;

//variaveis globais
AGENDA *ag[MAX];
int tam=0;
AGENDA *nula={
    "",
    "",
    "",
    0,
    "",
    "",
    "",
    "",
    "",
    "",
    0,
    0,
    0,
    "",
    0,
    ""
};


void imprimeDados(AGENDA *ag){
    printf("\n%s", ag->nome);
    printf("\n%s", ag->email);
    printf("\n%s, %d, %s, %s, %s", ag->end.rua, ag->end.num, ag->end.comp, ag->end.bairro, ag->end.cep);
    printf("\n%s - %s, %s", ag->end.cidade, ag->end.uf, ag->end.pais);
    printf("\n%d %s", ag->tel.ddd, ag->tel.num);
    printf("\n%d/%d/%d", ag->dat.dia, ag->dat.mes, ag->dat.ano);
    printf("\n%s\n\n", ag->obs);
}


void buscaPrimeiroNome(char pnome[30]){
    int i, f=0;
    char *p;
    for(i=0;i<tam;i++){
        //p=strstr(strupr(ag[i]->nome), strupr(pnome));//strupr converte a string para maiusculo
        if(/*p!=NULL*/strcmp(ag[i], pnome)==0){
            imprimeDados(ag[i]);
            f=1;
        }
    }
    if(f==0)
        printf("\nNao foi encontrado nenhum contato...\n\n");
}


void buscaMesNiver(int mes){
    int i, f=0;
    printf("\n\nPessoas que fazem aniversario no mes %d:", mes);
    for(i=0;i<tam;i++){
        if(ag[i]->dat.mes==mes){
            imprimeDados(ag[i]);
            f=1;
        }
    }
    if(f==0)
        printf("\n\nNao foi encontrado nenhum contato...\n\n");
}


void buscaDiaMesNiver(int dia, int mes){
    int i, f=0;
    printf("\n\nPessoas que fazem aniversario na data %d/%d:", dia, mes);
    for(i=0;i<tam;i++){
        if(ag[i]->dat.dia==dia && ag[i]->dat.mes==mes){
            imprimeDados(ag[i]);
            f=1;
        }
    }
    if(f==0)
        printf("\n\nNao foi encontrado nenhum contato...\n\n");
}


void inserePessoa(int i, char nome[30]){
    strcpy(ag[i]->nome, nome);
    printf("E-mail: ");
    gets(ag[i]->email);
    fflush(stdin);
    printf("Endereco\nRua: ");
    gets(ag[i]->end.rua);
    fflush(stdin);
    printf("Numero: ");
    scanf("%d", &ag[i]->end.num);
    fflush(stdin);
    printf("Complemento: ");
    gets(ag[i]->end.comp);
    fflush(stdin);
    printf("Bairro: ");
    gets(ag[i]->end.bairro);
    fflush(stdin);
    printf("CEP: ");
    gets(ag[i]->end.cep);
    fflush(stdin);
    printf("Cidade: ");
    gets(ag[i]->end.cidade);
    fflush(stdin);
    printf("Estado: ");
    gets(ag[i]->end.uf);
    fflush(stdin);
    printf("Pais: ");
    gets(ag[i]->end.pais);
    fflush(stdin);
    printf("DDD: ");
    scanf("%d", &ag[i]->tel.ddd);
    fflush(stdin);
    printf("Telefone: ");
    gets(ag[i]->tel.num);
    fflush(stdin);
    printf("Data de nascimento (dd/mm/aaaa): ");
    scanf("%d/%d/%d", &ag[i]->dat.dia, &ag[i]->dat.mes, &ag[i]->dat.ano);
    fflush(stdin);
    printf("Observacao: ");
    gets(ag[i]->obs);
    fflush(stdin);
}


void substituiContato(AGENDA *ag1, AGENDA *ag2){
    strcpy(ag1->nome, ag2->nome);
    strcpy(ag1->email, ag2->email);
    strcpy(ag1->end.rua, ag2->end.rua);
    ag1->end.num=ag2->end.num;
    strcpy(ag1->end.comp, ag2->end.comp);
    strcpy(ag1->end.bairro, ag2->end.bairro);
    strcpy(ag1->end.cep, ag2->end.cep);
    strcpy(ag1->end.cidade, ag2->end.cidade);
    strcpy(ag1->end.uf, ag2->end.uf);
    strcpy(ag1->end.pais, ag2->end.pais);
    ag1->tel.ddd=ag2->tel.ddd;
    strcpy(ag1->tel.num, ag2->tel.num);
    ag1->dat.dia=ag2->dat.dia;
    ag1->dat.mes=ag2->dat.mes;
    ag1->dat.ano=ag2->dat.ano;
    strcpy(ag1->obs, ag2->obs);
}


void deslocaContatos(int i, int direcao, char nome[30]){
    int j=tam;
    if(direcao==1){
        ag[tam]=malloc(sizeof(AGENDA));
        for(j=tam;j>i;j--)
            substituiContato(ag[j], ag[j-1]);
        inserePessoa(i, nome);
    }
    else{
        if(i==tam-1){
            substituiContato(ag[i], nula);
            tam--;
        }
        else{
            j=i;
            do{
                substituiContato(ag[j], ag[j+1]);
                j++;
            }while(j<tam-1);
            tam--;
            substituiContato(ag[j], nula);
        }
    }
}


int main()
{
    int i, e=0, f=0, aux, dia, mes;
    char escolha='a';
    char nome[30];

    while(escolha!='s'){
        printf("-------------------------AGENDA-------------------------");
        printf("\nc) Buscar Contato por nome;");
        printf("\nd) Buscar Contatos que fazem aniversario num mes;");
        printf("\ne) Buscar Contatos que fazem aniversario numa data;");
        printf("\nf) Inserir Contato;");
        printf("\ng) Remover Contato;");
        printf("\nh) Exibir Agenda;");
        printf("\n\ns) Sair.\n\nEscolha: ");
        scanf("%c", &escolha);
        fflush(stdin);
        escolha=tolower(escolha);

        f=0;
        switch(escolha){
        case 'c':
            printf("\n------------BUSCAR CONTATO POR NOME------------\n");
            printf("\nDigite o nome do contato: ");
            gets(nome);
            buscaPrimeiroNome(nome);
            break;
        case 'd':
            printf("\n-----BUSCAR CONTATO POR MES DE ANIVERSARIO-----\n");
            printf("\nDigite o mes (1-12): ");
            scanf("%d", &mes);
            fflush(stdin);
            buscaMesNiver(mes);
            break;
        case 'e':
            printf("\n----BUSCAR CONTATO POR DATA DE ANIVERSARIO-----\n");
            printf("\nDigite o dia e o mes (dd/mm): ");
            scanf("%d/%d", &dia, &mes);
            fflush(stdin);
            buscaDiaMesNiver(dia, mes);
            break;
        case 'f':
            printf("\n---------------ADICIONAR CONTATO---------------\n");
            printf("\nDigite os dados do contato.\n");
            printf("Nome: ");
            gets(nome);
            fflush(stdin);
            if(tam==0){
                ag[0]=malloc(sizeof(AGENDA));
                inserePessoa(0, nome);
                tam++;
            }
            else{
                aux=tam;
                for(i=0;i<aux;i++){
                    if(strcmp(nome, ag[i]->nome)<0){
                        deslocaContatos(i, 1, nome);
                        tam++;
                        break;
                    }
                    else if(i==aux-1){
                        tam++;
                        ag[i+1]=malloc(sizeof(AGENDA));
                        inserePessoa(i+1, nome);
                        break;
                    }
                }
            }
            break;
        case 'g':
            printf("\n---------------REMOVER CONTATO---------------\n");
            printf("\nDigite o nome do contato a ser removido.\nNome: ");
            gets(nome);
            fflush(stdin);
            for(i=0;i<tam;i++)
                if(strcmp(ag[i]->nome, nome)==0){
                    deslocaContatos(i, 0, nome);
                    f=1;
                    printf("\nContato Removido!\n\n");
                }
            if(f==0)
                printf("\n\nNao foi encontrado nenhum contato...\n\n");
            break;
        case 'h':
            printf("\n---------------EXIBIR CONTATOS---------------\n");
            while(e!=1 && e!=2){
                printf("\nEscolha uma opcao de Exibicao:");
                printf("\n1) Nome Telefone e E-mail;");
                printf("\n2) Todos os dados;");
                printf("\nEscolha: ");
                scanf("%d", &e);
                fflush(stdin);
                switch(e){
                case 1:
                    for(i=0;i<tam;i++){
                        printf("\n%s", ag[i]->nome);
                        printf("\n%d %s", ag[i]->tel.ddd, ag[i]->tel.num);
                        printf("\n%s\n\n", ag[i]->email);
                    }
                    break;
                case 2:
                    for(i=0;i<tam;i++)
                        imprimeDados(ag[i]);
                    break;
                default: printf("\nEscolha Invalida!\n\n");
                }
            }
            e=0;
            break;
        case 's': break;
        default: printf("\nEscolha invalida!\n\n");
        }
    }

    return 0;
    system("PAUSE");
}
