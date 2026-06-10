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

void listarTreinos() {
    if (totalTreinos == 0) {
        printf("Nenhum treino cadastrado.\n");
        return;
    }

    printf("\n===== LISTA DE TREINOS =====\n");

    for (int i = 0; i < totalTreinos; i++) {
        printf("\nTreino %d\n", i + 1);
        printf("Aluno: %s\n", treinos[i].nome_aluno);
        printf("Exercicio: %s\n", treinos[i].exercicio);
        printf("Peso: %d\n", treinos[i].peso);
        printf("Repeticoes: %d\n", treinos[i].repeticoes);
        printf("Series: %d\n", treinos[i].series);
    }
}

void menuPersonal() {
    int opcao;

    do {
        printf("\n===== MENU PERSONAL TRAINER =====\n");
        printf("1 - Cadastrar treino\n");
        printf("2 - Listar treinos\n");
        printf("0 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrarTreino();
                break;

            case 2:
                listarTreinos();
                break;

            case 0:
                printf("Saindo...\n");
                break;

            default:
                printf("Opcao invalida!\n");
        }

    } while (opcao != 0);
}