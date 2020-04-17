#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

int main()
{
    int qtd, i, v[20];
    float media = 0;
    FILE *arquivo;

    arquivo = fopen("Felicidade.txt", "w");

    printf("Digite a quantidade de funcionarios: ");
    scanf("%d", &qtd);

    /* srand(time(NULL)) objetiva inicializar o gerador de n�meros aleat�rios
    com o valor da fun��o time(NULL). Este por sua vez, � calculado
    como sendo o total de segundos passados desde 1 de janeiro de 1970
    at� a data atual.
    Desta forma, a cada execu��o o valor da "semente" ser� diferente.
    */
    srand(time(NULL));

    for(i=0;i<qtd;i++){
        v[i] = rand() % 10;
        //printf("%d ", v[i]);
        media += v[i];
        fprintf(arquivo, "Funcionario %d: %d\n", i+1, v[i]);
    }
    media /= qtd;
    fprintf(arquivo, "\nMedia de Felicidade = %.2f", media);

    fclose(arquivo);
    return 0;
}
