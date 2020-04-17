#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int main()
{
    FILE *f = fopen("compras.txt", "r");
    if(f==NULL){
        printf("O arquivo nao existe!\n");
        exit(1);
    }

    int i=0, digito=-1;
    float total=0;
    char c, preco[10];

    do{
        c=fgetc(f);
        if(digito==1){//digito=1 indica linhas com precos, digito=-1 indica linhas com nomes
                if(isdigit(c) || c=='.' || c==','){
                if(c==',')
                    c='.';//corrige as virgulas, convertento em ponto
                preco[i]=c;
                i++;
            }
        }
        if(c=='\n' || c==EOF){
            if(digito==1){
                total+=atof(preco);//converte string para float (incluindo ponto e casas decimais)
                memset(preco, '\0', sizeof preco);//limpa o conteudo da string
                i=0;
            }
            digito*=-1;
        }
    }while(c!=EOF);

    printf("Valor total da compra = R$%.2f\n\n", total);
    fclose(f);

    return 0;
    system("PAUSE");
}
