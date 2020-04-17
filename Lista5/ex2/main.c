#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

/*
entradas:
PQEs PQtá R PQma PQlu PQco R , R PQMai PQke R ?
PQÔ R PQLou PQco R , R PQmeu R ! R PQEs PQse R PQfe PQra R PQa PQí R !
*/

//funcao para remover 1 caracter especifico da string
void removeChar(char *s, char c){
    int i, j;
    for(i=j=0;i<strlen(s);i++)
        if(s[i]!=c)
            s[j++]=s[i];
    s[j]='\0';
}

int main()
{
    char frase[100], saida[100], *p;
    int i;
    p=saida;
    gets(frase);
    for(i=0;i<strlen(frase);i++){
        if(frase[i]=='P' && i < strlen(frase)){
            if(frase[i+1]=='Q'){
                i++;
                continue;
            }
        }
        else if(frase[i]=='R' && frase[i+1]==' '){
            if(frase[i+2]=='?' || frase[i+2]=='.' || frase[i+2]==',' || frase[i+2]=='!'){
                 *p=frase[i+2];
                 p++;
                 i+=3;
            }
            else{
                *p=' ';
                p++;
            }

        }
        else if(frase[i]!=' '){
            *p=frase[i];
            p++;
        }
    }

    printf("%s", saida);
    return 0;
    system("PAUSE");
}
