/**
 * @file personal.c
 * @brief Implementacao das funcoes do modulo personal trainer.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "personal.h"

Treino treinos[100];
int totalTreinos = 0;



void limparTela()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void pausarTela()
{
    printf("\nPressione ENTER para continuar...");
    getchar();
    getchar();
}

/**
 * @brief Cadastra um novo treino no sistema.
 * @details Solicita o CPF do aluno e os dados do treino ao usuario.
 *          Valida CPF, peso, repeticoes e series antes de cadastrar.
 */

void cadastrarTreino() {
    if (totalTreinos >= 100) {
        printf("Limite de treinos atingido!\n");
        return;
    }

    char cpf[12];
    char exercicio[100];
    int peso, repeticoes, series;

    printf("CPF do aluno: ");
    scanf(" %11s", cpf);

    printf("Exercicio: ");
    scanf(" %99[^\n]", exercicio);

    printf("Peso: ");
    scanf("%d", &peso);

    printf("Repeticoes: ");
    scanf("%d", &repeticoes);

    printf("Series: ");
    scanf("%d", &series);

    if (strlen(cpf) == 0) {
        printf("CPF nao pode ser vazio!\n");
        return;
    }

    if (peso <= 0) {
        printf("Peso invalido!\n");
        return;
    }

    if (repeticoes <= 0 || series <= 0) {
        printf("Repeticoes e series devem ser maiores que zero!\n");
        return;
    }

    strcpy(treinos[totalTreinos].cpf_aluno, cpf);
    strcpy(treinos[totalTreinos].exercicio, exercicio);
    treinos[totalTreinos].peso = peso;
    treinos[totalTreinos].repeticoes = repeticoes;
    treinos[totalTreinos].series = series;

    totalTreinos++;

    printf("Treino cadastrado com sucesso!\n");
}

/**
 * @brief Lista todos os treinos cadastrados.
 * @details Exibe CPF do aluno e dados do treino. Caso nenhum tenha sido
 *          cadastrado, exibe mensagem informativa.
 */

void listarTreinos() {
    if (totalTreinos == 0) {
        printf("Nenhum treino cadastrado.\n");
        return;
    }

    printf("\n=================================\n");
    printf("\n===== LISTA DE TREINOS =====\n");
    printf("=================================\n");

    for (int i = 0; i < totalTreinos; i++) {
        printf("\n---------------------------------\n");
        printf("\nTreino %d\n", i + 1);
        printf("CPF do aluno: %s\n", treinos[i].cpf_aluno);
        printf("Exercicio: %s\n", treinos[i].exercicio);
        printf("Peso: %d\n", treinos[i].peso);
        printf("Repeticoes: %d\n", treinos[i].repeticoes);
        printf("Series: %d\n", treinos[i].series);
    }
}

/**
 * @brief Busca um treino pelo CPF do aluno.
 * @param cpf String contendo o CPF do aluno.
 * @return Ponteiro para o primeiro Treino encontrado, ou NULL se nao existir.
 */

Treino* buscarTreinoPorCPF(char cpf[]) {
    for (int i = 0; i < totalTreinos; i++) {
        if (strcmp(treinos[i].cpf_aluno, cpf) == 0)
            return &treinos[i];
    }
    return NULL;
}

/**
 * @brief Exibe e controla o menu do personal trainer.
 * @details Loop continuo ate que o usuario escolha sair (opcao 0).
 */

void menuPersonal() {
    int opcao;

    do {
        printf("\n=== SISTEMA PERSONAL TRAINER ===\n");
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