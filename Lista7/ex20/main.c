#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


int main()
{
    FILE *f=fopen("alunos_notas.txt","w");

    int tam, i, j;
    char **nomes, nome[41], num[3];
    float *notas;
    srand(time(0));

    printf("Digite a quantidade de alunos na disciplina: ");
    scanf("%d", &tam);

    nomes=malloc(tam*sizeof(char));
    notas=malloc(tam*sizeof(float));

    for(i=0;i<tam;i++){
        nomes[i]=malloc(40*sizeof(char));
        strcpy(nome,"Aluno ");
        itoa(i+1,num,10);
        strcat(nome,num);
        /*for(j=strlen(nome);j<40;j++)
            strcat(nome," ");
        strcat(nome,"\0");*/
        strcpy(nomes[i], nome);
        notas[i]=(float)(rand()%10);
        fprintf(f,"%s %.2f\n", nomes[i], notas[i]);
        //limpar as variaceis
        memset(nome, '\0', sizeof nome);
        memset(num, '\0', sizeof nome);
    }

    free(nomes);
    free(notas);
    fclose(f);

    return 0;
    system("PAUSE");
}
