#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int tamanhoString(char s[]){
    return strlen(s);
}

void compara(char palavra[], char aux[]){
    if(strcmp(palavra, aux)==0)
        printf("\nAs palavras sao iguais!\n");
    else
        printf("\nAs palavras sao diferentes!\n");
}

void concatena(char s1[], char s2[]){
    printf("\n\nString concatenada: %s\n", strcat(s1, s2));
}

void inverte(char s[]){
    printf("\n\nString reversa: %s\n", strrev(s));
}

void contaCaractere(char s[], char c){
    int i, cont=0;
    for(i=0;i<strlen(s);i++)
        if(c==s[i])
            cont++;
    printf("\nO caracter '%c' apareceu %d vezes na string %s\n", c, cont, s);
}

void substituiCaractere(char s[], char c1, char c2){
    int i;
    for(i=0;i<strlen(s);i++)
        if(c1==s[i])
            s[i]=c2;
    printf("\n\nString substituida: %s\n", s);
}

int main()
{
    int verdadeiro=1;
    char escolha, palavra[20], aux[20], c1, c2;

    while(verdadeiro==1){
        printf("\nEscolha uma opcao:");
        printf("\nA- Ler string (max de 20 caracteres);");
        printf("\nB- Length;");
        printf("\nC- Comparar strings;");
        printf("\nD- Concatenar strings;");
        printf("\nE- Inverter string;");
        printf("\nF- Contar caractere;");
        printf("\nG- Substituir caractere;");
        printf("\nS- Sair.");
        printf("\nSua escolha: ");
        escolha=getch();

        if(escolha=='s')
            break;

        switch(escolha){
            case 'a':
                printf("\n\nDigite a palavra: ");
                gets(palavra);
                break;
            case 'b':
                printf("\n\nA string %s tem %d caracteres\n", palavra, tamanhoString(palavra));
                break;
            case 'c':
                printf("\n\nDigite outra string para compararmos: ");
                gets(aux);
                compara(palavra, aux);
                break;
            case 'd':
                printf("\n\nDigite outra string para concatenarmos: ");
                gets(aux);
                concatena(palavra, aux);
                break;
            case 'e':
                inverte(palavra);
                break;
            case 'f':
                printf("\n\nDigite o caractere que quer contar: ");
                c1=getch();
                contaCaractere(palavra, c1);
                break;
            case 'g':
                printf("\n\nDigite os caracteres que quer substituir: ");
                printf("\n1o: ");
                c1=getch();
                printf("\nSera substituido por: ");
                c2=getch();
                substituiCaractere(palavra, c1, c2);
                break;
            default:
                printf("\n\nOpcao invalida!\n");
                break;
        }
    }

    return 0;
    system("pause");
}
