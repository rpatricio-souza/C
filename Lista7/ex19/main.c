#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int main()
{
    FILE *f = fopen("aluno_nota.txt", "r");
    if(f==NULL){
        printf("O arquivo nao existe!\n");
        exit(1);
    }

    int linhas=0;
    float maior=0, nota;
    char nome[30], maiorNome[30];

    while(!feof(f)){
        fscanf(f, "NOME: %s NOTA: %f\n", nome, &nota);
        if(linhas==0 || nota>maior){
            strcpy(maiorNome,nome);
            maior=nota;
        }
        printf("%s %.2f\n", nome, nota);
        linhas++;
    }

    printf("\nMelhor aluno(a):");
    printf("\n%s, nota=%.2f\n", maiorNome, maior);

    fclose(f);

    return 0;
    system("PAUSE");
}
