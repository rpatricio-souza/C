#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX 100


/*
entradas:
a
Fulana1
Pai da Fulana1
Mae da Fulana1
Ciclano1
Pai do Fulano1
Mae do Fulano1
04/12/2019
18:45
a
Fulana2
Pai da Fulana2
Mae da Fulana2
Pessoa2
Pai do Pessoa2
Mae do Pessoa2
04/12/2019
20:25
b
04/12/2019
B
05/12/2019
A
Noiva 3
Pai da Noiva 3
Mae da Noiva 3
Noivo 3
Pai do Noivo 3
Mae da Noiva 3
20/12/2019
12:00

*/


typedef struct conjugue{
    char nome[50];
    char pai[50];
    char mae[50];
}NOIV;


typedef struct casamento{
    NOIV noiva;
    NOIV noivo;
    int dia;
    int mes;
    int ano;
    char hora[6];
}IGREJA;


int tam=0;
IGREJA ig[MAX];


void cadastrar(){
    printf("Dados da Noiva:");
    printf("\nNome: ");
    gets(ig[tam].noiva.nome);
    fflush(stdin);
    printf("Nome do Pai: ");
    gets(ig[tam].noiva.pai);
    fflush(stdin);
    printf("Nome da Mae: ");
    gets(ig[tam].noiva.mae);
    fflush(stdin);
    printf("\nDados do Noivo:");
    printf("\nNome: ");
    gets(ig[tam].noivo.nome);
    fflush(stdin);
    printf("Nome do Pai: ");
    gets(ig[tam].noivo.pai);
    fflush(stdin);
    printf("Nome da Mae: ");
    gets(ig[tam].noivo.mae);
    fflush(stdin);
    printf("\nData (dd/mm/aaaa): ");
    scanf("%d/%d/%d", &ig[tam].dia,&ig[tam].mes,&ig[tam].ano);
    fflush(stdin);
    printf("Hora (hh:mm): ");
    gets(ig[tam].hora);
    fflush(stdin);
    tam++;
    printf("\nExistem %d dados\n", tam);
    system("PAUSE");
}


void listarCerimonias(int dia, int mes, int ano){
    int i, achou=0;
    for(i=0;i<tam;i++){
        if(dia==ig[i].dia)
            if(mes==ig[i].mes)
                if(ano==ig[i].ano){
                    if(achou==0){
                        printf("No dia %d/%d/%d ocorreram as cerimonias:", dia, mes, ano);
                        achou++;
                    }
                    printf("\n%s e %s", ig[i].noiva.nome,ig[i].noivo.nome);
                }
    }
    if(achou==0)
        printf("\nNao foram encontradas cerimonias na data especificada!\n");
    printf("\n");
    system("PAUSE");
}


void exibeDataHora(char nomeNoiva[50], char nomeNoivo[50]){
    int i, achou=0;
    if(strcmp(nomeNoivo,"")==0){
        for(i=0;i<tam;i++){
            if(strcmp(nomeNoiva,ig[i].noiva.nome)==0){
                achou++;
                printf("\nCerimonia de %s e %s", ig[i].noiva.nome, ig[i].noivo.nome);
                printf("\nData: %d/%d/%d\nHora: %s\n", ig[i].dia,ig[i].mes,ig[i].ano,ig[i].hora);
            }
        }
    }
    else{
        for(i=0;i<tam;i++){
            if(strcmp(nomeNoivo,ig[i].noivo.nome)==0){
                achou++;
                printf("\nCerimonia de %s e %s", ig[i].noiva.nome, ig[i].noivo.nome);
                printf("\nData: %d/%d/%d\nHora: %s\n", ig[i].dia,ig[i].mes,ig[i].ano,ig[i].hora);
            }
        }
    }
    if(!achou)
        printf("\nNao foram encontradas cerimonias para essa pessoa!\n");
    printf("\n");
    system("PAUSE");
}


void gravarDados(){
    FILE *f=fopen("casamentos.dat", "a+b");
    fseek(f,0, SEEK_END);//posicionar o ponteiro no final do arquivo

    int i;
    for(i=0;i<tam;i++)
        fwrite(&ig[i], sizeof(IGREJA), 1, f);
    fclose(f);
    printf("\nDados gravados com sucesso!\n");
    system("PAUSE");
}


void lerDados(){
    FILE *f=fopen("casamentos.dat", "rb");

    int i=tam;
    printf("tam antes do read = %d\n", tam);
    if(f==NULL){
        printf("\nO arquivo nao existe\n");
        system("PAUSE");
        return;
    }
    else{
        rewind(f);//posiionar o ponteiro no inicio do arquivo
        while(feof(f)==0){
            fread(&ig[i], sizeof(IGREJA), 1, f);
            i++;
            tam++;
        }
        tam--;
        printf("tam depois do read = %d\n", tam);
    }
    fclose(f);
    printf("\n%d Dados lidos com sucesso!\n", tam);
    system("PAUSE");
}


void mostrarTudo(){
    int i;
    for(i=0;i<tam;i++){
        printf("Dados da Noiva:");
        printf("\nNome: %s", ig[i].noiva.nome);
        printf("\nNome do Pai: %s", ig[i].noiva.pai);
        printf("\nNome da Mae: %s", ig[i].noiva.mae);
        printf("\nDados do Noivo:");
        printf("\nNome: %s", ig[i].noivo.nome);
        printf("\nNome do Pai: %s", ig[i].noivo.pai);
        printf("\nNome da Mae: %s", ig[i].noivo.mae);
        printf("\nData: %d/%d/%d", ig[i].dia,ig[i].mes,ig[i].ano);
        printf("\nHora: %sh\n\n", ig[i].hora);
    }
    system("PAUSE");
}


int main()
{
    int dd, mm , aa;
    char escolha=' ', noivos=' ', dados=' ', nome[50];
    do{
        system("cls");
        printf("Escolha uma opcao:");
        printf("\na) Cadastrar noivos;");
        printf("\nb) Listar cerimonias por data;");
        printf("\nc) Exibir Data/Hora da cerimonia;");
        printf("\nd) Ler/Escrever os dados em arquivo;");
        printf("\ns) Sair;");
        printf("\nSua escolha: ");
        scanf("%c", &escolha);
        fflush(stdin);
        escolha=tolower(escolha);

        switch(escolha){
        case 'a':
            printf("\n-----------CADASTRAR NOIVOS-----------\n");
            cadastrar();
            break;
        case 'b':
            printf("\n-----------LISTAR CERIMONIAS----------\n");
            printf("Digite uma data (dd/mm/aaaa): ");
            scanf("%d/%d/%d", &dd,&mm,&aa);
            fflush(stdin);
            listarCerimonias(dd,mm,aa);
            break;
        case 'c':
            printf("\n------------EXIBIR HORARIOS-----------\n");
            do{
                printf("\n1)Procurar pelo nome da Noiva;");
                printf("\n2)Procurar pelo nome do Noivo;");
                printf("\nEscolha: ");
                scanf("%c", &noivos);
                fflush(stdin);

                noivos=tolower(noivos);
                if(noivos=='1'){
                    printf("\nDigite o nome da Noiva: ");
                    gets(nome);
                    fflush(stdin);
                    exibeDataHora(nome,"");
                }
                else if(noivos=='2'){
                    printf("\nDigite o nome do Noivo: ");
                    gets(nome);
                    fflush(stdin);
                    exibeDataHora("",nome);
                }
                else
                    printf("\nEscolha Invalida!\n");
            }while(noivos!='1' && noivos!='2');
            memset(nome, '\0', sizeof nome);//limpa a variavel nome
            break;
        case 'd':
            printf("\n----------------ARQUIVO---------------\n");
            do{
                printf("\n1) Ler Arquivo de dados;");
                printf("\n2) Gravar dados no arquivo;");
                printf("\nEscolha: ");
                scanf("%c", &dados);
                fflush(stdin);

                dados=tolower(dados);
                if(dados=='1')
                    lerDados();
                else if(dados=='2')
                    gravarDados();
                else
                    printf("\nEscolha Invalida!\n");
            }while(dados!='1' && dados!='2');
            break;
        case 'e':
            mostrarTudo();
            break;
        case 's':
            printf("\n----------PROGRAMA ENCERRADO----------\n");
            break;
        default:
            printf("\nOpcao Invalida!\n");
            system("PAUSE");
        }
    }while(escolha!='s');

    return 0;
    system("PAUSE");
}
