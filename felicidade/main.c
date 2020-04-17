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

    /* srand(time(NULL)) objetiva inicializar o gerador de números aleatórios
    com o valor da função time(NULL). Este por sua vez, é calculado
    como sendo o total de segundos passados desde 1 de janeiro de 1970
    até a data atual.
    Desta forma, a cada execução o valor da "semente" será diferente.
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
