#include <stdio.h>
#include <string.h>

typedef struct {
    char nome_aluno[100];
    char exercicio[100];
    int peso;
    int repeticoes;
    int series;
} Treino;

Treino treinos[100];
int totalTreinos = 0;

void cadastrarTreino() {
    if (totalTreinos >= 100) {
        printf("Limite de treinos atingido!\n");
        return;
    }

    printf("Nome do aluno: ");
    scanf(" %99[^\n]", treinos[totalTreinos].nome_aluno);

    printf("Exercicio: ");
    scanf(" %99[^\n]", treinos[totalTreinos].exercicio);

    printf("Peso: ");
    scanf("%d", &treinos[totalTreinos].peso);

    printf("Repeticoes: ");
    scanf("%d", &treinos[totalTreinos].repeticoes);

    printf("Series: ");
    scanf("%d", &treinos[totalTreinos].series);

    totalTreinos++;

    printf("Treino cadastrado com sucesso!\n");
}